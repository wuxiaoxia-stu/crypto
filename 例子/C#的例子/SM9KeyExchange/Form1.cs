using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Netca.Pki;
using System.IO;

namespace SM9KeyExchange
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
                senderUserKeyTextBox.Text = f.FileName;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog f = new OpenFileDialog();
            if (f.ShowDialog() == DialogResult.OK)
            {
                receiverUserKeyTextBox.Text = f.FileName;
            }
        }

        private void keyExchangeButton_Click(object sender, EventArgs e)
        {
            if (senderUserKeyTextBox.Text == "")
            {
                MessageBox.Show("没有输入发起方的用户密钥文件名!");
                return; 
            }

            if (receiverUserKeyTextBox.Text == "")
            {
                MessageBox.Show("没有输入响应方的用户密钥文件名!");
                return;
            }
            if (keyLenTextBox.Text == "")
            {
                MessageBox.Show("没有输入密钥长度!");
                return;
            }

            int keyLen;
            if (int.TryParse(keyLenTextBox.Text, out keyLen) == false)
            {
                MessageBox.Show("密钥长度不是整数!");
                return;
            }
            if (keyLen <= 0)
            {
                MessageBox.Show("密钥长度不是正数!");
                return;
            }

            bool keyConfirm = keyConfirmCheckBox.Checked;

            SM9UserKey senderUserKey;
            SM9UserKey receiverUserKey;

            try
            {
                senderUserKey = SM9UserKey.Import(File.ReadAllBytes(senderUserKeyTextBox.Text));
            }
            catch (PkiException)
            {
                MessageBox.Show("发起方的用户密钥文件格式错误!");
                return;
            }

            try
            {
                receiverUserKey = SM9UserKey.Import(File.ReadAllBytes(receiverUserKeyTextBox.Text));
            }
            catch (PkiException)
            {
                senderUserKey.Dispose();
                MessageBox.Show("响应方的用户密钥文件格式错误!");
                return;
            }
            displayTextBox.Text = "";

            using (senderUserKey)
            {
                using (receiverUserKey)
                {
                    SM9Keyexchange senderKeyexchange = new SM9Keyexchange(true, senderUserKey);
                    SM9Keyexchange receiverKeyexchange = new SM9Keyexchange(false, receiverUserKey);

                    byte[] Ra=senderKeyexchange.SenderPrepare(receiverUserKey.Id);
                    displayTextBox.AppendText("发起方：\n");
                    string str;
                    str = "Ra:" + HexEncode(Ra) + "\n";
                    displayTextBox.AppendText(str);

                    byte[] SKb=receiverKeyexchange.ReceiverKeyexchange(keyConfirm, senderUserKey.Id, Ra, keyLen);
                    displayTextBox.AppendText("\n响应方：\n");
                    byte[] Rb = receiverKeyexchange.GetRb();
                    str = "Rb:" + HexEncode(Rb) + "\n";
                    displayTextBox.AppendText(str);
                    str = "SKb:" + HexEncode(SKb) + "\n";
                    displayTextBox.AppendText(str);
                    byte[] SKa;
                    if (keyConfirm)
                    {
                        byte[] Sb = receiverKeyexchange.GetSb();
                        str = "Sb:" + HexEncode(Sb) + "\n";
                        SKa = senderKeyexchange.SenderKeyexchange(Rb, Sb, keyLen);
                    }
                    else
                    {
                        SKa = senderKeyexchange.SenderKeyexchange(Rb, keyLen);
                    }
                    displayTextBox.AppendText("\n发起方：\n");
                    str = "SKa:" + HexEncode(SKa) + "\n";
                    displayTextBox.AppendText(str);
                    if (ByteArrayEquals(SKa, SKb) == false)
                    {
                        str = "密钥交换结果得到的密钥不同\n";
                    }
                    else
                    {
                        str = "密钥交换结果得到的密钥相同\n";
                    }
                    displayTextBox.AppendText(str);
                    if (keyConfirm)
                    {
                        byte[] Sa = senderKeyexchange.GetSa();
                        str = "Sa:" + HexEncode(Sa) + "\n";
                        displayTextBox.AppendText(str);
                        displayTextBox.AppendText("\n响应方：\n");
                        byte[] S2 = receiverKeyexchange.GetSa();
                        str = "S2:" + HexEncode(S2) + "\n";
                        displayTextBox.AppendText(str);
                        if (ByteArrayEquals(SKa, SKb) == false)
                        {
                            str = "密钥确认失败\n";
                        }
                        else
                        {
                            str = "密钥确认成功\n";
                        }
                        displayTextBox.AppendText(str);
                    }
                }
            }

        }

        private string HexEncode(byte[] data)
        {
            return BitConverter.ToString(data).Replace("-", "");
        }

        private bool ByteArrayEquals(byte[] array1, byte[] array2)
        {
            if (array1.Length != array2.Length)
            {
                return false;
            }
            for (int i = 0; i < array1.Length; i++)
            {
                if (array1[i] != array2[i])
                {
                    return false;
                }
            }
            return true;
        }

    }
}
