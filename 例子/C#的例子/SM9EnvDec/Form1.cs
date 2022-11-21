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

namespace SM9EnvDec
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
                userKeyTextBox.Text = f.FileName;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog f = new OpenFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                envTextBox.Text = f.FileName;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SaveFileDialog f = new SaveFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                clearTextBox.Text = f.FileName;
            }
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            if (userKeyTextBox.Text == "")
            {
                MessageBox.Show("没有输入用户密钥文件名！");
                return;
            }

            if (envTextBox.Text == "")
            {
                MessageBox.Show("没有输入数字信封文件名！");
                return;
            }

            if (clearTextBox.Text == "")
            {
                MessageBox.Show("没有输入明文文件名！");
                return;
            }

            SM9UserKey sm9;
            try
            {
                sm9 = SM9UserKey.Import(File.ReadAllBytes(userKeyTextBox.Text));
            }
            catch(PkiException)
            {
                MessageBox.Show("用户密钥文件格式错误！");
                return;
            }
            using (sm9)
            {
                using (FileStream inStream = new FileStream(envTextBox.Text, FileMode.Open))
                {
                    byte[] encKey = ReadNBytes(inStream, 65);
                    byte[] key = sm9.DecryptSessionKey(16, encKey);
                    byte[] iv = ReadNBytes(inStream, 16);
                    using (Cipher c = new Cipher(false, Algorithm.EncryptAlgorithmSm4Cbc))
                    {
                        c.Key = key;
                        c.IV = iv;
                        c.Padding = Cipher.PaddingPKCS7;
                        c.Init();
                        using (FileStream outStream = new FileStream(clearTextBox.Text, FileMode.Create))
                        {
                            byte[] data = new byte[8192];
                            int len;
                            byte[] clear;
                            for (; ; )
                            {
                                len = inStream.Read(data, 0, data.Length);
                                if (len == 0)
                                {
                                    break;
                                }
                                clear = c.Update(data, 0, len);
                                if (clear.Length > 0)
                                {
                                    outStream.Write(clear, 0, clear.Length);
                                }
                            }
                            clear=c.Final();
                            if (clear.Length > 0)
                            {
                                outStream.Write(clear, 0, clear.Length);
                            }
                        }
                    }
                }
            }
            MessageBox.Show("解密成功！");
        }

        private byte[] ReadNBytes(FileStream inStream,int bytes)
        {
            byte[] data = new byte[bytes];
            int pos=0;
            int len;
            int remLen = bytes - pos;
            while (remLen>0)
            {
                len = inStream.Read(data, pos, remLen);
                if (len == remLen)
                {
                    return data;
                }
                else if (len == 0)
                {
                    throw new IOException("没有更多的数据可读");
                }
                else
                {
                    pos += len;
                    remLen -= len;
                }

            }
            throw new IOException("不应该能到达这里");
        }

    }
}
