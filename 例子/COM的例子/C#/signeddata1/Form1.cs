using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace signeddata1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NetcaPkiLib.SignedData sign1Obj = new NetcaPkiLib.SignedData();
            NetcaPkiLib.SignedData sign2Obj = new NetcaPkiLib.SignedData();
            NetcaPkiLib.Certificate cert = new NetcaPkiLib.Certificate();
            NetcaPkiLib.Utilities util = new NetcaPkiLib.Utilities();

            byte[] tbs = (byte[])util.Encode("123", NetcaPkiLib.Constants.NETCAPKI_CP_UTF8);
            cert.Decode(textBox1.Text);
            if (sign1Obj.SetSignCertificate(cert, "", false) == false)
            {
                MessageBox.Show("����ǩ��֤��ʧ��");
                return;
            }

            sign1Obj.SetSignAlgorithm(-1, NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_SHA1WITHRSA);
            sign1Obj.Detached = true;

            byte[] signature = (byte[])sign1Obj.Sign(tbs, NetcaPkiLib.Constants.NETCAPKI_CMS_ENCODE_DER);
            MessageBox.Show("ǩ���ɹ�");

            if (sign2Obj.DetachedVerify(tbs, signature, false))
            {
                MessageBox.Show("��֤ǩ���ɹ�");
            }
            else
            {
                MessageBox.Show("��֤ǩ��ʧ��");
            }
        }
    }
}