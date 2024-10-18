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

namespace LAB10
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();

            populateData();
        }

        public void populateData()
        {

            var connectionstring = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                        "Initial Catalog=LAB10;" +
                                        "Integrated Security=True;";

            SqlConnection sqlconn = new SqlConnection(connectionstring);

            sqlconn.Open();

            string query = "insert into users values('Muneel', 123)";

            SqlCommand comm = new SqlCommand(query, sqlconn);
            comm.ExecuteNonQuery();

            SqlDataReader reader = comm.ExecuteReader();

            if (reader.Read())
            {

                DataGridView grid1 = new DataGridView();
                grid1.Columns.Add("username", "username");
                grid1.Columns.Add("fullname", "fullname");
                grid1.Columns.Add("password", "password");
                grid1.Columns.Add("agr", "agr");

                while (reader.Read())
                {

                    string id = reader["id"].ToString();
                    string username = reader["username"].ToString();
                    string fullname = reader["fullname"].ToString();
                    string password = reader["password"].ToString();
                    string agr = reader["agr"].ToString();

                    grid1.Rows.Add(username, fullname, password, agr);
                }
            }
        }
    }
}
