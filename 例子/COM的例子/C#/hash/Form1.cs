using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace hash
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
            byte[] data = new byte[3];
            byte[] hash;

            data[0] = (byte)'a';
            data[1] = (byte)'b';
            data[2] = (byte)'c';

            hash = (byte[])device.Hash(NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_SHA256, data);
            MessageBox.Show(util.BinaryToHex(hash,true));
        }
    }
}