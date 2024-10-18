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
    public partial class ta_GiveFeedBack : Form
    {
        public ta_GiveFeedBack()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ta_Mainpage obj = new ta_Mainpage();
            obj.Show();
            this.Hide();
        }

        private void ta_GiveFeedBack_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            var username = globalVar.GlobalVariables.globalstring;
            var feedback = richTextBox1.Text;

            string connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
        "Initial Catalog=DBProject;" +
        "Integrated Security=True;";

            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                sqlConnection.Open();

                // Step 1: Define the SQL query to retrieve necessary attributes based on username
                string selectQuery = "SELECT u.userID FROM users u " +
                                        "WHERE u.userName = @Username";

                // Step 2: Create a SqlCommand to execute the query
                using (SqlCommand sqlCommand = new SqlCommand(selectQuery, sqlConnection))
                {
                    sqlCommand.Parameters.AddWithValue("@Username", username);

                    // Step 3: Execute the query and retrieve the userID
                    int userID = Convert.ToInt32(sqlCommand.ExecuteScalar());

                    // Step 4: Get the current system date
                    DateTime currentDate = DateTime.Now;

                    // Step 5: Insert data into the feedback table
                    string insertQuery = "INSERT INTO feedback (userID, feedbackDescription, feedbackDate) " +
                                            "VALUES (@UserID, @FeedbackDescription, @FeedbackDate)";

                    using (SqlCommand insertCommand = new SqlCommand(insertQuery, sqlConnection))
                    {
                        insertCommand.Parameters.AddWithValue("@UserID", userID);
                        insertCommand.Parameters.AddWithValue("@FeedbackDescription", feedback);
                        insertCommand.Parameters.AddWithValue("@FeedbackDate", currentDate);

                        // Execute the insert query
                        int rowsAffected = insertCommand.ExecuteNonQuery();

                        if (rowsAffected > 0)
                        {
                            MessageBox.Show("Feedback saved successfully.");

                            ta_Mainpage obj = new ta_Mainpage();
                            obj.Show();
                            this.Hide();
                        }
                        else
                        {
                            MessageBox.Show("Failed to save feedback.");
                        }
                    }
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            ta_Mainpage obj = new ta_Mainpage();
            obj.Show();
            this.Hide();
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
    }
}
