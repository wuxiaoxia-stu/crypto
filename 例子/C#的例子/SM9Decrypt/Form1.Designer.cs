namespace SM9Decrypt
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
            this.userKeyTextBox = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.cipherTextBox = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.clearTextBox = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.okButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(89, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "用户密钥文件：";
            // 
            // userKeyTextBox
            // 
            this.userKeyTextBox.Location = new System.Drawing.Point(117, 27);
            this.userKeyTextBox.Name = "userKeyTextBox";
            this.userKeyTextBox.Size = new System.Drawing.Size(224, 21);
            this.userKeyTextBox.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(353, 27);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(31, 21);
            this.button1.TabIndex = 2;
            this.button1.Text = "...";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(24, 67);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(65, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "密文文件：";
            // 
            // cipherTextBox
            // 
            this.cipherTextBox.Location = new System.Drawing.Point(117, 63);
            this.cipherTextBox.Name = "cipherTextBox";
            this.cipherTextBox.Size = new System.Drawing.Size(224, 21);
            this.cipherTextBox.TabIndex = 4;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(353, 63);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(31, 21);
            this.button2.TabIndex = 5;
            this.button2.Text = "...";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(24, 103);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 12);
            this.label3.TabIndex = 6;
            this.label3.Text = "明文文件：";
            // 
            // clearTextBox
            // 
            this.clearTextBox.Location = new System.Drawing.Point(117, 99);
            this.clearTextBox.Name = "clearTextBox";
            this.clearTextBox.Size = new System.Drawing.Size(224, 21);
            this.clearTextBox.TabIndex = 7;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(353, 99);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(31, 21);
            this.button3.TabIndex = 8;
            this.button3.Text = "...";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // okButton
            // 
            this.okButton.Location = new System.Drawing.Point(78, 139);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(56, 31);
            this.okButton.TabIndex = 9;
            this.okButton.Text = "确定";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(261, 139);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(56, 31);
            this.exitButton.TabIndex = 10;
            this.exitButton.Text = "退出";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(406, 199);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.clearTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.cipherTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.userKeyTextBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "SM9解密";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox userKeyTextBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox cipherTextBox;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox clearTextBox;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Button exitButton;
    }
}

