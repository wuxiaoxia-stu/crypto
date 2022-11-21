namespace GenSM9MasterKey
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
            this.typeComboBox = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.hidTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.keypairFileNameTextBox = new System.Windows.Forms.TextBox();
            this.keypairbutton = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.publickeyFileNameTextBox = new System.Windows.Forms.TextBox();
            this.publickeybutton = new System.Windows.Forms.Button();
            this.okbutton = new System.Windows.Forms.Button();
            this.exitbutton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 29);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "密钥类型：";
            // 
            // typeComboBox
            // 
            this.typeComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.typeComboBox.FormattingEnabled = true;
            this.typeComboBox.Items.AddRange(new object[] {
            "加密",
            "签名",
            "密钥交换"});
            this.typeComboBox.Location = new System.Drawing.Point(133, 25);
            this.typeComboBox.Name = "typeComboBox";
            this.typeComboBox.Size = new System.Drawing.Size(240, 20);
            this.typeComboBox.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(25, 72);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "hid：";
            // 
            // hidTextBox
            // 
            this.hidTextBox.Location = new System.Drawing.Point(133, 68);
            this.hidTextBox.Name = "hidTextBox";
            this.hidTextBox.Size = new System.Drawing.Size(240, 21);
            this.hidTextBox.TabIndex = 3;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(26, 115);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(89, 12);
            this.label3.TabIndex = 4;
            this.label3.Text = "主密钥对文件：";
            // 
            // keypairFileNameTextBox
            // 
            this.keypairFileNameTextBox.Location = new System.Drawing.Point(133, 111);
            this.keypairFileNameTextBox.Name = "keypairFileNameTextBox";
            this.keypairFileNameTextBox.Size = new System.Drawing.Size(240, 21);
            this.keypairFileNameTextBox.TabIndex = 5;
            // 
            // keypairbutton
            // 
            this.keypairbutton.Location = new System.Drawing.Point(387, 111);
            this.keypairbutton.Name = "keypairbutton";
            this.keypairbutton.Size = new System.Drawing.Size(33, 21);
            this.keypairbutton.TabIndex = 6;
            this.keypairbutton.Text = "...";
            this.keypairbutton.UseVisualStyleBackColor = true;
            this.keypairbutton.Click += new System.EventHandler(this.keypairbutton_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(28, 158);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(77, 12);
            this.label4.TabIndex = 7;
            this.label4.Text = "主公钥文件：";
            // 
            // publickeyFileNameTextBox
            // 
            this.publickeyFileNameTextBox.Location = new System.Drawing.Point(133, 154);
            this.publickeyFileNameTextBox.Name = "publickeyFileNameTextBox";
            this.publickeyFileNameTextBox.Size = new System.Drawing.Size(240, 21);
            this.publickeyFileNameTextBox.TabIndex = 8;
            // 
            // publickeybutton
            // 
            this.publickeybutton.Location = new System.Drawing.Point(387, 154);
            this.publickeybutton.Name = "publickeybutton";
            this.publickeybutton.Size = new System.Drawing.Size(33, 21);
            this.publickeybutton.TabIndex = 9;
            this.publickeybutton.Text = "...";
            this.publickeybutton.UseVisualStyleBackColor = true;
            this.publickeybutton.Click += new System.EventHandler(this.publickeybutton_Click);
            // 
            // okbutton
            // 
            this.okbutton.Location = new System.Drawing.Point(100, 201);
            this.okbutton.Name = "okbutton";
            this.okbutton.Size = new System.Drawing.Size(54, 30);
            this.okbutton.TabIndex = 10;
            this.okbutton.Text = "确定";
            this.okbutton.UseVisualStyleBackColor = true;
            this.okbutton.Click += new System.EventHandler(this.okbutton_Click);
            // 
            // exitbutton
            // 
            this.exitbutton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.exitbutton.Location = new System.Drawing.Point(276, 201);
            this.exitbutton.Name = "exitbutton";
            this.exitbutton.Size = new System.Drawing.Size(54, 30);
            this.exitbutton.TabIndex = 11;
            this.exitbutton.Text = "退出";
            this.exitbutton.UseVisualStyleBackColor = true;
            this.exitbutton.Click += new System.EventHandler(this.exitbutton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(443, 257);
            this.Controls.Add(this.exitbutton);
            this.Controls.Add(this.okbutton);
            this.Controls.Add(this.publickeybutton);
            this.Controls.Add(this.publickeyFileNameTextBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.keypairbutton);
            this.Controls.Add(this.keypairFileNameTextBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.hidTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.typeComboBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "产生SM9主密钥";
            this.Activated += new System.EventHandler(this.Form1_Activated);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox typeComboBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox hidTextBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox keypairFileNameTextBox;
        private System.Windows.Forms.Button keypairbutton;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox publickeyFileNameTextBox;
        private System.Windows.Forms.Button publickeybutton;
        private System.Windows.Forms.Button okbutton;
        private System.Windows.Forms.Button exitbutton;
    }
}

