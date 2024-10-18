namespace LAB10
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
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            usernametext = new TextBox();
            nametext = new TextBox();
            passwordtext = new TextBox();
            agetext = new TextBox();
            singuptext = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(181, 124);
            label1.Name = "label1";
            label1.Size = new Size(75, 20);
            label1.TabIndex = 0;
            label1.Text = "Username";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(181, 159);
            label2.Name = "label2";
            label2.Size = new Size(76, 20);
            label2.TabIndex = 1;
            label2.Text = "Full Name";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(181, 205);
            label3.Name = "label3";
            label3.Size = new Size(70, 20);
            label3.TabIndex = 2;
            label3.Text = "Password";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(181, 246);
            label4.Name = "label4";
            label4.Size = new Size(36, 20);
            label4.TabIndex = 3;
            label4.Text = "Age";
            // 
            // usernametext
            // 
            usernametext.Location = new Point(294, 121);
            usernametext.Name = "usernametext";
            usernametext.Size = new Size(125, 27);
            usernametext.TabIndex = 4;
            // 
            // nametext
            // 
            nametext.Location = new Point(294, 159);
            nametext.Name = "nametext";
            nametext.Size = new Size(125, 27);
            nametext.TabIndex = 5;
            // 
            // passwordtext
            // 
            passwordtext.Location = new Point(294, 202);
            passwordtext.Name = "passwordtext";
            passwordtext.Size = new Size(125, 27);
            passwordtext.TabIndex = 6;
            // 
            // agetext
            // 
            agetext.Location = new Point(294, 243);
            agetext.Name = "agetext";
            agetext.Size = new Size(125, 27);
            agetext.TabIndex = 7;
            // 
            // singuptext
            // 
            singuptext.Location = new Point(241, 320);
            singuptext.Name = "singuptext";
            singuptext.Size = new Size(94, 29);
            singuptext.TabIndex = 8;
            singuptext.Text = "Sign Up";
            singuptext.UseVisualStyleBackColor = true;
            singuptext.Click += singuptext_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(singuptext);
            Controls.Add(agetext);
            Controls.Add(passwordtext);
            Controls.Add(nametext);
            Controls.Add(usernametext);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "Form1";
            Text = "Username";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private TextBox usernametext;
        private TextBox nametext;
        private TextBox passwordtext;
        private TextBox agetext;
        private Button singuptext;
    }
}