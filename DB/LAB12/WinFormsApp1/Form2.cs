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

/*
 * 
 * Muneel Haider
 * 21i-0640
 * LAB 12
 * 
 */

namespace WinFormsApp1
{
    public partial class Form2 : Form
    {

        private string userNAME = "";
        public Form2(string copypasted)
        {
            InitializeComponent();
            PopulateData(copypasted);
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        public void PopulateData(string copypasted)
        {
            string connectionString =   "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                        "Initial Catalog=LAB12;" +
                                        "Integrated Security=True;";

            string userName = copypasted;

            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                sqlConnection.Open();
                string query = "SELECT t.taskID, t.taskName, t.taskDescription, t.taskStatus FROM tasks t INNER JOIN users u ON t.userID = u.userID WHERE u.userName ='" + userName + "'";

                using (SqlCommand sqlCommand = new SqlCommand(query, sqlConnection))
                {
                    sqlCommand.Parameters.AddWithValue("userName", userName);

                    using (SqlDataReader sqlReader = sqlCommand.ExecuteReader())
                    {
                        DataTable dataTable = new DataTable();

                        dataTable.Load(sqlReader);

                        dataGridView1.DataSource = dataTable;
                    }
                }
            }
        }
    }
}
