using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace signeddata2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NetcaPkiLib.SignedData signObj = new NetcaPkiLib.SignedData();
            NetcaPkiLib.Certificate cert = new NetcaPkiLib.Certificate();

            byte[] tbs = (byte[])signObj.Verify(textBox1.Text, true);
            
            cert.Decode(textBox2.Text);
            if (signObj.SetSignCertificate(cert, textBox3.Text, false) == false)
            {
                MessageBox.Show("设置签名证书失败");
                return;
            }
            signObj.SetSignAlgorithm(-1, NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_SHA1WITHRSA);

            byte[] signature = (byte[])signObj.CoSign(NetcaPkiLib.Constants.NETCAPKI_CMS_ENCODE_DER);

            MessageBox.Show("签名成功");

        }
    }
}