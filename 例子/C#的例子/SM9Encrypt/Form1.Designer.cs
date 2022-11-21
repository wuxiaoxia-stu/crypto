namespace SM9Encrypt
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
            this.idTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.clearTextBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.cipherTextBox = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.okButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "主公钥文件：";
            // 
            // masterKeyTextBox
            // 
            this.masterKeyTextBox.Location = new System.Drawing.Point(98, 23);
            this.masterKeyTextBox.Name = "masterKeyTextBox";
            this.masterKeyTextBox.Size = new System.Drawing.Size(231, 21);
            this.masterKeyTextBox.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(345, 23);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(32, 21);
            this.button1.TabIndex = 2;
            this.button1.Text = "...";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(16, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(65, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "用户标识：";
            // 
            // idTextBox
            // 
            this.idTextBox.Location = new System.Drawing.Point(98, 60);
            this.idTextBox.Name = "idTextBox";
            this.idTextBox.Size = new System.Drawing.Size(231, 21);
            this.idTextBox.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(16, 103);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(41, 12);
            this.label3.TabIndex = 5;
            this.label3.Text = "明文：";
            // 
            // clearTextBox
            // 
            this.clearTextBox.Location = new System.Drawing.Point(98, 103);
            this.clearTextBox.Multiline = true;
            this.clearTextBox.Name = "clearTextBox";
            this.clearTextBox.Size = new System.Drawing.Size(231, 78);
            this.clearTextBox.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(16, 203);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 12);
            this.label4.TabIndex = 7;
            this.label4.Text = "密文文件：";
            // 
            // cipherTextBox
            // 
            this.cipherTextBox.Location = new System.Drawing.Point(98, 199);
            this.cipherTextBox.Name = "cipherTextBox";
            this.cipherTextBox.Size = new System.Drawing.Size(231, 21);
            this.cipherTextBox.TabIndex = 8;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(345, 199);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(32, 21);
            this.button2.TabIndex = 9;
            this.button2.Text = "...";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // okButton
            // 
            this.okButton.Location = new System.Drawing.Point(80, 252);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(63, 29);
            this.okButton.TabIndex = 10;
            this.okButton.Text = "确定";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(237, 252);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(63, 29);
            this.exitButton.TabIndex = 11;
            this.exitButton.Text = "退出";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(399, 302);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.cipherTextBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.clearTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.idTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.masterKeyTextBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "SM9加密";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox masterKeyTextBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox idTextBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox clearTextBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox cipherTextBox;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Button exitButton;
    }
}

