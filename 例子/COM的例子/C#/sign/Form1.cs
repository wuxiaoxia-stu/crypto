using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace sign
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NetcaPkiLib.Certificate cert = new NetcaPkiLib.Certificate();
            NetcaPkiLib.Utilities util=new NetcaPkiLib.Utilities();

            byte[] data = (byte[])util.Encode("你好,NETCA", NetcaPkiLib.Constants.NETCAPKI_CP_UTF8);
            cert.Decode(textBox1.Text);

            byte[] sign=(byte[])cert.Sign(NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_SHA1WITHRSA,data);
            MessageBox.Show("签名成功");

            if (cert.Verify(NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_SHA1WITHRSA, data, sign))
            {
                MessageBox.Show("验证签名成功");
            }
            else
            {
                MessageBox.Show("验证签名失败");
            }

        }
    }
}