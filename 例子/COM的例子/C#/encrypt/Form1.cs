using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace encrypt
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
        
            byte[] key;
            byte[] data;
            byte[] cipher;

            key = (byte[])util.HexToBinary("000102030405060708090a0b0c0d0e0f");
            data = (byte[])util.HexToBinary("00112233445566778899aabbccddeeff");

            cipher = (byte[])device.Encrypt(NetcaPkiLib.Constants.NETCAPKI_ALGORITHM_AES_ECB,key,null,
                NetcaPkiLib.Constants.NETCAPKI_PADDING_NONE,data);
            MessageBox.Show(util.BinaryToHex(cipher,true));

        }
    }
}