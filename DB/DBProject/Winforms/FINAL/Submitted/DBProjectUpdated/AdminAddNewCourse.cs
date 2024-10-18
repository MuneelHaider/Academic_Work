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
    public partial class AdminAddNewCourse : Form
    {
        public AdminAddNewCourse()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AdminViewCourses obj = new AdminViewCourses();
            obj.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var courseName = coursenametxt.Text;
            var facultyName = facultynametxt.Text;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                   "Initial Catalog=DBProject;" +
                                   "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string facultyQuery = @"SELECT f.facultyID FROM faculty f
                                INNER JOIN users u ON f.userID = u.userID
                                WHERE u.userName = @facultyName";

                SqlCommand facultyCommand = new SqlCommand(facultyQuery, connection);
                facultyCommand.Parameters.AddWithValue("@facultyName", facultyName);

                object result = facultyCommand.ExecuteScalar();

                if (result != null && result != DBNull.Value)
                {
                    int facultyID = Convert.ToInt32(result);

                    string courseQuery = "INSERT INTO course (facultyID, courseName) VALUES (@facultyID, @courseName)";
                    SqlCommand courseCommand = new SqlCommand(courseQuery, connection);

                    courseCommand.Parameters.AddWithValue("@facultyID", facultyID);
                    courseCommand.Parameters.AddWithValue("@courseName", courseName);

                    courseCommand.ExecuteNonQuery();
                    MessageBox.Show("Course added successfully.");

                    AdminViewCourses obj = new AdminViewCourses();
                    obj.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("Faculty member not found.");
                }
            }
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void newadminbutton_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
        }

        private void viewtabutton_Click(object sender, EventArgs e)
        {
        }

        private void viewfacultybutton_Click(object sender, EventArgs e)
        {
        }

        private void button4_Click(object sender, EventArgs e)
        {
        }

        private void button5_Click_1(object sender, EventArgs e)
        {
            AdminUpdate obj = new AdminUpdate();
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

        private void button4_Click_1(object sender, EventArgs e)
        {
        }

        private void button7_Click(object sender, EventArgs e)
        {
            AdminViewCourses obj = new AdminViewCourses();
            obj.Show();
            this.Hide();
        }
    }
}
