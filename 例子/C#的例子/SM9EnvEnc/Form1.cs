using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using Netca.Pki;

namespace SM9EnvEnc
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog f = new OpenFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                masterKeyTextBox.Text = f.FileName;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog f = new OpenFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                clearTextBox.Text = f.FileName;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SaveFileDialog f = new SaveFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                envTextBox.Text = f.FileName;
            }
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            if (masterKeyTextBox.Text == "")
            {
                MessageBox.Show("没有输入主公钥文件名！");
                return;
            }

            if (idTextBox.Text == "")
            {
                MessageBox.Show("没有输入用户标识！");
                return;
            }

            if (clearTextBox.Text == "")
            {
                MessageBox.Show("没有输入明文文件名！");
                return;
            }

            if (envTextBox.Text == "")
            {
                MessageBox.Show("没有输入数字信封文件名！");
                return;
            }
            UTF8Encoding encoding=new UTF8Encoding();
            byte[] id = encoding.GetBytes(idTextBox.Text);

            SM9MasterKey sm9;
            try
            {
                sm9 = SM9MasterKey.ImportPublicKey(File.ReadAllBytes(masterKeyTextBox.Text));
            }
            catch (PkiException)
            {
                MessageBox.Show("主公钥文件格式错误！");
                return;
            }

            byte[] encKey;
            byte[] key;
            using (sm9)
            {
                key = sm9.GenerateSessionKey(id, 16, out encKey);
            }
            using (FileStream outStream = new FileStream(envTextBox.Text,FileMode.Create))
            {
                outStream.Write(encKey, 0, encKey.Length);
                byte[] iv = Util.GenerateRandom(16);
                outStream.Write(iv, 0, iv.Length);
                using (Cipher c = new Cipher(true, Algorithm.EncryptAlgorithmSm4Cbc))
                {
                    c.Key=key;
                    c.IV = iv;
                    c.Padding = Cipher.PaddingPKCS7;
                    c.Init();
                    using (FileStream inStream = new FileStream(clearTextBox.Text, FileMode.Open))
                    {
                        int len;
                        byte[] clear = new byte[8192];
                        byte[] cipher;
                        for (; ; )
                        {
                            len = inStream.Read(clear, 0, clear.Length);
                            if (len == 0)
                            {
                                break;
                            }
                            cipher=c.Update(clear, 0, len);
                            if (cipher.Length > 0)
                            {
                                outStream.Write(cipher, 0, cipher.Length);
                            }
                        }
                        cipher = c.Final();
                        if (cipher.Length > 0)
                        {
                            outStream.Write(cipher, 0, cipher.Length);
                        }
                                                
                    }
                }

            }
            MessageBox.Show("加密成功！");
        }


    }
}
