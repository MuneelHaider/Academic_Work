namespace DBProject
{
    partial class f_facultyRemoveTA
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(f_facultyRemoveTA));
            dataGridView1 = new DataGridView();
            label1 = new Label();
            label2 = new Label();
            textBox1 = new TextBox();
            button2 = new Button();
            pictureBox2 = new PictureBox();
            button3 = new Button();
            button4 = new Button();
            button5 = new Button();
            button6 = new Button();
            button7 = new Button();
            panel1 = new Panel();
            pictureBox1 = new PictureBox();
            label11 = new Label();
            panel2 = new Panel();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).BeginInit();
            panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            panel2.SuspendLayout();
            SuspendLayout();
            // 
            // dataGridView1
            // 
            dataGridView1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView1.Location = new Point(764, 326);
            dataGridView1.Name = "dataGridView1";
            dataGridView1.RowHeadersWidth = 51;
            dataGridView1.RowTemplate.Height = 29;
            dataGridView1.Size = new Size(378, 232);
            dataGridView1.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.White;
            label1.Location = new Point(415, 326);
            label1.Name = "label1";
            label1.Size = new Size(312, 31);
            label1.TabIndex = 2;
            label1.Text = "Who do you want to remove?";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Transparent;
            label2.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label2.ForeColor = Color.White;
            label2.Location = new Point(415, 391);
            label2.Name = "label2";
            label2.Size = new Size(122, 31);
            label2.TabIndex = 3;
            label2.Text = "Username:";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(543, 395);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(184, 27);
            textBox1.TabIndex = 4;
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(510, 513);
            button2.Name = "button2";
            button2.Size = new Size(153, 45);
            button2.TabIndex = 5;
            button2.Text = "Remove TA";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // pictureBox2
            // 
            pictureBox2.BackColor = Color.Transparent;
            pictureBox2.BackgroundImage = (Image)resources.GetObject("pictureBox2.BackgroundImage");
            pictureBox2.Location = new Point(886, 3);
            pictureBox2.Name = "pictureBox2";
            pictureBox2.Size = new Size(114, 122);
            pictureBox2.TabIndex = 32;
            pictureBox2.TabStop = false;
            // 
            // button3
            // 
            button3.BackColor = Color.FromArgb(64, 64, 64);
            button3.Image = (Image)resources.GetObject("button3.Image");
            button3.Location = new Point(12, 12);
            button3.Name = "button3";
            button3.Size = new Size(62, 29);
            button3.TabIndex = 8;
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // button4
            // 
            button4.FlatStyle = FlatStyle.Flat;
            button4.ForeColor = SystemColors.ActiveCaptionText;
            button4.Image = (Image)resources.GetObject("button4.Image");
            button4.Location = new Point(0, 121);
            button4.Name = "button4";
            button4.Size = new Size(250, 102);
            button4.TabIndex = 3;
            button4.Text = "View Feedback";
            button4.TextImageRelation = TextImageRelation.ImageAboveText;
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // button5
            // 
            button5.FlatStyle = FlatStyle.Flat;
            button5.Image = (Image)resources.GetObject("button5.Image");
            button5.Location = new Point(0, 221);
            button5.Name = "button5";
            button5.Size = new Size(250, 102);
            button5.TabIndex = 4;
            button5.Text = "View Tasks Assigned";
            button5.TextImageRelation = TextImageRelation.ImageAboveText;
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button6
            // 
            button6.FlatStyle = FlatStyle.Flat;
            button6.Image = (Image)resources.GetObject("button6.Image");
            button6.Location = new Point(-3, 410);
            button6.Name = "button6";
            button6.Size = new Size(253, 102);
            button6.TabIndex = 6;
            button6.Text = "View TA's";
            button6.TextImageRelation = TextImageRelation.ImageAboveText;
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // button7
            // 
            button7.FlatStyle = FlatStyle.Flat;
            button7.Image = (Image)resources.GetObject("button7.Image");
            button7.Location = new Point(0, 508);
            button7.Name = "button7";
            button7.Size = new Size(250, 102);
            button7.TabIndex = 7;
            button7.Text = "View LD's";
            button7.TextImageRelation = TextImageRelation.ImageAboveText;
            button7.UseVisualStyleBackColor = true;
            button7.Click += button7_Click;
            // 
            // panel1
            // 
            panel1.BackColor = Color.FromArgb(64, 64, 64);
            panel1.Controls.Add(pictureBox2);
            panel1.Controls.Add(pictureBox1);
            panel1.Controls.Add(label11);
            panel1.Dock = DockStyle.Top;
            panel1.Location = new Point(250, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(1000, 125);
            panel1.TabIndex = 32;
            // 
            // pictureBox1
            // 
            pictureBox1.BackColor = Color.Transparent;
            pictureBox1.BackgroundImage = (Image)resources.GetObject("pictureBox1.BackgroundImage");
            pictureBox1.Location = new Point(1136, 0);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(114, 122);
            pictureBox1.TabIndex = 32;
            pictureBox1.TabStop = false;
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Font = new Font("Segoe UI", 22.2F, FontStyle.Regular, GraphicsUnit.Point);
            label11.Location = new Point(241, 48);
            label11.Name = "label11";
            label11.Size = new Size(443, 50);
            label11.TabIndex = 30;
            label11.Text = "Remove Teacher Assistant";
            // 
            // panel2
            // 
            panel2.BackColor = Color.FromArgb(64, 64, 64);
            panel2.Controls.Add(button3);
            panel2.Controls.Add(button4);
            panel2.Controls.Add(button5);
            panel2.Controls.Add(button6);
            panel2.Controls.Add(button7);
            panel2.Dock = DockStyle.Left;
            panel2.Location = new Point(0, 0);
            panel2.Name = "panel2";
            panel2.Size = new Size(250, 804);
            panel2.TabIndex = 33;
            // 
            // f_facultyRemoveTA
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(1250, 804);
            Controls.Add(panel1);
            Controls.Add(panel2);
            Controls.Add(button2);
            Controls.Add(textBox1);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(dataGridView1);
            Name = "f_facultyRemoveTA";
            Text = "f_facultyRemoveTA";
            Load += f_facultyRemoveTA_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridView1).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).EndInit();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            panel2.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private DataGridView dataGridView1;
        private Label label1;
        private Label label2;
        private TextBox textBox1;
        private Button button2;
        private PictureBox pictureBox2;
        private Button button3;
        private Button button4;
        private Button button5;
        private Button button6;
        private Button button7;
        private Panel panel1;
        private PictureBox pictureBox1;
        private Label label11;
        private Panel panel2;
    }
}