using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DBProject
{
    public partial class ld_Mainpage : Form
    {
        public ld_Mainpage()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            start obj = new start();
            obj.Show();
            this.Hide();
        }

        private void ld_Mainpage_Load(object sender, EventArgs e)
        {
            var username = globalVar.GlobalVariables.globalstring;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {

                connection.Open();

                // SQL query to fetch LD information based on the username
                string query = @"
            SELECT u.userName, u.userEmail, u.userRole, p.profileName, p.profileAddress, 
                    p.profileCNIC, p.profileDOB, p.profileGender, p.profileContact, c.courseName
            FROM users u
            INNER JOIN profile p ON u.userID = p.userID
            INNER JOIN ld ON u.userID = ld.userID
            INNER JOIN course c ON ld.courseID = c.courseID
            WHERE u.userName = @username AND u.userRole = 'LD'"; // Assuming 'LD' is the role for Lab Details

                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@username", username);

                using (SqlDataReader reader = command.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        // Assuming textBoxes1, textBoxes2, ... follow the order of username, email, etc.
                        textBox1.Text = reader.GetString(0); // Username
                        textBox2.Text = reader.GetString(1); // Email
                        textBox3.Text = reader.GetString(2); // Role
                        textBox4.Text = reader.GetString(3); // Fullname
                        textBox5.Text = reader.GetString(4); // Address
                        textBox6.Text = reader.GetString(5); // CNIC
                        textBox7.Text = reader.GetDateTime(6).ToString("yyyy-MM-dd"); // DOB
                        textBox8.Text = reader.GetString(7); // Gender
                        textBox9.Text = reader.GetString(8); // Contact
                        textBox10.Text = reader.GetString(9); // Course Name
                    }
                    else
                    {
                        MessageBox.Show("LD details not found.");
                    }
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ld_GiveFeedBack obj = new ld_GiveFeedBack();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            ld_SeeTasks obj = new ld_SeeTasks();
            obj.Show();
            this.Hide();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            ld_GiveFeedBack obj = new ld_GiveFeedBack();
            obj.Show();
            this.Hide();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            ld_SeeTasks obj = new ld_SeeTasks();
            obj.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            start obj = new start();
            obj.Show();
            this.Hide();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {
        }

        private void label11_Click(object sender, EventArgs e)
        {
        }
    }
}
