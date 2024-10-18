namespace DBProject
{
    partial class AdminViewCourses
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AdminViewCourses));
            button2 = new Button();
            button3 = new Button();
            dataGridView1 = new DataGridView();
            panel1 = new Panel();
            button7 = new Button();
            button1 = new Button();
            button6 = new Button();
            button4 = new Button();
            button5 = new Button();
            panel2 = new Panel();
            pictureBox1 = new PictureBox();
            label12 = new Label();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).BeginInit();
            panel1.SuspendLayout();
            panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(425, 300);
            button2.Name = "button2";
            button2.Size = new Size(182, 39);
            button2.TabIndex = 1;
            button2.Text = "Add New Course";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            button3.Location = new Point(425, 449);
            button3.Name = "button3";
            button3.Size = new Size(182, 39);
            button3.TabIndex = 2;
            button3.Text = "Remove Course";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // dataGridView1
            // 
            dataGridView1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView1.Location = new Point(738, 300);
            dataGridView1.Name = "dataGridView1";
            dataGridView1.RowHeadersWidth = 51;
            dataGridView1.RowTemplate.Height = 29;
            dataGridView1.Size = new Size(300, 188);
            dataGridView1.TabIndex = 3;
            // 
            // panel1
            // 
            panel1.BackColor = Color.FromArgb(64, 64, 64);
            panel1.Controls.Add(button7);
            panel1.Controls.Add(button1);
            panel1.Controls.Add(button6);
            panel1.Controls.Add(button4);
            panel1.Controls.Add(button5);
            panel1.Dock = DockStyle.Left;
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(250, 804);
            panel1.TabIndex = 9;
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
            // button1
            // 
            button1.BackColor = Color.FromArgb(64, 64, 64);
            button1.Image = (Image)resources.GetObject("button1.Image");
            button1.Location = new Point(12, 12);
            button1.Name = "button1";
            button1.Size = new Size(62, 29);
            button1.TabIndex = 7;
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click_1;
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
            panel2.Controls.Add(pictureBox1);
            panel2.Controls.Add(label12);
            panel2.Dock = DockStyle.Top;
            panel2.Location = new Point(250, 0);
            panel2.Name = "panel2";
            panel2.Size = new Size(1000, 125);
            panel2.TabIndex = 24;
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.Transparent;
            pictureBox1.BackgroundImage = (Image)resources.GetObject("pictureBox1.BackgroundImage");
            pictureBox1.Location = new Point(883, 3);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(114, 122);
            pictureBox1.TabIndex = 7;
            pictureBox1.TabStop = false;
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Font = new Font("Segoe UI", 24F, FontStyle.Regular, GraphicsUnit.Point);
            label12.Location = new Point(331, 30);
            label12.Name = "label12";
            label12.Size = new Size(259, 54);
            label12.TabIndex = 8;
            label12.Text = "View Courses";
            // 
            // AdminViewCourses
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(1250, 804);
            Controls.Add(panel2);
            Controls.Add(panel1);
            Controls.Add(dataGridView1);
            Controls.Add(button3);
            Controls.Add(button2);
            Name = "AdminViewCourses";
            Text = "AdminViewCourses";
            Load += AdminViewCourses_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridView1).EndInit();
            panel1.ResumeLayout(false);
            panel2.ResumeLayout(false);
            panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
        }

        #endregion
        private Button button2;
        private Button button3;
        private DataGridView dataGridView1;
        private Panel panel1;
        private Button button7;
        private Button button1;
        private Button button6;
        private Button button4;
        private Button button5;
        private Panel panel2;
        private PictureBox pictureBox1;
        private Label label12;
    }
}