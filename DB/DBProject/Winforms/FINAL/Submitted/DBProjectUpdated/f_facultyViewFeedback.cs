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
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace DBProject
{
    public partial class f_facultyViewFeedback : Form
    {
        public f_facultyViewFeedback()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            f_facultyfeedback obj = new f_facultyfeedback();
            obj.Show();
            this.Hide();
        }

        private void f_facultyViewFeedback_Load(object sender, EventArgs e)
        {
            var username = globalVar.GlobalVariables.globalstring2;

            var connectionString = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                   "Initial Catalog=DBProject;" +
                                   "Integrated Security=True;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();

                string query = @"SELECT u.userName, u.userRole, f.feedbackDate, f.feedbackDescription
                            FROM users u
                            INNER JOIN feedback f ON u.userID = f.userID
                            WHERE u.userName = @userName";

                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@userName", username);

                using (SqlDataReader reader = command.ExecuteReader())
                {
                    if (reader.Read())
                    {
                        textBox1.Text = reader["userName"].ToString();
                        textBox2.Text = reader["userRole"].ToString();
                        textBox3.Text = reader["feedbackDate"] != DBNull.Value ? Convert.ToDateTime(reader["feedbackDate"]).ToString("yyyy-MM-dd") : "";

                        string feedbackDescription = reader["feedbackDescription"].ToString();
                        richTextBox1.Text = FormatStringForLabel(feedbackDescription);
                    }
                    else
                    {
                        MessageBox.Show("No feedback found for the selected user.");
                    }
                }
            }
        }

        private string FormatStringForLabel(string input)
        {
            var words = input.Split(' ');
            var formattedString = new StringBuilder();
            var lineLength = 0;

            foreach (var word in words)
            {
                formattedString.Append(word + " ");
                lineLength += word.Length;
                if (lineLength >= 10)
                {
                    formattedString.AppendLine();
                    lineLength = 0;
                }
            }

            return formattedString.ToString();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            f_facultyfeedback obj = new f_facultyfeedback();
            obj.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            f_facultyfeedback obj = new f_facultyfeedback();
            obj.Show();
            this.Hide();
        }

        private void button5_Click(object sender, EventArgs e)
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
