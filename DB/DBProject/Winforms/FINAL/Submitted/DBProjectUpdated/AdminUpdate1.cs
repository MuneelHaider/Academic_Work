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
    public partial class AdminUpdate1 : Form
    {
        public AdminUpdate1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var username = usernametxt.Text;
            var oldpassword = oldpasswordtxt.Text;
            var newpassword = newpasswordtxt.Text;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                   "Initial Catalog=DBProject;" +
                                   "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string queryVerify = "SELECT COUNT(1) FROM users WHERE userName = '" + username + "' AND userPassword = '" + oldpassword + "'";

                SqlCommand cmdVerify = new SqlCommand(queryVerify, connection);

                int count = Convert.ToInt32(cmdVerify.ExecuteScalar());

                if (count == 1)
                {

                    string queryUpdate = "UPDATE users SET userPassword = '" + newpassword + "' WHERE userName = '" + username + "'";

                    SqlCommand cmdUpdate = new SqlCommand(queryUpdate, connection);

                    cmdUpdate.ExecuteNonQuery();

                    MessageBox.Show("Username and password updated successfully.");

                    AdminMainPage obj = new AdminMainPage();
                    obj.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("Old password does not match.");
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            AdminUpdate obj = new AdminUpdate();
            obj.Show();
            this.Hide();
        }

        private void AdminUpdate1_Load(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
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
