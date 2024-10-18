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
using static DBProject.globalVar;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;

namespace DBProject
{
    public partial class f_facultyMain : Form
    {
        public f_facultyMain()
        {
            InitializeComponent();
        }

        private void f_facultyMain_Load(object sender, EventArgs e)
        {
            var username = globalVar.GlobalVariables.globalstring;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string query = @"SELECT u.userName, u.userEmail, p.profileName, p.profileAddress, p.profileCNIC, 
                                p.profileDOB, p.profileGender, p.profileContact, 
                                f.facultyDepartment, f.facultyOffice 
                         FROM users u
                         INNER JOIN profile p ON u.userID = p.userID
                         INNER JOIN faculty f ON u.userID = f.userID
                         WHERE u.userName = @userName"
                ;

                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@userName", username);

                using (SqlDataReader reader = command.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        // Assign values to textboxes
                        usernametxt.Text = reader["userName"].ToString();
                        emailtxt.Text = reader["userEmail"].ToString();
                        fullnametxt.Text = reader["profileName"].ToString();
                        addresstxt.Text = reader["profileAddress"].ToString();
                        cnictxt.Text = reader["profileCNIC"].ToString();
                        dobtxt.Text = (reader["profileDOB"] != DBNull.Value) ? Convert.ToDateTime(reader["profileDOB"]).ToString("yyyy-MM-dd") : "";
                        gendertxt.Text = reader["profileGender"].ToString();
                        contacttxt.Text = reader["profileContact"].ToString();
                        departmenttxt.Text = reader["facultyDepartment"].ToString();
                        officetxt.Text = reader["facultyOffice"].ToString();
                    }
                    else
                    {
                        MessageBox.Show("Faculty member not found.");
                    }
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            start obj = new start();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            f_facultyfeedback obj = new f_facultyfeedback();
            obj.Show();
            this.Hide();
        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void usernametxt_TextChanged(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            f_facultyViewTA obj = new f_facultyViewTA();
            obj.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {
            f_facultyViewLD obj = new f_facultyViewLD();
            obj.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            f_facultyTasks obj = new f_facultyTasks();
            obj.Show();
            this.Hide();
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            start obj = new start();
            obj.Show();
            this.Hide();
        }
    }
}
