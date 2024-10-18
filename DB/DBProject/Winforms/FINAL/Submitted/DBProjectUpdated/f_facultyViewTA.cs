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
    public partial class f_facultyViewTA : Form
    {
        public f_facultyViewTA()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            f_facultyMain f_FacultyMain = new f_facultyMain();
            f_FacultyMain.Show();
            this.Hide();
        }

        private void f_facultyViewTA_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string query = @"SELECT ta.taID, ta.userID, ta.courseID, ta.taAvailability, 
                                users.userName AS TAName, course.courseName AS CourseName 
                        FROM ta
                        JOIN users ON ta.userID = users.userID
                        JOIN course ON ta.courseID = course.courseID";

                SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connection);

                DataTable dataTable = new DataTable();
                dataAdapter.Fill(dataTable);

                dataGridView1.DataSource = dataTable;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            f_facultyAddTA obj = new f_facultyAddTA();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            f_facultyRemoveTA obj = new f_facultyRemoveTA();
            obj.Show();
            this.Hide();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            f_facultyMain obj = new f_facultyMain();
            obj.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            f_facultyfeedback obj = new f_facultyfeedback();
            obj.Show();
            this.Hide();
        }

        private void button5_Click(object sender, EventArgs e)
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
