using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace mac
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NetcaPkiLib.Device device = new NetcaPkiLib.Device();
            NetcaPkiLib.Utilities util = new NetcaPkiLib.Utilities();

            byte[] key = (byte[])util.Encode("Jefe", NetcaPkiLib.Constants.NETCAPKI_CP_UTF8);
            byte[] data = (byte[])util.Encode("what do ya want for nothing?", NetcaPkiLib.Constants.NETCAPKI_CP_UTF8);

            byte[] mac = (byte[])device.Mac(NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_HMAC_SHA256, key, data);
            MessageBox.Show(util.BinaryToHex(mac,true));

        }
    }
}