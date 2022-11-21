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

namespace GenSM9UserKey
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

        private void okButton_Click(object sender, EventArgs e)
        {
            if (masteKeyTextBox.Text == "")
            {
                MessageBox.Show("没有输入主密钥文件名！");
                return;
            }
            if (idTextBox.Text == "")
            {
                MessageBox.Show("没有输入用户标识！");
                return;
            }
            if (userKeyTextBox.Text == "")
            {
                MessageBox.Show("没有输入用户密钥文件名！");
                return;
            }

            SM9MasterKey masterKey;
            try
            {
                masterKey = SM9MasterKey.ImportKeyPair(File.ReadAllBytes(masteKeyTextBox.Text));
            }
            catch(PkiException)
            {
                MessageBox.Show("主密钥文件格式错误！");
                return;
            }
            using (masterKey)
            {
                UTF8Encoding encoding = new UTF8Encoding();
                try
                {
                    using (SM9UserKey userKey = masterKey.GenerateUserKey(encoding.GetBytes(idTextBox.Text)))
                    {
                        Save(userKeyTextBox.Text, userKey.Export());
                    }
                }
                catch (PkiException ex)
                {
                    if (ex.ErrorCode == -142)
                    {
                        MessageBox.Show("不能为该用户标识产生用户密钥！");
                        return;
                    }
                    MessageBox.Show("产生用户密钥失败！");
                    return;
                }
                
            }
            MessageBox.Show("产生用户密钥成功！");
        }
        private void Save(string fileName, byte[] data)
        {
            using (FileStream f = new FileStream(fileName, FileMode.Create))
            {
                f.Write(data, 0, data.Length);
            }
        }
        

        private void masteKeyFileNameButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog f = new OpenFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                masteKeyTextBox.Text = f.FileName;
            }
        }

        private void userKeyFileNameButton_Click(object sender, EventArgs e)
        {
            SaveFileDialog f = new SaveFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                userKeyTextBox.Text = f.FileName;
            }
        }
    }
}
