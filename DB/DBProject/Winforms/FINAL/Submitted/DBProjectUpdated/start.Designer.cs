namespace DBProject
{
    partial class start
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(start));
            singupbutton = new Button();
            LOGIN = new Button();
            usertext = new TextBox();
            passtext = new TextBox();
            label1 = new Label();
            label2 = new Label();
            pictureBox1 = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // singupbutton
            // 
            singupbutton.BackColor = Color.FromArgb(42, 64, 95);
            singupbutton.Image = (Image)resources.GetObject("singupbutton.Image");
            singupbutton.Location = new Point(1152, 26);
            singupbutton.Name = "singupbutton";
            singupbutton.Size = new Size(76, 56);
            singupbutton.TabIndex = 0;
            singupbutton.UseVisualStyleBackColor = false;
            singupbutton.Click += singupbutton_Click;
            // 
            // LOGIN
            // 
            LOGIN.Location = new Point(573, 634);
            LOGIN.Name = "LOGIN";
            LOGIN.Size = new Size(126, 44);
            LOGIN.TabIndex = 1;
            LOGIN.Text = "LOGIN";
            LOGIN.UseVisualStyleBackColor = true;
            LOGIN.Click += LOGIN_Click;
            // 
            // usertext
            // 
            usertext.Location = new Point(641, 443);
            usertext.Name = "usertext";
            usertext.Size = new Size(170, 27);
            usertext.TabIndex = 2;
            // 
            // passtext
            // 
            passtext.Location = new Point(641, 542);
            passtext.Name = "passtext";
            passtext.Size = new Size(170, 27);
            passtext.TabIndex = 3;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Segoe UI", 16.2F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.White;
            label1.Location = new Point(432, 432);
            label1.Name = "label1";
            label1.Size = new Size(148, 38);
            label1.TabIndex = 4;
            label1.Text = "Username:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Transparent;
            label2.Font = new Font("Segoe UI", 16.2F, FontStyle.Regular, GraphicsUnit.Point);
            label2.ForeColor = Color.White;
            label2.Location = new Point(437, 531);
            label2.Name = "label2";
            label2.Size = new Size(138, 38);
            label2.TabIndex = 5;
            label2.Text = "Password:";
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.Transparent;
            pictureBox1.BackgroundImage = (Image)resources.GetObject("pictureBox1.BackgroundImage");
            pictureBox1.Location = new Point(467, -15);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(334, 365);
            pictureBox1.TabIndex = 6;
            pictureBox1.TabStop = false;
            // 
            // start
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(1250, 804);
            Controls.Add(pictureBox1);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(passtext);
            Controls.Add(usertext);
            Controls.Add(LOGIN);
            Controls.Add(singupbutton);
            Name = "start";
            Text = "Form1";
            Load += start_Load;
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button singupbutton;
        private Button LOGIN;
        private TextBox usertext;
        private TextBox passtext;
        private Label label1;
        private Label label2;
        private PictureBox pictureBox1;
    }
}