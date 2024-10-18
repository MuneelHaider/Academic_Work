using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;

/*
 * 
 * Muneel Haider
 * 21i-0640
 * LAB 12
 * 
 */

namespace WinFormsApp1
{
    public static class GlobalVariables
    {
        public static string SharedVariable = "";
    }

    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e) { }

        private void textBox1_TextChanged(object sender, EventArgs e) { }

        private void button1_Click(object sender, EventArgs e)
        {
            var username = userText.Text;
            var password = passwordText.Text;
            GlobalVariables.SharedVariable = username;

            var connectionstring = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                    "Initial Catalog=LAB12;" +
                                    "Integrated Security=True;";

            SqlConnection connection = new SqlConnection(connectionstring);

            connection.Open();
            SqlCommand com1 = new SqlCommand("insert into users " +
             "values('" + username + "','" + password + "')", connection);

            var ifError = com1.ExecuteNonQuery();

            if (ifError == 0)
            {
                MessageBox.Show("Error");
            }
            else
            {

                MessageBox.Show("Successfully Registered!");

                connection.Close();

                Form2 obj = new Form2(username);
                obj.Show();
                this.Hide();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {

            var username1 = userText.Text;
            var password1 = passwordText.Text;

            var connectionstring1 = "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" +
                                    "Initial Catalog=LAB12;" +
                                    "Integrated Security=True;";

            SqlConnection connection1 = new SqlConnection(connectionstring1);

            connection1.Open();

            string name = "";
            string pass = "";

            SqlCommand com11 = new SqlCommand("select * from users where userName='" + username1 + "' AND userPassword='" + password1 + "'", connection1);

            com11.Parameters.AddWithValue(username1, userText.Text);
            com11.Parameters.AddWithValue(password1, passwordText.Text);

            SqlDataReader reader = com11.ExecuteReader();
            reader.Read();
            bool flag = false;

            if (reader.HasRows)
            {

                flag = true;
                name = reader["userName"].ToString();
                pass = reader["userPassword"].ToString();
            }

            reader.Close();
            connection1.Close();

            if(flag == true)
            {

                if(name == username1)
                {

                    MessageBox.Show("LOGIN SUCCESSFULLY!");

                    Form2 obj = new Form2(username1);
                    obj.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("Invalid Details.");
                }
            }
            else
            {
                MessageBox.Show("Invalid Details.");
            } 
        }
    }
}