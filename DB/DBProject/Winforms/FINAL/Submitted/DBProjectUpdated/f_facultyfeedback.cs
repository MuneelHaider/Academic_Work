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
    public partial class f_facultyfeedback : Form
    {
        public f_facultyfeedback()
        {
            InitializeComponent();
        }

        private void f_facultyfeedback_Load(object sender, EventArgs e)
        {
            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string query = @"SELECT u.userName, u.userRole
                                 FROM users u
                                 INNER JOIN feedback f ON u.userID = f.userID";

                SqlDataAdapter dataAdapter = new SqlDataAdapter(query, connection);

                DataTable dataTable = new DataTable();
                dataAdapter.Fill(dataTable);

                dataGridView1.DataSource = dataTable;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var username = feedbacktxt.Text;
            globalVar.GlobalVariables.globalstring2 = username;

            f_facultyViewFeedback obj = new f_facultyViewFeedback();
            obj.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            f_facultyMain obj = new f_facultyMain();
            obj.Show();
            this.Hide();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            f_facultyMain obj = new f_facultyMain();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            f_facultyfeedback obj = new f_facultyfeedback();
            obj.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            f_facultyTasks obj = new f_facultyTasks();
            obj.Show();
            this.Hide();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            f_facultyViewTA obj = new f_facultyViewTA();
            obj.Show();
            this.Hide();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            f_facultyViewLD obj = new f_facultyViewLD();
            obj.Show();
            this.Hide();
        }
    }
}
