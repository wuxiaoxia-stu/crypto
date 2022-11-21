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

namespace SM9Encrypt
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
            SaveFileDialog f = new SaveFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                cipherTextBox.Text = f.FileName;
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
                MessageBox.Show("没有输入明文！");
                return;
            }

            if (cipherTextBox.Text == "")
            {
                MessageBox.Show("没有输入密文文件名！");
                return;
            }

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

            UTF8Encoding encoding = new UTF8Encoding();
            byte[] id = encoding.GetBytes(idTextBox.Text);
            byte[] clear = encoding.GetBytes(clearTextBox.Text);
            using (sm9)
            {
                int macKeyLen = 32;
                byte[] cipher = sm9.Encrypt(id, clear, macKeyLen);
                Save(cipherTextBox.Text, cipher);
            }
            MessageBox.Show("加密成功");
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
