using System.Data.SqlClient;
namespace WinFormsApp3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var username = Usernametext.Text;
            var password = passwordtext.Text;
            var FullName = fnametext.Text;
            var age = agetext.Text;

            var connectionString = 
                "Data Source=SALMAN\\SQLEXPRESS;" +
                "Database=WidnowsForm;" +
                "Integrated Security=True";

            SqlConnection sqlconn = new SqlConnection(connectionString);
            sqlconn.Open();

            SqlCommand sqlcomm = new SqlCommand("insert into Users " +"values('" +
                username + "','" + FullName +
                "','" + password + "'," + age + ")" , sqlconn);
            var ifError = sqlcomm.ExecuteNonQuery();
            if (ifError == 0)
            {
                MessageBox.Show("Error");
            }
            else
            {
                MessageBox.Show("Success");
            }
        }
    }
}