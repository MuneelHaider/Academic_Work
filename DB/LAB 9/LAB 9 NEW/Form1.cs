namespace LAB_9_NEW
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            this.Visible = false;

            Form2 form = new Form2();
            form.Visible = true;
        }
    }
}