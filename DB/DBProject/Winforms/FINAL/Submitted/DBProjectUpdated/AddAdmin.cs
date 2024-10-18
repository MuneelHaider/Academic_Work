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
    public partial class AddAdmin : Form
    {
        public AddAdmin()
        {
            InitializeComponent();
        }

        private void backbutton_Click(object sender, EventArgs e)
        {
            AdminMainPage obj = new AdminMainPage();
            obj.Show();
            this.Hide();
        }

        private void signupadminbutton_Click(object sender, EventArgs e)
        {
            var username = usernametxt.Text;
            var password = passwordtxt.Text;
            var email = emailtxt.Text;
            var fullname = fullnametxt.Text;
            var address = addresstxt.Text;
            var cnic = cnictxt.Text;
            var dob = dobtxt.Text;
            var gender = gendertxt.Text;
            var contact = contacttxt.Text;

            var connectionstring = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                   "Initial Catalog=DBProject;" +
                                   "Integrated Security=True;";

            if (email.EndsWith("@gmail.com") == true)
            {
                using (SqlConnection connection = new SqlConnection(connectionstring))
                {
                    connection.Open();

                    string query1 = "EXEC RegisterAdmin @userName = '" + username + "', @userPassword = '" + password + "', @userEmail = '" + email + "', @userRole = 'Admin', @profileName = '" + fullname + "', @profileAddress = '" + address + "', @profileCNIC = '" + cnic + "', @profileDOB = '" + dob + "', @profileGender = '" + gender + "', @profileContact = '" + contact + "';";

                    using (SqlCommand cmd1 = new SqlCommand(query1, connection))
                    {
                        var ifError = cmd1.ExecuteNonQuery();

                        if (ifError == 0)
                        {
                            MessageBox.Show("Error inserting new Admin.");
                        }
                        else
                        {
                            MessageBox.Show("Admin added successfully.");

                            AdminMainPage obj = new AdminMainPage();
                            obj.Show();
                            this.Hide();
                        }
                    }
                }
            }
            else
            {
                MessageBox.Show("Invalid email. Must end with @gmail.com.");
            }
        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            AdminMainPage obj = new AdminMainPage();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            AddAdmin obj = new AddAdmin();
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

        private void button5_Click(object sender, EventArgs e)
        {
            AdminUpdate obj = new AdminUpdate();
            obj.Show();
            this.Hide();
        }
    }
}
