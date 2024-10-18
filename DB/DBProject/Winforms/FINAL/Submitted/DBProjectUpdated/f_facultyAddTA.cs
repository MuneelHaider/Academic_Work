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
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace DBProject
{
    public partial class f_facultyAddTA : Form
    {
        public f_facultyAddTA()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            f_facultyViewTA obj = new f_facultyViewTA();
            obj.Show();
            this.Hide();
        }

        private void f_facultyAddTA_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string query = @"
                                SELECT c.courseName, u.userName AS 'FacultyName'
                                FROM course c
                                INNER JOIN faculty f ON c.facultyID = f.facultyID
                                INNER JOIN users u ON f.userID = u.userID";

                SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connection);

                DataTable dataTable = new DataTable();
                dataAdapter.Fill(dataTable);

                dataGridView1.DataSource = dataTable;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var username = textBox1.Text;
            var password = textBox2.Text;
            var email = textBox3.Text;
            var role = "TA";
            var fullname = textBox4.Text;
            var address = textBox5.Text;
            var cnic = textBox6.Text;
            var dob = textBox7.Text;
            var gender = textBox8.Text;
            var contact = textBox9.Text;
            var coursename = textBox10.Text;
            var avail = textBox11.Text;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string courseQuery = "SELECT courseID FROM course WHERE courseName = @courseName";

                SqlCommand courseCommand = new SqlCommand(courseQuery, connection);

                courseCommand.Parameters.AddWithValue("@courseName", coursename);
                object courseResult = courseCommand.ExecuteScalar();

                if (courseResult == null || courseResult == DBNull.Value)
                {
                    MessageBox.Show("Course not found.");
                    return;
                }

                int courseID = Convert.ToInt32(courseResult);

                string userQuery = "INSERT INTO users (userName, userPassword, userEmail, userRole) VALUES (@userName, @password, @email, @role); SELECT SCOPE_IDENTITY();";
                SqlCommand userCommand = new SqlCommand(userQuery, connection);

                userCommand.Parameters.AddWithValue("@userName", username);
                userCommand.Parameters.AddWithValue("@password", password);
                userCommand.Parameters.AddWithValue("@email", email);
                userCommand.Parameters.AddWithValue("@role", role);

                int userID = Convert.ToInt32(userCommand.ExecuteScalar());

                string profileQuery = "INSERT INTO profile (userID, profileName, profileAddress, profileCNIC, profileDOB, profileGender, profileContact) VALUES (@userID, @profileName, @profileAddress, @profileCNIC, @profileDOB, @profileGender, @profileContact)";

                SqlCommand profileCommand = new SqlCommand(profileQuery, connection);

                profileCommand.Parameters.AddWithValue("@userID", userID);
                profileCommand.Parameters.AddWithValue("@profileName", fullname);
                profileCommand.Parameters.AddWithValue("@profileAddress", address);
                profileCommand.Parameters.AddWithValue("@profileCNIC", cnic);
                profileCommand.Parameters.AddWithValue("@profileDOB", dob);
                profileCommand.Parameters.AddWithValue("@profileGender", gender);
                profileCommand.Parameters.AddWithValue("@profileContact", contact);
                profileCommand.ExecuteNonQuery();

                string taQuery = "INSERT INTO ta (userID, courseID, taAvailability) VALUES (@userID, @courseID, @avail)";

                SqlCommand taCommand = new SqlCommand(taQuery, connection);

                taCommand.Parameters.AddWithValue("@userID", userID);
                taCommand.Parameters.AddWithValue("@courseID", courseID);
                taCommand.Parameters.AddWithValue("@avail", avail);
                taCommand.ExecuteNonQuery();

                MessageBox.Show("TA added successfully.");

                f_facultyViewTA obj = new f_facultyViewTA();
                obj.Show();
                this.Hide();
            }
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            f_facultyViewTA obj = new f_facultyViewTA();
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
