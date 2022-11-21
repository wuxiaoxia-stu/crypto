using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace verifycert
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NetcaPkiLib.CertVerify certVerifyObj = new NetcaPkiLib.CertVerify();
            certVerifyObj.Option = 0;

            NetcaPkiLib.Certificate certObj=new NetcaPkiLib.Certificate();
            certObj.Decode(rootca.Text);
            certVerifyObj.AddRootCert(certObj);

            if (ca1.Text.Length > 0)
            {
                certObj = new NetcaPkiLib.Certificate();
                certObj.Decode(ca1.Text);
                certVerifyObj.AddCACert(certObj);
            }

            if (ca2.Text.Length > 0)
            {
                certObj = new NetcaPkiLib.Certificate();
                certObj.Decode(ca2.Text);
                certVerifyObj.AddCACert(certObj);
            }

            if (ca3.Text.Length > 0)
            {
                certObj = new NetcaPkiLib.Certificate();
                certObj.Decode(ca3.Text);
                certVerifyObj.AddCACert(certObj);
            }

            certObj = new NetcaPkiLib.Certificate();
            certObj.Decode(eecert.Text);

            int status = certVerifyObj.Verify(certObj);

            MessageBox.Show(status.ToString());

            int count=certVerifyObj.GetCertificateCount();
            for(int i=1;i<=count;i++)
            {
                certVerifyObj.GetCertificate(i).Display();
            }
            
        }
    }
}