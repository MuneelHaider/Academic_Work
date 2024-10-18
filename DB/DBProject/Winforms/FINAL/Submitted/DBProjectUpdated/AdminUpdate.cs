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
    public partial class AdminUpdate : Form
    {
        public AdminUpdate()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            AdminMainPage obj = new AdminMainPage();
            obj.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AdminUpdate1 obj = new AdminUpdate1();
            obj.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            AdminUpdate2 obj = new AdminUpdate2();
            obj.Show();
            this.Hide();
        }

        private void AdminUpdate_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string query = @"SELECT u.userName, u.userEmail, u.userRole, p.profileName, p.profileAddress, p.profileCNIC, p.profileDOB, p.profileGender, p.profileContact 
                            FROM users u
                            INNER JOIN profile p ON u.userID = p.userID
                            WHERE u.userRole = 'Admin'";

                SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connection);

                DataTable dataTable = new DataTable();
                dataAdapter.Fill(dataTable);

                dataGridView1.DataSource = dataTable;
            }
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            AdminMainPage obj = new AdminMainPage();
            obj.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            AddAdmin obj = new AddAdmin();
            obj.Show();
            this.Hide();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            AdminUpdate obj = new AdminUpdate();
            obj.Show();
            this.Hide();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            FacultyView obj = new FacultyView();
            obj.Show();
            this.Hide();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            AdminViewCourses obj = new AdminViewCourses();
            obj.Show();
            this.Hide();
        }
    }
}
