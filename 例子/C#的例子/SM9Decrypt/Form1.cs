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

namespace SM9Decrypt
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Close();
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
                cipherTextBox.Text = f.FileName;
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

        private void okButton_Click(object sender, EventArgs e)
        {
            if (userKeyTextBox.Text == "")
            {
                MessageBox.Show("没有输入用户密钥文件名！");
                return;
            }

            if (cipherTextBox.Text == "")
            {
                MessageBox.Show("没有输入密文文件名！");
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
            catch (PkiException)
            {
                MessageBox.Show("用户密钥文件格式出错！");
                return;
            }

            using (sm9)
            {
                byte[] cipher = File.ReadAllBytes(cipherTextBox.Text);   
                int macKeyLen = 32;
                byte[] clear = sm9.Decrypt(cipher, macKeyLen);
                Save(clearTextBox.Text,clear);
            }
            MessageBox.Show("解密成功");
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
