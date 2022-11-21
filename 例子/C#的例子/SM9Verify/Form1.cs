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

namespace SM9Verify
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
                tbsTextBox.Text = f.FileName;
            }
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            OpenFileDialog f = new OpenFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                signTextBox.Text = f.FileName;
            }
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

            if (tbsTextBox.Text == "")
            {
                MessageBox.Show("没有输入要签名的文件的文件名！");
                return;
            }

            if (signTextBox.Text == "")
            {
                MessageBox.Show("没有输入签名值文件的文件名！");
                return;
            }

            UTF8Encoding encoding = new UTF8Encoding();
            byte[] id = encoding.GetBytes(idTextBox.Text);
            SM9MasterKey masterKey;

            try
            {
                masterKey = SM9MasterKey.ImportPublicKey(File.ReadAllBytes(masterKeyTextBox.Text));
            }
            catch (PkiException)
            {
                MessageBox.Show("主公钥文件格式错误！");
                return;
            }
            using (masterKey)
            {
                using (Hash hashObj = SM9MasterKey.CreateHashObjectForVerify())
                {
                    using (FileStream stream = new FileStream(tbsTextBox.Text, FileMode.Open))
                    {
                        byte[] data = new byte[8192];
                        int len;
                        for (; ; )
                        {
                            len = stream.Read(data, 0, data.Length);
                            if (len == 0)
                            {
                                break;
                            }
                            hashObj.Update(data, 0, len);
                        }
                    }
                    byte[] signature = File.ReadAllBytes(signTextBox.Text);
                    if (masterKey.Verify(id, hashObj, signature))
                    {
                        MessageBox.Show("验证签名成功！");
                    }
                    else
                    {
                        MessageBox.Show("验证签名失败！");
                    }
                }
            }

        }
    }
}
