using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace certpath
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NetcaPkiLib.CertPath certpath = new NetcaPkiLib.CertPath();
            NetcaPkiLib.Certificate cert = new NetcaPkiLib.Certificate();

            cert.Decode(textBox1.Text);

            if (certpath.Build(cert) == false)
            {
                MessageBox.Show("构造证书链失败");
                return;
            }
            int count = certpath.GetCertificateCount();
            for (int i = 1; i <=count; i++)
            {
                certpath.GetCertificate(i).Display();
            }
            
        }
    }
}