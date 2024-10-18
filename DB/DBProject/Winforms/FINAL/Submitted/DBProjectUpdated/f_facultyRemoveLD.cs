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
    public partial class f_facultyRemoveLD : Form
    {
        public f_facultyRemoveLD()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            f_facultyViewLD obj = new f_facultyViewLD();
            obj.Show();
            this.Hide();
        }

        private void f_facultyRemoveLD_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // SQL query to fetch LD information along with user and course details
                string query = @"
                                SELECT ld.ldID, u.userName AS 'LD Name', c.courseName
                                FROM ld
                                INNER JOIN users u ON ld.userID = u.userID
                                INNER JOIN course c ON ld.courseID = c.courseID";

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

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Step 1: Retrieve userID from the username
                string getUserIdQuery = "SELECT userID FROM users WHERE userName = @userName";
                SqlCommand getUserIdCommand = new SqlCommand(getUserIdQuery, connection);
                getUserIdCommand.Parameters.AddWithValue("@userName", username);

                object userIdResult = getUserIdCommand.ExecuteScalar();

                if (userIdResult != null)
                {
                    int userID = Convert.ToInt32(userIdResult);

                    // Step 2: Delete LD from the ld table
                    string deleteLDQuery = "DELETE FROM ld WHERE userID = @userID";
                    SqlCommand deleteLDCommand = new SqlCommand(deleteLDQuery, connection);
                    deleteLDCommand.Parameters.AddWithValue("@userID", userID);

                    int rowsAffected = deleteLDCommand.ExecuteNonQuery();

                    if (rowsAffected > 0)
                    {
                        MessageBox.Show("LD removed successfully.");

                        f_facultyViewLD obj = new f_facultyViewLD();
                        obj.Show();
                        this.Hide();
                    }
                    else
                    {
                        MessageBox.Show("LD not found or already removed.");
                    }
                }
                else
                {
                    MessageBox.Show("Username not found.");
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            f_facultyfeedback obj = new f_facultyfeedback();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            f_facultyViewLD obj = new f_facultyViewLD();
            obj.Show();
            this.Hide();
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

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
