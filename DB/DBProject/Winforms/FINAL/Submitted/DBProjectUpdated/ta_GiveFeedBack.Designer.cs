namespace DBProject
{
    partial class ta_GiveFeedBack
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ta_GiveFeedBack));
            label1 = new Label();
            richTextBox1 = new RichTextBox();
            button2 = new Button();
            pictureBox1 = new PictureBox();
            button4 = new Button();
            button6 = new Button();
            panel2 = new Panel();
            label11 = new Label();
            panel1 = new Panel();
            button7 = new Button();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            panel2.SuspendLayout();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Segoe UI", 14F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.White;
            label1.Location = new Point(456, 270);
            label1.Name = "label1";
            label1.Size = new Size(182, 32);
            label1.TabIndex = 6;
            label1.Text = "Enter Feedback:";
            // 
            // richTextBox1
            // 
            richTextBox1.Location = new Point(422, 322);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(681, 270);
            richTextBox1.TabIndex = 5;
            richTextBox1.Text = "";
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 14F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(647, 642);
            button2.Name = "button2";
            button2.Size = new Size(233, 54);
            button2.TabIndex = 4;
            button2.Text = "Submit Feedback";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.Transparent;
            pictureBox1.BackgroundImage = (Image)resources.GetObject("pictureBox1.BackgroundImage");
            pictureBox1.Location = new Point(886, 0);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(114, 122);
            pictureBox1.TabIndex = 1;
            pictureBox1.TabStop = false;
            // 
            // button4
            // 
            button4.BackColor = Color.FromArgb(64, 64, 64);
            button4.Image = (Image)resources.GetObject("button4.Image");
            button4.Location = new Point(42, 31);
            button4.Name = "button4";
            button4.Size = new Size(61, 29);
            button4.TabIndex = 0;
            button4.UseVisualStyleBackColor = false;
            button4.Click += button4_Click;
            // 
            // button6
            // 
            button6.BackColor = Color.FromArgb(64, 64, 64);
            button6.Cursor = Cursors.Hand;
            button6.Image = (Image)resources.GetObject("button6.Image");
            button6.Location = new Point(3, 122);
            button6.Name = "button6";
            button6.Size = new Size(250, 135);
            button6.TabIndex = 10;
            button6.Text = "Give Feedback";
            button6.TextImageRelation = TextImageRelation.ImageAboveText;
            button6.UseVisualStyleBackColor = false;
            button6.Click += button6_Click;
            // 
            // panel2
            // 
            panel2.BackColor = Color.FromArgb(64, 64, 64);
            panel2.Controls.Add(label11);
            panel2.Controls.Add(pictureBox1);
            panel2.Dock = DockStyle.Top;
            panel2.Location = new Point(250, 0);
            panel2.Name = "panel2";
            panel2.Size = new Size(1000, 125);
            panel2.TabIndex = 30;
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Font = new Font("Segoe UI", 22F, FontStyle.Regular, GraphicsUnit.Point);
            label11.Location = new Point(339, 35);
            label11.Name = "label11";
            label11.Size = new Size(257, 50);
            label11.TabIndex = 2;
            label11.Text = "Give Feedback";
            // 
            // panel1
            // 
            panel1.BackColor = Color.FromArgb(64, 64, 64);
            panel1.Controls.Add(button7);
            panel1.Controls.Add(button4);
            panel1.Controls.Add(button6);
            panel1.Dock = DockStyle.Left;
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(250, 804);
            panel1.TabIndex = 29;
            // 
            // button7
            // 
            button7.BackColor = Color.FromArgb(64, 64, 64);
            button7.Cursor = Cursors.Hand;
            button7.Image = (Image)resources.GetObject("button7.Image");
            button7.Location = new Point(3, 252);
            button7.Name = "button7";
            button7.Size = new Size(250, 135);
            button7.TabIndex = 11;
            button7.Text = "View Tasks";
            button7.TextImageRelation = TextImageRelation.ImageAboveText;
            button7.UseVisualStyleBackColor = false;
            button7.Click += button7_Click;
            // 
            // ta_GiveFeedBack
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(1250, 804);
            Controls.Add(panel2);
            Controls.Add(panel1);
            Controls.Add(label1);
            Controls.Add(richTextBox1);
            Controls.Add(button2);
            Name = "ta_GiveFeedBack";
            Text = "ta_GiveFeedBack";
            Load += ta_GiveFeedBack_Load;
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            panel2.ResumeLayout(false);
            panel2.PerformLayout();
            panel1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Label label1;
        private RichTextBox richTextBox1;
        private Button button2;
        private PictureBox pictureBox1;
        private Button button4;
        private Button button6;
        private Panel panel2;
        private Label label11;
        private Panel panel1;
        private Button button7;
    }
}