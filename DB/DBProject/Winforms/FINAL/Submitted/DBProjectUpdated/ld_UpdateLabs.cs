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
    public partial class ld_UpdateLabs : Form
    {
        public ld_UpdateLabs()
        {
            InitializeComponent();
        }

        private void ld_UpdateLabs_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                try
                {
                    sqlConnection.Open();

                    // Step 1: Define the SQL query to retrieve data from the lab table with labStatus = 0
                    string selectQuery = "SELECT * FROM lab WHERE labStatus = 0";

                    // Step 2: Create a SqlDataAdapter to fetch the data
                    using (SqlDataAdapter dataAdapter = new SqlDataAdapter(selectQuery, sqlConnection))
                    {
                        // Step 3: Create a DataTable to hold the retrieved data
                        DataTable dataTable = new DataTable();

                        // Step 4: Fill the DataTable with the data from the lab table
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

        private void button1_Click(object sender, EventArgs e)
        {
            ld_SeeTasks obj = new ld_SeeTasks();
            obj.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string labname = textBox1.Text;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            // Assuming you have a SqlConnection object named "sqlConnection" properly configured with your database connection string
            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                sqlConnection.Open();

                // Step 1: Define the SQL query to update labStatus based on labName
                string updateQuery = "UPDATE lab SET labStatus = 1 WHERE labName = @LabName";

                // Step 2: Create a SqlCommand to execute the update query
                using (SqlCommand sqlCommand = new SqlCommand(updateQuery, sqlConnection))
                {
                    sqlCommand.Parameters.AddWithValue("@LabName", labname);

                    // Step 3: Execute the update query
                    int rowsAffected = sqlCommand.ExecuteNonQuery();

                    if (rowsAffected > 0)
                    {
                        MessageBox.Show($"Lab '{labname}' Status Updated to COMPLETE.");

                        ld_SeeTasks obj = new ld_SeeTasks();
                        obj.Show();
                        this.Hide();
                    }
                    else
                    {
                        MessageBox.Show($"Lab '{labname}' not found.");
                    }
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            ld_SeeTasks obj = new ld_SeeTasks();
            obj.Show();
            this.Hide();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            ld_GiveFeedBack obj = new ld_GiveFeedBack();
            obj.Show();
            this.Hide();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            ld_SeeTasks obj = new ld_SeeTasks();
            obj.Show();
            this.Hide();
        }
    }
}
