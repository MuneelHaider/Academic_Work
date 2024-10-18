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
    public partial class f_facultyRemoveTask : Form
    {
        public f_facultyRemoveTask()
        {
            InitializeComponent();
        }

        private void f_facultyRemoveTask_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string query = @"
                                SELECT t.taskName AS 'Task/Lab Name', u.userName AS 'TA/LD Name'
                                FROM taskTA t
                                INNER JOIN ta ON t.taID = ta.taID
                                INNER JOIN users u ON ta.userID = u.userID

                                UNION

                                SELECT l.labName AS 'Task/Lab Name', u.userName AS 'TA/LD Name'
                                FROM lab l
                                INNER JOIN ld ON l.ldID = ld.ldID
                                INNER JOIN users u ON ld.userID = u.userID";

                SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connection);

                DataTable dataTable = new DataTable();
                dataAdapter.Fill(dataTable);

                dataGridView1.DataSource = dataTable;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var taskName = textBox1.Text;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                   "Initial Catalog=DBProject;" +
                                   "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                // Attempt to delete from taskTA
                string deleteTaskQuery = "DELETE FROM taskTA WHERE taskName = @taskName";
                SqlCommand deleteTaskCommand = new SqlCommand(deleteTaskQuery, connection);
                deleteTaskCommand.Parameters.AddWithValue("@taskName", taskName);
                int rowsAffectedTask = deleteTaskCommand.ExecuteNonQuery();

                // Attempt to delete from lab
                string deleteLabQuery = "DELETE FROM lab WHERE labName = @taskName";
                SqlCommand deleteLabCommand = new SqlCommand(deleteLabQuery, connection);
                deleteLabCommand.Parameters.AddWithValue("@taskName", taskName);
                int rowsAffectedLab = deleteLabCommand.ExecuteNonQuery();

                if (rowsAffectedTask > 0)
                {
                    MessageBox.Show("Task deleted from TA tasks.");

                    f_facultyTasks obj = new f_facultyTasks();
                    obj.Show();
                    this.Hide();
                }
                else if (rowsAffectedLab > 0)
                {
                    MessageBox.Show("Task deleted from Lab tasks.");

                    f_facultyTasks obj = new f_facultyTasks();
                    obj.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("Task not found in TA or Lab tasks.");
                }
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            f_facultyTasks obj = new f_facultyTasks();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            f_facultyTasks obj = new f_facultyTasks();
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
