namespace DBProject
{
    partial class ld_GiveFeedBack
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ld_GiveFeedBack));
            button2 = new Button();
            richTextBox1 = new RichTextBox();
            label1 = new Label();
            label4 = new Label();
            button7 = new Button();
            button6 = new Button();
            panel2 = new Panel();
            pictureBox1 = new PictureBox();
            panel1 = new Panel();
            button4 = new Button();
            panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 14F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(589, 631);
            button2.Name = "button2";
            button2.Size = new Size(275, 49);
            button2.TabIndex = 1;
            button2.Text = "Submit Feedback";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // richTextBox1
            // 
            richTextBox1.Location = new Point(409, 280);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(675, 295);
            richTextBox1.TabIndex = 2;
            richTextBox1.Text = "";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Segoe UI", 14F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.White;
            label1.Location = new Point(409, 234);
            label1.Name = "label1";
            label1.Size = new Size(182, 32);
            label1.TabIndex = 3;
            label1.Text = "Enter Feedback:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 24F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(339, 35);
            label4.Name = "label4";
            label4.Size = new Size(293, 54);
            label4.TabIndex = 2;
            label4.Text = "Feedback Form";
            label4.Click += label4_Click;
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
            button7.Text = "View Labs";
            button7.TextImageRelation = TextImageRelation.ImageAboveText;
            button7.UseVisualStyleBackColor = false;
            button7.Click += button7_Click;
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
            panel2.Controls.Add(label4);
            panel2.Controls.Add(pictureBox1);
            panel2.Dock = DockStyle.Top;
            panel2.Location = new Point(250, 0);
            panel2.Name = "panel2";
            panel2.Size = new Size(1000, 125);
            panel2.TabIndex = 9;
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
            panel1.TabIndex = 8;
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
            // ld_GiveFeedBack
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
            Name = "ld_GiveFeedBack";
            Text = "ld_GiveFeedBack";
            panel2.ResumeLayout(false);
            panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            panel1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Button button2;
        private RichTextBox richTextBox1;
        private Label label1;
        private Label label4;
        private Button button7;
        private Button button6;
        private Panel panel2;
        private PictureBox pictureBox1;
        private Panel panel1;
        private Button button4;
    }
}