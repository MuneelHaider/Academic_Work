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
    public partial class ld_SeeTasks : Form
    {
        public ld_SeeTasks()
        {
            InitializeComponent();
        }

        private void ld_SeeTasks_Load(object sender, EventArgs e)
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
            ld_Mainpage obj = new ld_Mainpage();
            obj.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ld_UpdateLabs obj = new ld_UpdateLabs();
            obj.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            ld_Mainpage obj = new ld_Mainpage();
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

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {
        }
    }
}
