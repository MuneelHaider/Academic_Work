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
    public partial class AdminUpdate2 : Form
    {
        public AdminUpdate2()
        {
            InitializeComponent();
        }

        private void AdminUpdate2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            AdminUpdate1 obj = new AdminUpdate1();
            obj.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
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

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                   "Initial Catalog=DBProject;" +
                                   "Integrated Security=True;";

            if (email.EndsWith("@gmail.com") == true)
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    string queryUpdateUser = "UPDATE users SET userPassword = @password, userEmail = @email WHERE userName = @username";

                    SqlCommand commandUpdateUser = new SqlCommand(queryUpdateUser, connection);

                    commandUpdateUser.Parameters.AddWithValue("@username", username);
                    commandUpdateUser.Parameters.AddWithValue("@password", password);
                    commandUpdateUser.Parameters.AddWithValue("@email", email);
                    commandUpdateUser.ExecuteNonQuery();

                    string queryGetUserID = "SELECT userID FROM users WHERE userName = @username";

                    SqlCommand commandGetUserID = new SqlCommand(queryGetUserID, connection);

                    commandGetUserID.Parameters.AddWithValue("@username", username);

                    int userID = Convert.ToInt32(commandGetUserID.ExecuteScalar());

                    string queryUpdateProfile = "UPDATE profile SET profileName = @fullname, profileAddress = @address, profileCNIC = @cnic, profileDOB = @dob, profileGender = @gender, profileContact = @contact WHERE userID = @userID";

                    SqlCommand commandUpdateProfile = new SqlCommand(queryUpdateProfile, connection);

                    commandUpdateProfile.Parameters.AddWithValue("@fullname", fullname);
                    commandUpdateProfile.Parameters.AddWithValue("@address", address);
                    commandUpdateProfile.Parameters.AddWithValue("@cnic", cnic);
                    commandUpdateProfile.Parameters.AddWithValue("@dob", dob);
                    commandUpdateProfile.Parameters.AddWithValue("@gender", gender);
                    commandUpdateProfile.Parameters.AddWithValue("@contact", contact);
                    commandUpdateProfile.Parameters.AddWithValue("@userID", userID);
                    commandUpdateProfile.ExecuteNonQuery();

                    MessageBox.Show("Admin details updated successfully.");

                    AdminMainPage obj = new AdminMainPage();
                    obj.Show();
                    this.Hide();
                }
            }
            else
            {
                MessageBox.Show("Invalid email. Must end with @gmail.com");
            }
        }

        private void contacttxt_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            AdminUpdate obj = new AdminUpdate();
            obj.Show();
            this.Hide();
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
