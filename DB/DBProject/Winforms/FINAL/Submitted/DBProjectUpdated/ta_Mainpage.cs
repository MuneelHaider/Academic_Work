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
    public partial class ta_Mainpage : Form
    {
        public ta_Mainpage()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            start obj = new start();
            obj.Show();
            this.Hide();
        }

        private void ta_Mainpage_Load(object sender, EventArgs e)
        {
            var username = globalVar.GlobalVariables.globalstring;

            string connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
        "Initial Catalog=DBProject;" +
        "Integrated Security=True;";

            // Establish a database connection
            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                sqlConnection.Open();

                // Define the SQL query to retrieve TA details based on username
                string selectQuery = "SELECT u.userName, u.userEmail, u.userRole, " +
                                        "p.profileName, p.profileAddress, p.profileCNIC, " +
                                        "p.profileDOB, p.profileGender, p.profileContact, " +
                                        "c.courseName " +
                                        "FROM users u " +
                                        "JOIN profile p ON u.userID = p.userID " +
                                        "LEFT JOIN ta t ON u.userID = t.userID " +
                                        "LEFT JOIN course c ON t.courseID = c.courseID " +
                                        "WHERE u.userName = @Username";

                // Create a SqlCommand to execute the query
                using (SqlCommand sqlCommand = new SqlCommand(selectQuery, sqlConnection))
                {
                    sqlCommand.Parameters.AddWithValue("@Username", username);

                    // Execute the query and retrieve the data
                    SqlDataReader reader = sqlCommand.ExecuteReader();

                    // Check if a record was found
                    if (reader.Read())
                    {
                        // Populate the respective textboxes with the fetched data
                        textBox1.Text = reader["userName"].ToString();
                        textBox2.Text = reader["userEmail"].ToString();
                        textBox3.Text = reader["userRole"].ToString();
                        textBox4.Text = reader["profileName"].ToString();
                        textBox5.Text = reader["profileAddress"].ToString();
                        textBox6.Text = reader["profileCNIC"].ToString();
                        textBox7.Text = reader["profileDOB"].ToString();
                        textBox8.Text = reader["profileGender"].ToString();
                        textBox9.Text = reader["profileContact"].ToString();
                        textBox10.Text = reader["courseName"].ToString();
                    }
                    else
                    {
                        MessageBox.Show("TA not found.");
                    }

                    reader.Close();
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ta_GiveFeedBack obj = new ta_GiveFeedBack();
            obj.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            ta_SeeTasks obj = new ta_SeeTasks();
            obj.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            start obj = new start();
            obj.Show();
            this.Hide();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

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

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {
        }

        private void label11_Click(object sender, EventArgs e)
        {
        }
    }
}
