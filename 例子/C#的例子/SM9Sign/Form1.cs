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

namespace SM9Sign
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void userKeyButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog f = new OpenFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                userKeyTextBox.Text = f.FileName;
            }
        }

        private void tbsButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog f = new OpenFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                tbsTextBox.Text = f.FileName;
            }
        }

        private void signButton_Click(object sender, EventArgs e)
        {
            SaveFileDialog f = new SaveFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                signTextBox.Text = f.FileName;
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

            SM9UserKey sm9;

            try
            {
                sm9 = SM9UserKey.Import(File.ReadAllBytes(userKeyTextBox.Text));
            }
            catch (PkiException)
            {
                MessageBox.Show("用户密钥文件格式错误！");
                return;
            }
            using (sm9)
            {
                using (Hash hashObj = SM9UserKey.CreateHashObjectForSign())
                {
                    using (FileStream stream = new FileStream(tbsTextBox.Text,FileMode.Open))
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
                    byte[] signature=sm9.Sign(hashObj);
                    Save(signTextBox.Text,signature);
                }
            }

            MessageBox.Show("签名成功");
        }

        private void Save(string fileName, byte[] data)
        {
            using (FileStream f = new FileStream(fileName, FileMode.Create))
            {
                f.Write(data, 0, data.Length);
            }
        }
    }
}
