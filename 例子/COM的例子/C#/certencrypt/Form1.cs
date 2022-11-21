using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace certencrypt
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
            NetcaPkiLib.Utilities util = new NetcaPkiLib.Utilities();

            byte[] data = (byte[])util.Encode("ÄãºÃ,NETCA", NetcaPkiLib.Constants.NETCAPKI_CP_UTF8);
            
            cert.Decode(textBox1.Text);

            byte[] cipher = (byte[])cert.Encrypt(NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_RSA_PKCS1_V1_5_ENC, data);
            MessageBox.Show(util.BinaryToHex(cipher,true));


        }
    }
}