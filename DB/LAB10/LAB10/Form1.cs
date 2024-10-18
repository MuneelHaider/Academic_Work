using System.Data.SqlClient;
namespace LAB10
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void singuptext_Click(object sender, EventArgs e)
        {
            var username = usernametext.Text;
            var password = passwordtext.Text;
            var fullname = nametext.Text;
            var age = agetext.Text;

            var connectionstring =  "Data Source=MUNEELHAIDER-PC\\SQLEXPRESS;" + 
                                    "Initial Catalog=LAB10;" + 
                                    "Integrated Security=True;";
            
            SqlConnection sqlconn = new SqlConnection(connectionstring);

            sqlconn.Open();
            SqlCommand sqlcomm = new SqlCommand("insert into users " + 
             "values('" + username + "','" + fullname + "','" + password + "'," + age + ")", sqlconn);

            var ifError = sqlcomm.ExecuteNonQuery();

            if(ifError == 0) {

                MessageBox.Show("Error");
            }
            else
            {
                MessageBox.Show("Success.");
            }

        }
    }
}