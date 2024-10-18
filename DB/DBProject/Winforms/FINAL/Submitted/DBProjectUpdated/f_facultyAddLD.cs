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
    public partial class f_facultyAddLD : Form
    {
        public f_facultyAddLD()
        {
            InitializeComponent();
        }

        private void f_facultyAddLD_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // SQL query to fetch course information
                string query = "SELECT courseID, facultyID, courseName FROM course";

                SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connection);

                DataTable dataTable = new DataTable();
                dataAdapter.Fill(dataTable);

                // Bind the DataTable to the DataGridView
                dataGridView1.DataSource = dataTable;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var username = textBox1.Text;
            var password = textBox2.Text;
            var email = textBox3.Text;
            var fullname = textBox4.Text;
            var address = textBox5.Text;
            var cnic = textBox6.Text;
            var dob = textBox7.Text; // Ensure this is in 'yyyy-MM-dd' format
            var gender = textBox8.Text;
            var contact = textBox9.Text;
            var coursename = textBox10.Text;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                   "Initial Catalog=DBProject;" +
                                   "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Retrieve courseID
                string courseIdQuery = "SELECT courseID FROM course WHERE courseName = @coursename";
                SqlCommand courseIdCommand = new SqlCommand(courseIdQuery, connection);
                courseIdCommand.Parameters.AddWithValue("@coursename", coursename);

                object courseIdResult = courseIdCommand.ExecuteScalar();

                if (courseIdResult != null)
                {
                    int courseID = Convert.ToInt32(courseIdResult);

                    // Insert into users
                    string userInsertQuery = "INSERT INTO users (userName, userPassword, userEmail, userRole) VALUES (@username, @password, @email, 'LD'); SELECT SCOPE_IDENTITY();";
                    SqlCommand userInsertCommand = new SqlCommand(userInsertQuery, connection);
                    userInsertCommand.Parameters.AddWithValue("@username", username);
                    userInsertCommand.Parameters.AddWithValue("@password", password);
                    userInsertCommand.Parameters.AddWithValue("@email", email);

                    int userID = Convert.ToInt32(userInsertCommand.ExecuteScalar());

                    // Insert into profile
                    string profileInsertQuery = "INSERT INTO profile (userID, profileName, profileAddress, profileCNIC, profileDOB, profileGender, profileContact) VALUES (@userID, @fullname, @address, @cnic, @dob, @gender, @contact)";
                    SqlCommand profileInsertCommand = new SqlCommand(profileInsertQuery, connection);
                    profileInsertCommand.Parameters.AddWithValue("@userID", userID);
                    profileInsertCommand.Parameters.AddWithValue("@fullname", fullname);
                    profileInsertCommand.Parameters.AddWithValue("@address", address);
                    profileInsertCommand.Parameters.AddWithValue("@cnic", cnic);
                    profileInsertCommand.Parameters.AddWithValue("@dob", Convert.ToDateTime(dob));
                    profileInsertCommand.Parameters.AddWithValue("@gender", gender);
                    profileInsertCommand.Parameters.AddWithValue("@contact", contact);

                    profileInsertCommand.ExecuteNonQuery();

                    // Insert into ld
                    string ldInsertQuery = "INSERT INTO ld (userID, courseID) VALUES (@userID, @courseID)";
                    SqlCommand ldInsertCommand = new SqlCommand(ldInsertQuery, connection);
                    ldInsertCommand.Parameters.AddWithValue("@userID", userID);
                    ldInsertCommand.Parameters.AddWithValue("@courseID", courseID);

                    ldInsertCommand.ExecuteNonQuery();

                    MessageBox.Show("New LD added successfully.");
                }
                else
                {
                    MessageBox.Show("Course not found.");
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            f_facultyViewLD obj = new f_facultyViewLD();
            obj.Show();
            this.Hide();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            f_facultyViewLD obj = new f_facultyViewLD();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            f_facultyfeedback obj = new f_facultyfeedback();
            obj.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            f_facultyTasks obj = new f_facultyTasks();
            obj.Show();
            this.Hide();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            f_facultyViewTA obj = new f_facultyViewTA();
            obj.Show();
            this.Hide();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            f_facultyViewLD obj = new f_facultyViewLD();
            obj.Show();
            this.Hide();
        }
    }
}
