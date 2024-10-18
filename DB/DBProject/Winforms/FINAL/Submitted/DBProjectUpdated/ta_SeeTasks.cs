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
    public partial class ta_SeeTasks : Form
    {
        public ta_SeeTasks()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ta_Mainpage obj = new ta_Mainpage();
            obj.Show();
            this.Hide();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ta_UpdateTasks obj = new ta_UpdateTasks();
            obj.Show();
            this.Hide();
        }

        private void ta_SeeTasks_Load(object sender, EventArgs e)
        {
            string connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
        "Initial Catalog=DBProject;" +
        "Integrated Security=True;";

            // Assuming you have a DataGridView control named dataGridView1 on your form
            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                sqlConnection.Open();

                // Step 1: Define the SQL query to retrieve data from the taskTA table with taskStatus = 0
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
        }

        private void button4_Click(object sender, EventArgs e)
        {
            ta_Mainpage obj = new ta_Mainpage();
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

        private void label11_Click(object sender, EventArgs e)
        {

        }
    }
}
