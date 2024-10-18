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
    public partial class FacultyView : Form
    {
        public FacultyView()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            facultySignup obj = new facultySignup();
            obj.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            AdminMainPage obj = new AdminMainPage();
            obj.Show();
            this.Hide();
        }

        private void FacultyView_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string query = @"SELECT u.userName, u.userEmail, p.profileName, p.profileAddress, p.profileCNIC, p.profileDOB, p.profileGender, p.profileContact, f.facultyDepartment, f.facultyOffice 
                            FROM users u
                            INNER JOIN profile p ON u.userID = p.userID
                            INNER JOIN faculty f ON u.userID = f.userID
                            WHERE u.userRole = 'Faculty'";

                SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connection);

                DataTable dataTable = new DataTable();
                dataAdapter.Fill(dataTable);

                dataGridView1.DataSource = dataTable;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            facultyRemove obj = new facultyRemove();
            obj.Show();
            this.Hide();
        }

        private void button2_Click_1(object sender, EventArgs e)
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
