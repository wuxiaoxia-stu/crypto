namespace SM9KeyExchange
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
            this.senderUserKeyTextBox = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.receiverUserKeyTextBox = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.keyExchangeButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.displayTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.keyLenTextBox = new System.Windows.Forms.TextBox();
            this.keyConfirmCheckBox = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(15, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(137, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "发起方的用户密钥文件：";
            // 
            // senderUserKeyTextBox
            // 
            this.senderUserKeyTextBox.Location = new System.Drawing.Point(172, 17);
            this.senderUserKeyTextBox.Name = "senderUserKeyTextBox";
            this.senderUserKeyTextBox.Size = new System.Drawing.Size(308, 21);
            this.senderUserKeyTextBox.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(492, 17);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(40, 21);
            this.button1.TabIndex = 2;
            this.button1.Text = "...";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(15, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(137, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "响应方的用户密钥文件：";
            // 
            // receiverUserKeyTextBox
            // 
            this.receiverUserKeyTextBox.Location = new System.Drawing.Point(172, 49);
            this.receiverUserKeyTextBox.Name = "receiverUserKeyTextBox";
            this.receiverUserKeyTextBox.Size = new System.Drawing.Size(307, 21);
            this.receiverUserKeyTextBox.TabIndex = 3;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(492, 49);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(40, 21);
            this.button2.TabIndex = 4;
            this.button2.Text = "...";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // keyExchangeButton
            // 
            this.keyExchangeButton.Location = new System.Drawing.Point(88, 139);
            this.keyExchangeButton.Name = "keyExchangeButton";
            this.keyExchangeButton.Size = new System.Drawing.Size(81, 33);
            this.keyExchangeButton.TabIndex = 7;
            this.keyExchangeButton.Text = "密钥交换";
            this.keyExchangeButton.UseVisualStyleBackColor = true;
            this.keyExchangeButton.Click += new System.EventHandler(this.keyExchangeButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(362, 129);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(81, 33);
            this.exitButton.TabIndex = 8;
            this.exitButton.Text = "退出";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // displayTextBox
            // 
            this.displayTextBox.Location = new System.Drawing.Point(20, 185);
            this.displayTextBox.Multiline = true;
            this.displayTextBox.Name = "displayTextBox";
            this.displayTextBox.ReadOnly = true;
            this.displayTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.displayTextBox.Size = new System.Drawing.Size(510, 203);
            this.displayTextBox.TabIndex = 9;
            this.displayTextBox.TabStop = false;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(15, 84);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 12);
            this.label3.TabIndex = 9;
            this.label3.Text = "密钥长度：";
            // 
            // keyLenTextBox
            // 
            this.keyLenTextBox.Location = new System.Drawing.Point(172, 80);
            this.keyLenTextBox.Name = "keyLenTextBox";
            this.keyLenTextBox.Size = new System.Drawing.Size(307, 21);
            this.keyLenTextBox.TabIndex = 5;
            // 
            // keyConfirmCheckBox
            // 
            this.keyConfirmCheckBox.AutoSize = true;
            this.keyConfirmCheckBox.Location = new System.Drawing.Point(15, 116);
            this.keyConfirmCheckBox.Name = "keyConfirmCheckBox";
            this.keyConfirmCheckBox.Size = new System.Drawing.Size(96, 16);
            this.keyConfirmCheckBox.TabIndex = 6;
            this.keyConfirmCheckBox.Text = "需要密钥确认";
            this.keyConfirmCheckBox.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(550, 408);
            this.Controls.Add(this.keyConfirmCheckBox);
            this.Controls.Add(this.keyLenTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.displayTextBox);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.keyExchangeButton);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.receiverUserKeyTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.senderUserKeyTextBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "SM9密钥交换";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox senderUserKeyTextBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox receiverUserKeyTextBox;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button keyExchangeButton;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.TextBox displayTextBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox keyLenTextBox;
        private System.Windows.Forms.CheckBox keyConfirmCheckBox;
    }
}

