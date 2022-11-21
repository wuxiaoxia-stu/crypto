using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using NetcaPkiLib;

namespace TestWinForm
{
    public partial class Form1 : Form
    {
        private static readonly object Event_CAKey_Changed;

        private Utilities caUtilities;

        static Form1()
        {
            Event_CAKey_Changed = new object();
        }

        public Form1()
        {
            InitializeComponent();
            InitializeCusComponent();
        }

        private void InitializeCusComponent()
        {
            caUtilities = new Utilities();
            caUtilities.InsertEvent += caUtilities_InsertEvent;
            caUtilities.PulloutEvent += caUtilities_PulloutEvent;
            caUtilities.RegEvent();
        }

        void caUtilities_PulloutEvent(int type, string sn)
        {
            string msg = string.Format("拔出Key：{0}, {1}\n", type, sn);
            System.IO.File.AppendAllText(@"D:\log.txt", msg);
        }

        void caUtilities_InsertEvent(int type, string sn)
        {
            string msg = string.Format("插入Key：{0}, {1}\n", type, sn);
            System.IO.File.AppendAllText(@"D:\log.txt", msg);
        }
        
    }
}
