namespace DBProject
{
    partial class f_facultyViewLD
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(f_facultyViewLD));
            dataGridView1 = new DataGridView();
            button2 = new Button();
            button3 = new Button();
            panel1 = new Panel();
            pictureBox2 = new PictureBox();
            pictureBox1 = new PictureBox();
            label11 = new Label();
            button4 = new Button();
            button5 = new Button();
            button6 = new Button();
            button7 = new Button();
            button8 = new Button();
            panel2 = new Panel();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).BeginInit();
            panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            panel2.SuspendLayout();
            SuspendLayout();
            // 
            // dataGridView1
            // 
            dataGridView1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView1.Location = new Point(691, 346);
            dataGridView1.Name = "dataGridView1";
            dataGridView1.RowHeadersWidth = 51;
            dataGridView1.RowTemplate.Height = 29;
            dataGridView1.Size = new Size(364, 219);
            dataGridView1.TabIndex = 1;
            dataGridView1.CellContentClick += dataGridView1_CellContentClick;
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 14F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(404, 368);
            button2.Name = "button2";
            button2.Size = new Size(196, 49);
            button2.TabIndex = 2;
            button2.Text = "Add New LD";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Font = new Font("Segoe UI", 14F, FontStyle.Regular, GraphicsUnit.Point);
            button3.Location = new Point(418, 457);
            button3.Name = "button3";
            button3.Size = new Size(169, 49);
            button3.TabIndex = 3;
            button3.Text = "Remove LD";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
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
            panel1.TabIndex = 34;
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
            label11.Location = new Point(259, 39);
            label11.Name = "label11";
            label11.Size = new Size(407, 50);
            label11.TabIndex = 30;
            label11.Text = "View Lab Demonstrator";
            // 
            // button4
            // 
            button4.BackColor = Color.FromArgb(64, 64, 64);
            button4.Image = (Image)resources.GetObject("button4.Image");
            button4.Location = new Point(12, 12);
            button4.Name = "button4";
            button4.Size = new Size(62, 29);
            button4.TabIndex = 8;
            button4.UseVisualStyleBackColor = false;
            button4.Click += button4_Click;
            // 
            // button5
            // 
            button5.FlatStyle = FlatStyle.Flat;
            button5.ForeColor = SystemColors.ActiveCaptionText;
            button5.Image = (Image)resources.GetObject("button5.Image");
            button5.Location = new Point(0, 121);
            button5.Name = "button5";
            button5.Size = new Size(250, 102);
            button5.TabIndex = 3;
            button5.Text = "View Feedback";
            button5.TextImageRelation = TextImageRelation.ImageAboveText;
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button6
            // 
            button6.FlatStyle = FlatStyle.Flat;
            button6.Image = (Image)resources.GetObject("button6.Image");
            button6.Location = new Point(0, 221);
            button6.Name = "button6";
            button6.Size = new Size(250, 102);
            button6.TabIndex = 4;
            button6.Text = "View Tasks Assigned";
            button6.TextImageRelation = TextImageRelation.ImageAboveText;
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // button7
            // 
            button7.FlatStyle = FlatStyle.Flat;
            button7.Image = (Image)resources.GetObject("button7.Image");
            button7.Location = new Point(-3, 410);
            button7.Name = "button7";
            button7.Size = new Size(253, 102);
            button7.TabIndex = 6;
            button7.Text = "View TA's";
            button7.TextImageRelation = TextImageRelation.ImageAboveText;
            button7.UseVisualStyleBackColor = true;
            button7.Click += button7_Click;
            // 
            // button8
            // 
            button8.FlatStyle = FlatStyle.Flat;
            button8.Image = (Image)resources.GetObject("button8.Image");
            button8.Location = new Point(0, 508);
            button8.Name = "button8";
            button8.Size = new Size(250, 102);
            button8.TabIndex = 7;
            button8.Text = "View LD's";
            button8.TextImageRelation = TextImageRelation.ImageAboveText;
            button8.UseVisualStyleBackColor = true;
            button8.Click += button8_Click;
            // 
            // panel2
            // 
            panel2.BackColor = Color.FromArgb(64, 64, 64);
            panel2.Controls.Add(button4);
            panel2.Controls.Add(button5);
            panel2.Controls.Add(button6);
            panel2.Controls.Add(button7);
            panel2.Controls.Add(button8);
            panel2.Dock = DockStyle.Left;
            panel2.Location = new Point(0, 0);
            panel2.Name = "panel2";
            panel2.Size = new Size(250, 804);
            panel2.TabIndex = 35;
            // 
            // f_facultyViewLD
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(1250, 804);
            Controls.Add(panel1);
            Controls.Add(panel2);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(dataGridView1);
            Name = "f_facultyViewLD";
            Text = "f_facultyViewLD";
            Load += f_facultyViewLD_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridView1).EndInit();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            panel2.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion
        private DataGridView dataGridView1;
        private Button button2;
        private Button button3;
        private Panel panel1;
        private PictureBox pictureBox2;
        private PictureBox pictureBox1;
        private Label label11;
        private Button button4;
        private Button button5;
        private Button button6;
        private Button button7;
        private Button button8;
        private Panel panel2;
    }
}