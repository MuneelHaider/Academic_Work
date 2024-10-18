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
    public partial class f_facultyAddTask : Form
    {
        public f_facultyAddTask()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            f_facultyTasks obj = new f_facultyTasks();
            obj.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var taskName = textBox1.Text;
            var facultyName = globalVar.GlobalVariables.globalstring; // Faculty name
            var username = textBox2.Text; // TA or LD username
            var date = textBox3.Text; // Ensure this is in 'yyyy-MM-dd' format
            var description = textBox4.Text;
            var status = 0; // Zero means task is pending

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                   "Initial Catalog=DBProject;" +
                                   "Integrated Security=True; ";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Step 1: Determine the user's role based on username
                string roleQuery = "SELECT userRole FROM users WHERE userName = @userName";
                SqlCommand roleCommand = new SqlCommand(roleQuery, connection);
                roleCommand.Parameters.AddWithValue("@userName", username);

                string userRole = (string)roleCommand.ExecuteScalar();

                if (userRole == "TA")
                {
                    // The user is a TA, insert into taskTA

                    // Retrieve facultyID using facultyName
                    string facultyIdQuery = "SELECT facultyID FROM faculty INNER JOIN users ON faculty.userID = users.userID WHERE userName = @facultyName";
                    SqlCommand facultyIdCommand = new SqlCommand(facultyIdQuery, connection);
                    facultyIdCommand.Parameters.AddWithValue("@facultyName", facultyName);

                    int facultyID = Convert.ToInt32(facultyIdCommand.ExecuteScalar());

                    // Retrieve taID using username
                    string taIdQuery = "SELECT taID FROM ta INNER JOIN users ON ta.userID = users.userID WHERE userName = @userName";
                    SqlCommand taIdCommand = new SqlCommand(taIdQuery, connection);
                    taIdCommand.Parameters.AddWithValue("@userName", username);

                    int taID = Convert.ToInt32(taIdCommand.ExecuteScalar());

                    string insertTaskQuery = "INSERT INTO taskTA (facultyID, taID, taskName, taskDescription, taskDueDate, taskStatus) VALUES (@facultyID, @taID, @taskName, @description, @date, @status)";
                    SqlCommand insertTaskCommand = new SqlCommand(insertTaskQuery, connection);
                    insertTaskCommand.Parameters.AddWithValue("@facultyID", facultyID);
                    insertTaskCommand.Parameters.AddWithValue("@taID", taID);
                    insertTaskCommand.Parameters.AddWithValue("@taskName", taskName);
                    insertTaskCommand.Parameters.AddWithValue("@description", description);
                    insertTaskCommand.Parameters.AddWithValue("@date", Convert.ToDateTime(date));
                    insertTaskCommand.Parameters.AddWithValue("@status", status);

                    insertTaskCommand.ExecuteNonQuery();
                    MessageBox.Show("Task for TA added successfully.");
                }
                else if (userRole == "LD")
                {
                    string ldIdQuery = "SELECT ldID FROM ld INNER JOIN users ON ld.userID = users.userID WHERE userName = @userName";
                    SqlCommand ldIdCommand = new SqlCommand(ldIdQuery, connection);
                    ldIdCommand.Parameters.AddWithValue("@userName", username);

                    int ldID = Convert.ToInt32(ldIdCommand.ExecuteScalar());

                    string insertLabQuery = "INSERT INTO lab (ldID, labName, labDate, labStatus, labDescription) VALUES (@ldID, @taskName, @date, @status, @description)";
                    SqlCommand insertLabCommand = new SqlCommand(insertLabQuery, connection);
                    insertLabCommand.Parameters.AddWithValue("@ldID", ldID);
                    insertLabCommand.Parameters.AddWithValue("@taskName", taskName);
                    insertLabCommand.Parameters.AddWithValue("@date", Convert.ToDateTime(date));
                    insertLabCommand.Parameters.AddWithValue("@status", status);
                    insertLabCommand.Parameters.AddWithValue("@description", description);

                    insertLabCommand.ExecuteNonQuery();
                    MessageBox.Show("Lab task added successfully.");
                }
                else
                {
                    MessageBox.Show("User role not found or unsupported for tasks.");
                }
            }
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            f_facultyTasks obj = new f_facultyTasks();
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
