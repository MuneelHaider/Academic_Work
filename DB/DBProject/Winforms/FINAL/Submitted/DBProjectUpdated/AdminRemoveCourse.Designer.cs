namespace DBProject
{
    partial class AdminRemoveCourse
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AdminRemoveCourse));
            button1 = new Button();
            dataGridView1 = new DataGridView();
            label1 = new Label();
            label2 = new Label();
            textBox1 = new TextBox();
            button2 = new Button();
            panel1 = new Panel();
            button7 = new Button();
            button6 = new Button();
            button3 = new Button();
            button5 = new Button();
            panel2 = new Panel();
            label4 = new Label();
            pictureBox1 = new PictureBox();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).BeginInit();
            panel1.SuspendLayout();
            panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // button1
            // 
            button1.BackColor = Color.FromArgb(64, 64, 64);
            button1.Image = (Image)resources.GetObject("button1.Image");
            button1.Location = new Point(42, 31);
            button1.Name = "button1";
            button1.Size = new Size(61, 29);
            button1.TabIndex = 0;
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // dataGridView1
            // 
            dataGridView1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView1.Location = new Point(787, 302);
            dataGridView1.Name = "dataGridView1";
            dataGridView1.RowHeadersWidth = 51;
            dataGridView1.RowTemplate.Height = 29;
            dataGridView1.Size = new Size(391, 221);
            dataGridView1.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.Transparent;
            label1.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label1.ForeColor = Color.White;
            label1.Location = new Point(301, 302);
            label1.Name = "label1";
            label1.Size = new Size(390, 31);
            label1.TabIndex = 2;
            label1.Text = "Which course do you want to delete?";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.BackColor = Color.Transparent;
            label2.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            label2.ForeColor = Color.White;
            label2.Location = new Point(301, 369);
            label2.Name = "label2";
            label2.Size = new Size(156, 31);
            label2.TabIndex = 3;
            label2.Text = "Course Name:";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(481, 373);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(229, 27);
            textBox1.TabIndex = 4;
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 13.8F, FontStyle.Regular, GraphicsUnit.Point);
            button2.Location = new Point(432, 486);
            button2.Name = "button2";
            button2.Size = new Size(181, 60);
            button2.TabIndex = 5;
            button2.Text = "Remove Course";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // panel1
            // 
            panel1.BackColor = Color.FromArgb(64, 64, 64);
            panel1.Controls.Add(button7);
            panel1.Controls.Add(button1);
            panel1.Controls.Add(button6);
            panel1.Controls.Add(button3);
            panel1.Controls.Add(button5);
            panel1.Dock = DockStyle.Left;
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(250, 804);
            panel1.TabIndex = 6;
            // 
            // button7
            // 
            button7.BackColor = Color.FromArgb(64, 64, 64);
            button7.Cursor = Cursors.Hand;
            button7.Image = (Image)resources.GetObject("button7.Image");
            button7.Location = new Point(-3, 506);
            button7.Name = "button7";
            button7.Size = new Size(250, 135);
            button7.TabIndex = 11;
            button7.Text = "View Courses";
            button7.TextImageRelation = TextImageRelation.ImageAboveText;
            button7.UseVisualStyleBackColor = false;
            button7.Click += button7_Click_1;
            // 
            // button6
            // 
            button6.BackColor = Color.FromArgb(64, 64, 64);
            button6.Cursor = Cursors.Hand;
            button6.Image = (Image)resources.GetObject("button6.Image");
            button6.Location = new Point(-3, 380);
            button6.Name = "button6";
            button6.Size = new Size(250, 135);
            button6.TabIndex = 10;
            button6.Text = "View Faculty";
            button6.TextImageRelation = TextImageRelation.ImageAboveText;
            button6.UseVisualStyleBackColor = false;
            button6.Click += button6_Click;
            // 
            // button3
            // 
            button3.BackColor = Color.FromArgb(64, 64, 64);
            button3.Cursor = Cursors.Hand;
            button3.Image = (Image)resources.GetObject("button3.Image");
            button3.Location = new Point(-3, 120);
            button3.Name = "button3";
            button3.Size = new Size(250, 135);
            button3.TabIndex = 8;
            button3.Text = "Add New Admin";
            button3.TextImageRelation = TextImageRelation.ImageAboveText;
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click_1;
            // 
            // button5
            // 
            button5.BackColor = Color.FromArgb(64, 64, 64);
            button5.Cursor = Cursors.Hand;
            button5.Image = (Image)resources.GetObject("button5.Image");
            button5.Location = new Point(-3, 253);
            button5.Name = "button5";
            button5.Size = new Size(250, 135);
            button5.TabIndex = 9;
            button5.Text = "View Admins";
            button5.TextImageRelation = TextImageRelation.ImageAboveText;
            button5.UseVisualStyleBackColor = false;
            button5.Click += button5_Click_1;
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
            panel2.TabIndex = 7;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 24F, FontStyle.Regular, GraphicsUnit.Point);
            label4.Location = new Point(339, 35);
            label4.Name = "label4";
            label4.Size = new Size(298, 54);
            label4.TabIndex = 2;
            label4.Text = "Remove Course";
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
            // AdminRemoveCourse
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(1250, 804);
            Controls.Add(panel2);
            Controls.Add(panel1);
            Controls.Add(button2);
            Controls.Add(textBox1);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(dataGridView1);
            Name = "AdminRemoveCourse";
            Text = "AdminRemoveCourse";
            Load += AdminRemoveCourse_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridView1).EndInit();
            panel1.ResumeLayout(false);
            panel2.ResumeLayout(false);
            panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private DataGridView dataGridView1;
        private Label label1;
        private Label label2;
        private TextBox textBox1;
        private Button button2;
        private Panel panel1;
        private Panel panel2;
        private PictureBox pictureBox1;
        private Label label4;
        private Button button7;
        private Button button6;
        private Button button3;
        private Button button5;
    }
}