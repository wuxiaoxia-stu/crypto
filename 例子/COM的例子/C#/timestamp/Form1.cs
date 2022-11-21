using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace timestamp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NetcaPkiLib.TimeStamp ts = new NetcaPkiLib.TimeStamp();
            NetcaPkiLib.Device device=new NetcaPkiLib.Device();
            NetcaPkiLib.Utilities util=new NetcaPkiLib.Utilities();

            int algo = NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_SHA1;
            byte[] hash=(byte[])device.Hash(algo,util.Encode("123",NetcaPkiLib.Constants.NETCAPKI_CP_UTF8));

            ts.TsaUrl="https://classatsa.cnca.net/tsa.asp";
            ts.HashAlgorithm=algo;
            ts.MessageImprint=hash;

            int resp=ts.GetTSPResponse();
            if(resp==NetcaPkiLib.Constants.NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTED
                || resp==NetcaPkiLib.Constants.NETCAPKI_TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS)
            {
                MessageBox.Show(ts.GetTime().ToString());
            }
            else
            {
                MessageBox.Show("获取时间戳失败");
            }
        }
    }
}