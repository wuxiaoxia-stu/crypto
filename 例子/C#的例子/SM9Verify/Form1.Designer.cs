namespace SM9Verify
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
            this.label1 = new System.Windows.Forms.Label();
            this.masterKeyTextBox = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.tbsTextBox = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.signTextBox = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.okButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.idTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(15, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "主公钥文件：";
            // 
            // masterKeyTextBox
            // 
            this.masterKeyTextBox.Location = new System.Drawing.Point(110, 23);
            this.masterKeyTextBox.Name = "masterKeyTextBox";
            this.masterKeyTextBox.Size = new System.Drawing.Size(206, 21);
            this.masterKeyTextBox.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(329, 23);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(33, 21);
            this.button1.TabIndex = 2;
            this.button1.Text = "...";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(15, 99);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(89, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "要签名的文件：";
            // 
            // tbsTextBox
            // 
            this.tbsTextBox.Location = new System.Drawing.Point(110, 95);
            this.tbsTextBox.Name = "tbsTextBox";
            this.tbsTextBox.Size = new System.Drawing.Size(206, 21);
            this.tbsTextBox.TabIndex = 4;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(329, 95);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(33, 21);
            this.button2.TabIndex = 5;
            this.button2.Text = "...";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(15, 135);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 12);
            this.label3.TabIndex = 6;
            this.label3.Text = "签名值文件：";
            // 
            // signTextBox
            // 
            this.signTextBox.Location = new System.Drawing.Point(110, 131);
            this.signTextBox.Name = "signTextBox";
            this.signTextBox.Size = new System.Drawing.Size(206, 21);
            this.signTextBox.TabIndex = 6;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(329, 131);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(33, 21);
            this.button3.TabIndex = 7;
            this.button3.Text = "...";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // okButton
            // 
            this.okButton.Location = new System.Drawing.Point(82, 171);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(57, 32);
            this.okButton.TabIndex = 8;
            this.okButton.Text = "确定";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(220, 171);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(57, 32);
            this.exitButton.TabIndex = 9;
            this.exitButton.Text = "退出";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(16, 63);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 12);
            this.label4.TabIndex = 11;
            this.label4.Text = "用户标识：";
            // 
            // idTextBox
            // 
            this.idTextBox.Location = new System.Drawing.Point(110, 59);
            this.idTextBox.Name = "idTextBox";
            this.idTextBox.Size = new System.Drawing.Size(206, 21);
            this.idTextBox.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(381, 226);
            this.Controls.Add(this.idTextBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.signTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.tbsTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.masterKeyTextBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "SM9验证签名";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox masterKeyTextBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tbsTextBox;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox signTextBox;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox idTextBox;
    }
}

