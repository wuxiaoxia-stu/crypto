namespace SM9Sign
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
            this.userKeyButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.tbsTextBox = new System.Windows.Forms.TextBox();
            this.tbsButton = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.signTextBox = new System.Windows.Forms.TextBox();
            this.signButton = new System.Windows.Forms.Button();
            this.okButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(89, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "用户密钥文件：";
            // 
            // userKeyTextBox
            // 
            this.userKeyTextBox.Location = new System.Drawing.Point(116, 26);
            this.userKeyTextBox.Name = "userKeyTextBox";
            this.userKeyTextBox.Size = new System.Drawing.Size(222, 21);
            this.userKeyTextBox.TabIndex = 1;
            // 
            // userKeyButton
            // 
            this.userKeyButton.Location = new System.Drawing.Point(350, 26);
            this.userKeyButton.Name = "userKeyButton";
            this.userKeyButton.Size = new System.Drawing.Size(36, 21);
            this.userKeyButton.TabIndex = 2;
            this.userKeyButton.Text = "...";
            this.userKeyButton.UseVisualStyleBackColor = true;
            this.userKeyButton.Click += new System.EventHandler(this.userKeyButton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 77);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(89, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "要签名的文件：";
            // 
            // tbsTextBox
            // 
            this.tbsTextBox.Location = new System.Drawing.Point(116, 73);
            this.tbsTextBox.Name = "tbsTextBox";
            this.tbsTextBox.Size = new System.Drawing.Size(222, 21);
            this.tbsTextBox.TabIndex = 4;
            // 
            // tbsButton
            // 
            this.tbsButton.Location = new System.Drawing.Point(350, 73);
            this.tbsButton.Name = "tbsButton";
            this.tbsButton.Size = new System.Drawing.Size(36, 21);
            this.tbsButton.TabIndex = 5;
            this.tbsButton.Text = "...";
            this.tbsButton.UseVisualStyleBackColor = true;
            this.tbsButton.Click += new System.EventHandler(this.tbsButton_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 124);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 12);
            this.label3.TabIndex = 6;
            this.label3.Text = "签名值文件：";
            // 
            // signTextBox
            // 
            this.signTextBox.Location = new System.Drawing.Point(116, 120);
            this.signTextBox.Name = "signTextBox";
            this.signTextBox.Size = new System.Drawing.Size(222, 21);
            this.signTextBox.TabIndex = 7;
            // 
            // signButton
            // 
            this.signButton.Location = new System.Drawing.Point(350, 120);
            this.signButton.Name = "signButton";
            this.signButton.Size = new System.Drawing.Size(36, 21);
            this.signButton.TabIndex = 8;
            this.signButton.Text = "...";
            this.signButton.UseVisualStyleBackColor = true;
            this.signButton.Click += new System.EventHandler(this.signButton_Click);
            // 
            // okButton
            // 
            this.okButton.Location = new System.Drawing.Point(96, 171);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(64, 33);
            this.okButton.TabIndex = 9;
            this.okButton.Text = "确定";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(252, 171);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(64, 33);
            this.exitButton.TabIndex = 10;
            this.exitButton.Text = "退出";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(408, 229);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.signButton);
            this.Controls.Add(this.signTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.tbsButton);
            this.Controls.Add(this.tbsTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.userKeyButton);
            this.Controls.Add(this.userKeyTextBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "SM9签名";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox userKeyTextBox;
        private System.Windows.Forms.Button userKeyButton;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox tbsTextBox;
        private System.Windows.Forms.Button tbsButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox signTextBox;
        private System.Windows.Forms.Button signButton;
        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Button exitButton;
    }
}

