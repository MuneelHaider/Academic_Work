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
    public partial class ld_GiveFeedBack : Form
    {
        public ld_GiveFeedBack()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var feedback = richTextBox1.Text;
            string feedbackDescription = richTextBox1.Text;
            string username = globalVar.GlobalVariables.globalstring;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                           "Initial Catalog=DBProject;" +
                           "Integrated Security=True;";


            // Get the current date
            DateTime currentDate = DateTime.Now;

            // Assuming you have a SqlConnection object named "sqlConnection" and it's properly configured with your database connection string
            using (SqlConnection sqlConnection = new SqlConnection(connectionString))
            {
                sqlConnection.Open();

                // Step 1: Get the userID based on the username
                string getUserIdQuery = "SELECT userID FROM users WHERE userName = @Username";
                int userID;

                using (SqlCommand getUserIdCmd = new SqlCommand(getUserIdQuery, sqlConnection))
                {
                    getUserIdCmd.Parameters.AddWithValue("@Username", username);
                    object result = getUserIdCmd.ExecuteScalar();

                    // Check if a user with the given username exists
                    if (result != null)
                    {
                        userID = Convert.ToInt32(result);

                        // Step 2: Insert data into the feedback table
                        string insertFeedbackQuery = "INSERT INTO feedback (userID, feedbackDescription, feedbackDate) " +
                                                        "VALUES (@UserID, @FeedbackDescription, @FeedbackDate)";

                        using (SqlCommand insertFeedbackCmd = new SqlCommand(insertFeedbackQuery, sqlConnection))
                        {
                            insertFeedbackCmd.Parameters.AddWithValue("@UserID", userID);
                            insertFeedbackCmd.Parameters.AddWithValue("@FeedbackDescription", feedbackDescription);
                            insertFeedbackCmd.Parameters.AddWithValue("@FeedbackDate", currentDate);

                            insertFeedbackCmd.ExecuteNonQuery();

                            MessageBox.Show("Feedback inserted successfully.");

                            ld_Mainpage obj = new ld_Mainpage();
                            obj.Show();
                            this.Hide();
                        }
                    }
                    else
                    {
                        MessageBox.Show("User not found.");
                    }
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            ld_Mainpage obj = new ld_Mainpage();
            obj.Show();
            this.Hide();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            ld_GiveFeedBack obj = new ld_GiveFeedBack();
            obj.Show();
            this.Hide();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            ld_SeeTasks obj = new ld_SeeTasks();
            obj.Show();
            this.Hide();
        }
    }
}
