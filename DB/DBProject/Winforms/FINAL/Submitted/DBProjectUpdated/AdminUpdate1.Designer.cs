namespace DBProject
{
    partial class AdminUpdate1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AdminUpdate1));
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            usernametxt = new TextBox();
            oldpasswordtxt = new TextBox();
            newpasswordtxt = new TextBox();
            button1 = new Button();
            button2 = new Button();
            panel1 = new Panel();
            button7 = new Button();
            button6 = new Button();
            button4 = new Button();
            button5 = new Button();
            panel2 = new Panel();
            label4 = new Label();
            pictureBox1 = new PictureBox();
            panel1.SuspendLayout();
            panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.White;
            label1.Location = new Point(561, 274);
            label1.Name = "label1";
            label1.Size = new Size(122, 31);
            label1.TabIndex = 0;
            label1.Text = "Username:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Transparent;
            label2.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label2.ForeColor = Color.White;
            label2.Location = new Point(523, 343);
            label2.Name = "label2";
            label2.Size = new Size(160, 31);
            label2.TabIndex = 1;
            label2.Text = "Old password:";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label3.ForeColor = Color.White;
            label3.Location = new Point(523, 410);
            label3.Name = "label3";
            label3.Size = new Size(169, 31);
            label3.TabIndex = 2;
            label3.Text = "New password:";
            // 
            // usernametxt
            // 
            usernametxt.Location = new Point(737, 274);
            usernametxt.Name = "usernametxt";
            usernametxt.Size = new Size(162, 27);
            usernametxt.TabIndex = 3;
            // 
            // oldpasswordtxt
            // 
            oldpasswordtxt.Location = new Point(737, 343);
            oldpasswordtxt.Name = "oldpasswordtxt";
            oldpasswordtxt.Size = new Size(162, 27);
            oldpasswordtxt.TabIndex = 4;
            // 
            // newpasswordtxt
            // 
            newpasswordtxt.Location = new Point(737, 410);
            newpasswordtxt.Name = "newpasswordtxt";
            newpasswordtxt.Size = new Size(162, 27);
            newpasswordtxt.TabIndex = 5;
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(689, 578);
            button1.Name = "button1";
            button1.Size = new Size(110, 39);
            button1.TabIndex = 6;
            button1.Text = "Update";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.BackColor = Color.FromArgb(64, 64, 64);
            button2.Image = (Image)resources.GetObject("button2.Image");
            button2.Location = new Point(12, 12);
            button2.Name = "button2";
            button2.Size = new Size(62, 29);
            button2.TabIndex = 7;
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // panel1
            // 
            panel1.BackColor = Color.FromArgb(64, 64, 64);
            panel1.Controls.Add(button7);
            panel1.Controls.Add(button2);
            panel1.Controls.Add(button6);
            panel1.Controls.Add(button4);
            panel1.Controls.Add(button5);
            panel1.Dock = DockStyle.Left;
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(250, 804);
            panel1.TabIndex = 8;
            // 
            // button7
            // 
            button7.BackColor = Color.FromArgb(64, 64, 64);
            button7.Cursor = Cursors.Hand;
            button7.Image = (Image)resources.GetObject("button7.Image");
            button7.Location = new Point(0, 508);
            button7.Name = "button7";
            button7.Size = new Size(250, 135);
            button7.TabIndex = 19;
            button7.Text = "View Courses";
            button7.TextImageRelation = TextImageRelation.ImageAboveText;
            button7.UseVisualStyleBackColor = false;
            button7.Click += button7_Click;
            // 
            // button6
            // 
            button6.BackColor = Color.FromArgb(64, 64, 64);
            button6.Cursor = Cursors.Hand;
            button6.Image = (Image)resources.GetObject("button6.Image");
            button6.Location = new Point(0, 382);
            button6.Name = "button6";
            button6.Size = new Size(250, 135);
            button6.TabIndex = 18;
            button6.Text = "View Faculty";
            button6.TextImageRelation = TextImageRelation.ImageAboveText;
            button6.UseVisualStyleBackColor = false;
            button6.Click += button6_Click;
            // 
            // button4
            // 
            button4.BackColor = Color.FromArgb(64, 64, 64);
            button4.Cursor = Cursors.Hand;
            button4.Image = (Image)resources.GetObject("button4.Image");
            button4.Location = new Point(0, 122);
            button4.Name = "button4";
            button4.Size = new Size(250, 135);
            button4.TabIndex = 16;
            button4.Text = "Add New Admin";
            button4.TextImageRelation = TextImageRelation.ImageAboveText;
            button4.UseVisualStyleBackColor = false;
            button4.Click += button4_Click;
            // 
            // button5
            // 
            button5.BackColor = Color.FromArgb(64, 64, 64);
            button5.Cursor = Cursors.Hand;
            button5.Image = (Image)resources.GetObject("button5.Image");
            button5.Location = new Point(0, 255);
            button5.Name = "button5";
            button5.Size = new Size(250, 135);
            button5.TabIndex = 17;
            button5.Text = "View Admins";
            button5.TextImageRelation = TextImageRelation.ImageAboveText;
            button5.UseVisualStyleBackColor = false;
            button5.Click += button5_Click;
            // 
            // panel2
            // 
            panel2.BackColor = Color.FromArgb(64, 64, 64);
            panel2.Controls.Add(label4);
            panel2.Controls.Add(pictureBox1);
            panel2.Dock = DockStyle.Top;
            panel2.Location = new Point(250, 0);
            panel2.Name = "panel2";
            panel2.Size = new Size(1000, 125);
            panel2.TabIndex = 9;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 24F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(347, 37);
            label4.Name = "label4";
            label4.Size = new Size(412, 54);
            label4.TabIndex = 8;
            label4.Text = "Admin Update Details";
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.Transparent;
            pictureBox1.BackgroundImage = (Image)resources.GetObject("pictureBox1.BackgroundImage");
            pictureBox1.Location = new Point(886, 3);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(114, 122);
            pictureBox1.TabIndex = 7;
            pictureBox1.TabStop = false;
            // 
            // AdminUpdate1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(1250, 804);
            Controls.Add(panel2);
            Controls.Add(panel1);
            Controls.Add(button1);
            Controls.Add(newpasswordtxt);
            Controls.Add(oldpasswordtxt);
            Controls.Add(usernametxt);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "AdminUpdate1";
            Text = "AdminUpdate1";
            Load += AdminUpdate1_Load;
            panel1.ResumeLayout(false);
            panel2.ResumeLayout(false);
            panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private Label label3;
        private TextBox usernametxt;
        private TextBox oldpasswordtxt;
        private TextBox newpasswordtxt;
        private Button button1;
        private Button button2;
        private Panel panel1;
        private Panel panel2;
        private Button button7;
        private Button button6;
        private Button button4;
        private Button button5;
        private PictureBox pictureBox1;
        private Label label4;
    }
}