using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace store
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NetcaPkiLib.Store store = new NetcaPkiLib.Store();
            NetcaPkiLib.Certificate cert;
            DateTime now = DateTime.Now;
            store.Open(NetcaPkiLib.Constants.NETCAPKI_CERT_STORE_TYPE_CURRENT_USER, NetcaPkiLib.Constants.NETCAPKI_CERT_STORE_NAME_MY);
            int count = store.GetCertificateCount();
            for (int i = 1; i <= count; i++)
            {
                cert = store.GetCertificate(i);
                if (cert.ValidFromDate.CompareTo(now)<=0 
                    && cert.ValidToDate.CompareTo(now)>=0
                    && (cert.KeyUsage & (NetcaPkiLib.Constants.NETCAPKI_KEYUSAGE_DIGITALSIGNATURE | NetcaPkiLib.Constants.NETCAPKI_KEYUSAGE_NONREPUDIATION))!=0)
                {
                    cert.Display();
                }
            }
        }
    }
}