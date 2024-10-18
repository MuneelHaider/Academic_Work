namespace LAB3.Models
{
    public class Students
    {

        public string Roll_number { get; set; }
        public string Name { get; set; }
        public float CGPA { get; set; }

        public string department { get; set; }

        public string phoneNumber { get; set; }

        public string email {  get; set; }
        public Students()
        {

            Roll_number = string.Empty;
            Name = string.Empty;
            CGPA = 0;
            department = string.Empty;
            phoneNumber = string.Empty;
            email = string.Empty;
        }

        public Students(string roll_number, string name, float cGPA, string department, string phoneNumber, string email)
        {
            Roll_number = roll_number;
            Name = name;
            CGPA = cGPA;
            this.department = department;
            this.phoneNumber = phoneNumber;
            this.email = email;
            
        }

        //public float GETCGPA
        //{
        //    get
        //    {
        //        return CGPA;
        //    }
        //    set
        //    {

        //        CGPA = value;
        //    }
        //}


    }
}
