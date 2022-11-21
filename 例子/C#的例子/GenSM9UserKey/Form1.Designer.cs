namespace GenSM9UserKey
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
            this.masteKeyTextBox = new System.Windows.Forms.TextBox();
            this.masteKeyFileNameButton = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.idTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.userKeyTextBox = new System.Windows.Forms.TextBox();
            this.userKeyFileNameButton = new System.Windows.Forms.Button();
            this.okButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(26, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "主密钥文件：";
            // 
            // masteKeyTextBox
            // 
            this.masteKeyTextBox.Location = new System.Drawing.Point(150, 27);
            this.masteKeyTextBox.Name = "masteKeyTextBox";
            this.masteKeyTextBox.Size = new System.Drawing.Size(220, 21);
            this.masteKeyTextBox.TabIndex = 1;
            // 
            // masteKeyFileNameButton
            // 
            this.masteKeyFileNameButton.Location = new System.Drawing.Point(382, 27);
            this.masteKeyFileNameButton.Name = "masteKeyFileNameButton";
            this.masteKeyFileNameButton.Size = new System.Drawing.Size(38, 21);
            this.masteKeyFileNameButton.TabIndex = 2;
            this.masteKeyFileNameButton.Text = "...";
            this.masteKeyFileNameButton.UseVisualStyleBackColor = true;
            this.masteKeyFileNameButton.Click += new System.EventHandler(this.masteKeyFileNameButton_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(26, 77);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(65, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "用户标识：";
            // 
            // idTextBox
            // 
            this.idTextBox.Location = new System.Drawing.Point(150, 73);
            this.idTextBox.Name = "idTextBox";
            this.idTextBox.Size = new System.Drawing.Size(220, 21);
            this.idTextBox.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(26, 123);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(89, 12);
            this.label3.TabIndex = 5;
            this.label3.Text = "用户密钥文件：";
            // 
            // userKeyTextBox
            // 
            this.userKeyTextBox.Location = new System.Drawing.Point(150, 119);
            this.userKeyTextBox.Name = "userKeyTextBox";
            this.userKeyTextBox.Size = new System.Drawing.Size(220, 21);
            this.userKeyTextBox.TabIndex = 6;
            // 
            // userKeyFileNameButton
            // 
            this.userKeyFileNameButton.Location = new System.Drawing.Point(384, 119);
            this.userKeyFileNameButton.Name = "userKeyFileNameButton";
            this.userKeyFileNameButton.Size = new System.Drawing.Size(38, 21);
            this.userKeyFileNameButton.TabIndex = 7;
            this.userKeyFileNameButton.Text = "...";
            this.userKeyFileNameButton.UseVisualStyleBackColor = true;
            this.userKeyFileNameButton.Click += new System.EventHandler(this.userKeyFileNameButton_Click);
            // 
            // okButton
            // 
            this.okButton.Location = new System.Drawing.Point(100, 169);
            this.okButton.Name = "okButton";
            this.okButton.Size = new System.Drawing.Size(56, 30);
            this.okButton.TabIndex = 8;
            this.okButton.Text = "确定";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.okButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(266, 169);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(56, 30);
            this.exitButton.TabIndex = 9;
            this.exitButton.Text = "退出";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(446, 228);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.okButton);
            this.Controls.Add(this.userKeyFileNameButton);
            this.Controls.Add(this.userKeyTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.idTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.masteKeyFileNameButton);
            this.Controls.Add(this.masteKeyTextBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "产生SM9用户密钥";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox masteKeyTextBox;
        private System.Windows.Forms.Button masteKeyFileNameButton;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox idTextBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox userKeyTextBox;
        private System.Windows.Forms.Button userKeyFileNameButton;
        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.Button exitButton;
    }
}

