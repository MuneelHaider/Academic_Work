using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace DBProject
{
    public partial class facultySignup : Form
    {
        public facultySignup()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void backbutton_Click(object sender, EventArgs e)
        {
            FacultyView obj = new FacultyView();
            obj.Show();
            this.Hide();
        }

        private void signupfaculty_Click(object sender, EventArgs e)
        {
            var username = usernametext.Text;
            var password = passtext.Text;
            var email = emailtext.Text;
            var role = "Faculty";
            var fullname = fullnametext.Text;
            var address = addresstxt.Text;
            var cnic = cnictxt.Text;
            var dob = dobtxt.Text; // Ensure this is in 'yyyy-MM-dd' format
            var gender = gendertxt.Text;
            var contact = contacttxt.Text;
            var department = departmenttxt.Text;
            var office = officetxt.Text;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                   "Initial Catalog=DBProject;" +
                                   "Integrated Security=True;";

            if (email.EndsWith("@gmail.com"))
            {
                using (SqlConnection connection = new SqlConnection(connectionString))
                {
                    connection.Open();

                    SqlCommand command = new SqlCommand("InsertFaculty", connection);
                    command.CommandType = CommandType.StoredProcedure;

                    command.Parameters.AddWithValue("@userName", usernametext.Text);
                    command.Parameters.AddWithValue("@userPassword", passtext.Text);
                    command.Parameters.AddWithValue("@userEmail", emailtext.Text);
                    command.Parameters.AddWithValue("@userRole", "Faculty"); // Assuming the role is always 'Faculty'
                    command.Parameters.AddWithValue("@profileName", fullnametext.Text);
                    command.Parameters.AddWithValue("@profileAddress", addresstxt.Text);
                    command.Parameters.AddWithValue("@profileCNIC", cnictxt.Text);
                    command.Parameters.AddWithValue("@profileDOB", dobtxt.Text); // Ensure correct format
                    command.Parameters.AddWithValue("@profileGender", gendertxt.Text);
                    command.Parameters.AddWithValue("@profileContact", contacttxt.Text);
                    command.Parameters.AddWithValue("@facultyDepartment", departmenttxt.Text);
                    command.Parameters.AddWithValue("@facultyOffice", officetxt.Text);

                    command.ExecuteNonQuery();

                    MessageBox.Show("Faculty member added successfully.");

                    FacultyView obj = new FacultyView();
                    obj.Show();
                    this.Hide();
                }
            }
            else
            {
                MessageBox.Show("Invalid email. Must end with @gmail.com");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            FacultyView obj = new FacultyView();
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
