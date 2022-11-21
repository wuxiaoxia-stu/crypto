namespace verifycert
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.rootca = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.ca1 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.ca2 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.ca3 = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.eecert = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // rootca
            // 
            this.rootca.Location = new System.Drawing.Point(123, 12);
            this.rootca.Multiline = true;
            this.rootca.Name = "rootca";
            this.rootca.Size = new System.Drawing.Size(350, 119);
            this.rootca.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(223, 662);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(69, 35);
            this.button1.TabIndex = 11;
            this.button1.Text = "验证";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 2;
            this.label1.Text = "根证书：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(15, 149);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "CA1：";
            // 
            // ca1
            // 
            this.ca1.Location = new System.Drawing.Point(123, 146);
            this.ca1.Multiline = true;
            this.ca1.Name = "ca1";
            this.ca1.Size = new System.Drawing.Size(347, 122);
            this.ca1.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(21, 289);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 12);
            this.label3.TabIndex = 5;
            this.label3.Text = "CA2:";
            // 
            // ca2
            // 
            this.ca2.Location = new System.Drawing.Point(123, 286);
            this.ca2.Multiline = true;
            this.ca2.Name = "ca2";
            this.ca2.Size = new System.Drawing.Size(345, 106);
            this.ca2.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(15, 414);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(29, 12);
            this.label4.TabIndex = 7;
            this.label4.Text = "CA3:";
            // 
            // ca3
            // 
            this.ca3.Location = new System.Drawing.Point(123, 411);
            this.ca3.Multiline = true;
            this.ca3.Name = "ca3";
            this.ca3.Size = new System.Drawing.Size(345, 93);
            this.ca3.TabIndex = 8;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 527);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(89, 12);
            this.label5.TabIndex = 9;
            this.label5.Text = "要验证的证书：";
            // 
            // eecert
            // 
            this.eecert.Location = new System.Drawing.Point(120, 524);
            this.eecert.Multiline = true;
            this.eecert.Name = "eecert";
            this.eecert.Size = new System.Drawing.Size(349, 114);
            this.eecert.TabIndex = 10;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(504, 729);
            this.Controls.Add(this.eecert);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.ca3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.ca2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.ca1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.rootca);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox rootca;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox ca1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox ca2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox ca3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox eecert;
    }
}

