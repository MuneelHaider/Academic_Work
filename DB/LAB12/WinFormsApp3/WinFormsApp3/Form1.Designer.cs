namespace WinFormsApp3
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            Usernametext = new TextBox();
            passwordtext = new TextBox();
            agetext = new TextBox();
            fnametext = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            button1 = new Button();
            SuspendLayout();
            // 
            // Usernametext
            // 
            Usernametext.Font = new Font("Segoe UI Semibold", 9F, FontStyle.Bold, GraphicsUnit.Point);
            Usernametext.Location = new Point(237, 112);
            Usernametext.Name = "Usernametext";
            Usernametext.Size = new Size(241, 23);
            Usernametext.TabIndex = 0;
            // 
            // passwordtext
            // 
            passwordtext.Font = new Font("Segoe UI Semibold", 9F, FontStyle.Bold, GraphicsUnit.Point);
            passwordtext.Location = new Point(237, 193);
            passwordtext.Name = "passwordtext";
            passwordtext.Size = new Size(241, 23);
            passwordtext.TabIndex = 1;
            // 
            // agetext
            // 
            agetext.Font = new Font("Segoe UI Semibold", 9F, FontStyle.Bold, GraphicsUnit.Point);
            agetext.Location = new Point(237, 237);
            agetext.Name = "agetext";
            agetext.Size = new Size(241, 23);
            agetext.TabIndex = 2;
            // 
            // fnametext
            // 
            fnametext.Font = new Font("Segoe UI Semibold", 9F, FontStyle.Bold, GraphicsUnit.Point);
            fnametext.Location = new Point(237, 153);
            fnametext.Name = "fnametext";
            fnametext.Size = new Size(241, 23);
            fnametext.TabIndex = 3;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(123, 120);
            label1.Name = "label1";
            label1.Size = new Size(66, 15);
            label1.TabIndex = 4;
            label1.Text = "Username :";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(123, 161);
            label2.Name = "label2";
            label2.Size = new Size(67, 15);
            label2.TabIndex = 5;
            label2.Text = "Full Name :";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(123, 201);
            label3.Name = "label3";
            label3.Size = new Size(63, 15);
            label3.TabIndex = 6;
            label3.Text = "Password :";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(123, 245);
            label4.Name = "label4";
            label4.Size = new Size(34, 15);
            label4.TabIndex = 7;
            label4.Text = "Age :";
            // 
            // button1
            // 
            button1.Location = new Point(275, 301);
            button1.Name = "button1";
            button1.Size = new Size(143, 33);
            button1.TabIndex = 8;
            button1.Text = "SignUp";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(button1);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(fnametext);
            Controls.Add(agetext);
            Controls.Add(passwordtext);
            Controls.Add(Usernametext);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox Usernametext;
        private TextBox passwordtext;
        private TextBox agetext;
        private TextBox fnametext;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Button button1;
    }
}