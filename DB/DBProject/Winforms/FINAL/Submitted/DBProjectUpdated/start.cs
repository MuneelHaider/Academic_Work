using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace DBProject
{
    public partial class start : Form
    {
        public start()
        {
            InitializeComponent();
        }

        private void singupbutton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void LOGIN_Click(object sender, EventArgs e)
        {
            var username = usertext.Text;
            var password = passtext.Text;

            var connectionstring = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                    "Initial Catalog=DBProject;" +
                                    "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionstring))
            {
                connection.Open();

                string query1 = "SELECT userName, userPassword, userRole FROM users WHERE userName = '" + username + "' AND userPassword = '" + password + "'";

                SqlCommand cmd1 = new SqlCommand(query1, connection);

                cmd1.Parameters.AddWithValue("@username", username);
                cmd1.Parameters.AddWithValue("@password", password);

                using (SqlDataReader reader = cmd1.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        MessageBox.Show("LOGIN SUCCESSFULL.");

                        globalVar.GlobalVariables.globalstring = username;

                        string role = reader["userRole"].ToString();

                        if (role == "Admin")
                        {

                            AdminMainPage obj = new AdminMainPage();
                            obj.Show();
                            this.Hide();
                        }
                        else if (role == "Faculty")
                        {

                            f_facultyMain obj = new f_facultyMain();
                            obj.Show();
                            this.Hide();
                        }
                        else if (role == "LD")
                        {

                            ld_Mainpage obj = new ld_Mainpage();
                            obj.Show();
                            this.Hide();
                        }
                        else if (role == "TA")
                        {

                            ta_Mainpage obj = new ta_Mainpage();
                            obj.Show();
                            this.Hide();
                        }
                    }
                    else
                    {
                        MessageBox.Show("Invalid Details.");
                    }
                }
            }
        }

        private void start_Load(object sender, EventArgs e)
        {

        }
    }
}
