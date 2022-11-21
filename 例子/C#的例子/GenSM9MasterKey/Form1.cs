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

namespace GenSM9MasterKey
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            typeComboBox.SelectedIndex=1;
            
        }

        private void exitbutton_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void okbutton_Click(object sender, EventArgs e)
        {
            int index=typeComboBox.SelectedIndex;
            int type;
            if (index == 0)
            {
                type = KeyPair.KeyPairTypeEncrypt;
            }
            else if (index == 1)
            {
                type = KeyPair.KeyPairTypeSignature;
            }
            else if (index == 2)
            {
                type = KeyPair.KeyPairTypeKeyAgreement;
            }
            else
            {
                MessageBox.Show("没有选择密钥类型!");
                return;
            }
            if (hidTextBox.Text == "")
            {
                MessageBox.Show("没有输入hid!");
                return;
            }

            int hid;
            if (int.TryParse(hidTextBox.Text, out hid) == false)
            {
                MessageBox.Show("hid不是整数!");
                return;
            }

            if (keypairFileNameTextBox.Text == "")
            {
                MessageBox.Show("没有输入主密钥对文件名!");
                return;
            }

            if (publickeyFileNameTextBox.Text == "")
            {
                MessageBox.Show("没有输入主公钥文件名!");
                return;
            }

            SM9MasterKey sm9 = SM9MasterKey.GenerateKeyPair(type, hid);
            if (sm9 == null)
            {
                MessageBox.Show("产生SM9主密钥失败!");
                return;
            }
            using (sm9)
            {
                Save(keypairFileNameTextBox.Text, sm9.ExportKeyPair());
                Save(publickeyFileNameTextBox.Text, sm9.ExportPublicKey());
            }
            MessageBox.Show("产生SM9主密钥成功!");
            
        }

        private void Save(string fileName,byte[] data)
        {
            using (FileStream f = new FileStream(fileName, FileMode.Create))
            {
                f.Write(data,0,data.Length);
            }
        }

        private void keypairbutton_Click(object sender, EventArgs e)
        {
            SaveFileDialog f = new SaveFileDialog();
            if(f.ShowDialog()==DialogResult.OK)
            {
                keypairFileNameTextBox.Text = f.FileName;
            }
        }

        private void publickeybutton_Click(object sender, EventArgs e)
        {
            SaveFileDialog f = new SaveFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                publickeyFileNameTextBox.Text = f.FileName;
            }
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            hidTextBox.Focus();
        }
    }
}
