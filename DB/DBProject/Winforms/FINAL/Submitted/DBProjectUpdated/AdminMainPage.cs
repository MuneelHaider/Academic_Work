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
    public partial class AdminMainPage : Form
    {
        public AdminMainPage()
        {
            InitializeComponent();
        }

        private void backButon_Click(object sender, EventArgs e)
        {
            start obj = new start();
            obj.Show();
            this.Hide();
        }

        private void newadminbutton_Click(object sender, EventArgs e)
        {
            AddAdmin obj = new AddAdmin();
            obj.Show();
            this.Hide();
        }

        private void updateadmindetailsbutton_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            AdminUpdate obj = new AdminUpdate();
            obj.Show();
            this.Hide();
        }

        private void newfacultybutton_Click(object sender, EventArgs e)
        {

        }

        private void viewfacultybutton_Click(object sender, EventArgs e)
        {
            FacultyView obj = new FacultyView();
            obj.Show();
            this.Hide();
        }

        private void viewtabutton_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            AdminViewCourses obj = new AdminViewCourses();
            obj.Show();
            this.Hide();
        }

        private void AdminMainPage_Load(object sender, EventArgs e)
        {
            var username = globalVar.GlobalVariables.globalstring;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // SQL query to fetch admin information without password
                string query = @"
                                SELECT u.userName, u.userEmail, u.userRole, p.profileName, p.profileAddress, p.profileCNIC, p.profileDOB, p.profileGender, p.profileContact
                                FROM users u
                                INNER JOIN profile p ON u.userID = p.userID
                                WHERE u.userName = @username AND u.userRole = 'Admin'";

                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@username", username);

                using (SqlDataReader reader = command.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        textBox1.Text = reader.GetString(0); // userName
                        textBox2.Text = reader.GetString(1); // userEmail
                        textBox3.Text = reader.GetString(2); // userRole
                        textBox4.Text = reader.GetString(3); // profileName
                        textBox5.Text = reader.GetString(4); // profileAddress
                        textBox6.Text = reader.GetString(5); // profileCNIC
                        textBox7.Text = reader.GetDateTime(6).ToString("yyyy-MM-dd"); // profileDOB
                        textBox8.Text = reader.GetString(7); // profileGender
                        textBox9.Text = reader.GetString(8); // profileContact
                    }
                    else
                    {
                        MessageBox.Show("Admin not found.");
                    }
                }
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            start obj = new start();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            AddAdmin obj = new AddAdmin();
            obj.Show();
            this.Hide();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            AdminUpdate obj = new AdminUpdate();
            obj.Show();
            this.Hide();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            FacultyView obj = new FacultyView();
            obj.Show();
            this.Hide();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            AdminViewCourses obj = new AdminViewCourses();
            obj.Show();
            this.Hide();
        }
    }
}
