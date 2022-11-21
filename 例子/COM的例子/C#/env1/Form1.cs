using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace env1
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
            NetcaPkiLib.EnvelopedData env = new NetcaPkiLib.EnvelopedData();
            NetcaPkiLib.Utilities util = new NetcaPkiLib.Utilities();

            cert.Decode(textBox1.Text);
            env.EncryptAlgorithm = NetcaPkiLib.Constants.NETCAPKI_ENVELOPEDDATA_ALGORITHM_AES256CBC;
            if (env.AddCert(cert, false) == false)
            {
                MessageBox.Show("添加加密证书失败");
                return;
            }

            byte[] clear = (byte[])util.Encode("123", NetcaPkiLib.Constants.NETCAPKI_CP_UTF8);
            byte[] cipher = (byte[])env.Encrypt(clear, NetcaPkiLib.Constants.NETCAPKI_CMS_ENCODE_DER);
            MessageBox.Show("加密成功");
        }
    }
}