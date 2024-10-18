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
    public partial class ta_UpdateTasks : Form
    {
        public ta_UpdateTasks()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ta_SeeTasks obj = new ta_SeeTasks();
            obj.Show();
            this.Hide();
        }

        private void ta_UpdateTasks_Load(object sender, EventArgs e)
        {
            string connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
        "Initial Catalog=DBProject;" +
        "Integrated Security=True;";

            // Assuming you have a DataGridView control named dataGridView1 on your form
            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                try
                {
                    sqlConnection.Open();

                    // Step 1: Define the SQL query to retrieve tasks from the taskTA table with taskStatus = 0
                    string selectQuery = "SELECT * FROM taskTA WHERE taskStatus = 0";

                    // Step 2: Create a SqlDataAdapter to fetch the data
                    using (SqlDataAdapter dataAdapter = new SqlDataAdapter(selectQuery, sqlConnection))
                    {
                        // Step 3: Create a DataTable to hold the retrieved data
                        DataTable dataTable = new DataTable();

                        // Step 4: Fill the DataTable with the data from the taskTA table
                        dataAdapter.Fill(dataTable);

                        // Step 5: Bind the DataGridView to the DataTable
                        dataGridView1.DataSource = dataTable;
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var taskname = textBox1.Text;

            string connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
        "Initial Catalog=DBProject;" +
        "Integrated Security=True;";

            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                try
                {
                    sqlConnection.Open();

                    // Step 1: Define the SQL query to update the task status to 1 based on taskname
                    string updateQuery = "UPDATE taskTA SET taskStatus = 1 WHERE taskName = @TaskName";

                    // Step 2: Create a SqlCommand to execute the query
                    using (SqlCommand sqlCommand = new SqlCommand(updateQuery, sqlConnection))
                    {
                        sqlCommand.Parameters.AddWithValue("@TaskName", taskname);

                        // Step 3: Execute the query to update the task status
                        int rowsAffected = sqlCommand.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("Task status updated successfully.");

                            ta_SeeTasks obj = new ta_SeeTasks();
                            obj.Show();
                            this.Hide();
                        }
                        else
                        {
                            MessageBox.Show("No task found with the specified name.");
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: " + ex.Message);
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            ta_SeeTasks obj = new ta_SeeTasks();
            obj.Show();
            this.Hide();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            ta_GiveFeedBack obj = new ta_GiveFeedBack();
            obj.Show();
            this.Hide();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            ta_SeeTasks obj = new ta_SeeTasks();
            obj.Show();
            this.Hide();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
