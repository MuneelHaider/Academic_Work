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

namespace WinFormsApp3
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
            PopulateData();
        }

        public void PopulateData()
        {
            string connectionString =
                "Data Source=SALMAN\\SQLEXPRESS;" +
                "Database=WidnowsForm;" +
                "Integrated Security=True";
            SqlConnection sql = new SqlConnection(connectionString);
            sql.Open();
            string query = "select * from Users";
            SqlCommand cmd = new SqlCommand(query, sql);
            SqlDataReader reader = cmd.ExecuteReader();

            if(reader.HasRows)
            {
              dataGridView1.Columns.Add("Username", "Username");
                dataGridView1.Columns.Add("FullName", "FullName");
                dataGridView1.Columns.Add("Password", "Password");
                dataGridView1.Columns.Add("Age", "Age");

                while (reader.Read())
                {
                    string username = reader["Username"].ToString();
                    string fullname = reader["FullName"].ToString();
                    string password = reader["Password"].ToString();
                    string age = reader["Age"].ToString();
                    dataGridView1.Rows.Add(username , fullname , password, age);
                }
            }
            else
            {
                MessageBox.Show("No Data");
            }



        }
    }
}
