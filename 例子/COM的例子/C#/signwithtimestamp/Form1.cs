using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace signwithtimestamp
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
            NetcaPkiLib.SignedData sign1Obj = new NetcaPkiLib.SignedData();
            NetcaPkiLib.SignedData sign2Obj = new NetcaPkiLib.SignedData();
            NetcaPkiLib.Utilities util = new NetcaPkiLib.Utilities();

            byte[] tbs = (byte[])util.Encode("123", NetcaPkiLib.Constants.NETCAPKI_CP_UTF8);
            cert.Select("Signature", "");
            if (sign1Obj.SetSignCertificate(cert, "", false) == false)
            {
                MessageBox.Show("设置签名证书失败");
                return;
            }

            sign1Obj.SetSignAlgorithm(-1, NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_SHA1WITHRSA);
            sign1Obj.Detached = false;
            byte[] signature = (byte[])sign1Obj.SignWithTSATimeStamp("https://classatsa.cnca.net/tsa.asp", tbs, NetcaPkiLib.Constants.NETCAPKI_CMS_ENCODE_DER);
            MessageBox.Show("签名成功");
            
            sign1Obj = null;
            byte[] tbs2=(byte[])sign2Obj.Verify(signature, false);
            if (EqualsByteArray(tbs, tbs2))
            {
                MessageBox.Show("验证签名成功");
                MessageBox.Show(sign2Obj.GetTSATimeStamp(1).ToString());
            }
            else
            {
                MessageBox.Show("验证签名失败");
            }
            
        }

        private bool EqualsByteArray(byte[] data1,byte[] data2)
        {
            if (data1.Length != data2.Length)
            {
                return false;
            }
            for (int i = 0; i < data1.Length; i++)
            {
                if (data1[i] != data2[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
}