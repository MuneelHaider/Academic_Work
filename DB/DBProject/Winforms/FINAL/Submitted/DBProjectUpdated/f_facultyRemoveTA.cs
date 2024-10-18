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
    public partial class f_facultyRemoveTA : Form
    {
        public f_facultyRemoveTA()
        {
            InitializeComponent();
        }

        private void f_facultyRemoveTA_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string query = @"
                                SELECT u.userName AS 'TA Name', c.courseName AS 'Course Name'
                                FROM ta
                                INNER JOIN users u ON ta.userID = u.userID
                                INNER JOIN course c ON ta.courseID = c.courseID";

                SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connection);

                DataTable dataTable = new DataTable();
                dataAdapter.Fill(dataTable);

                dataGridView1.DataSource = dataTable;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            f_facultyViewTA obj = new f_facultyViewTA();
            obj.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var username = textBox1.Text;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string getUserIdQuery = "SELECT userID FROM users WHERE userName = @userName AND userRole = 'TA'";
                SqlCommand getUserIdCommand = new SqlCommand(getUserIdQuery, connection);
                getUserIdCommand.Parameters.AddWithValue("@userName", username);

                object result = getUserIdCommand.ExecuteScalar();

                if (result != null && result != DBNull.Value)
                {
                    int userID = Convert.ToInt32(result);

                    string deleteTAQuery = "DELETE FROM ta WHERE userID = @userID";
                    SqlCommand deleteTACommand = new SqlCommand(deleteTAQuery, connection);
                    deleteTACommand.Parameters.AddWithValue("@userID", userID);
                    int rowsAffected = deleteTACommand.ExecuteNonQuery();

                    if (rowsAffected > 0)
                    {
                        MessageBox.Show("TA removed successfully.");

                        f_facultyViewTA obj = new f_facultyViewTA();
                        obj.Show();
                        this.Hide();
                    }
                    else
                    {
                        MessageBox.Show("TA not found or already removed.");
                    }
                }
                else
                {
                    MessageBox.Show("TA with the specified username not found.");
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            f_facultyViewTA obj = new f_facultyViewTA();
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
