using Microsoft.AspNetCore.Mvc;
using LAB3.Models;

namespace LAB3.Controllers
{
    public class StudentsController : Controller
    {
        public static List<Students> students = new List<Students>();

        Students s1 = new Students("21i-0640", "Muneel", 4, "CS", "12346", "muneelhaider@gmail.com");
        Students s2 = new Students("21i-1140", "Munees", 3, "CS", "42346", "haider@gmail.com");
        Students s3 = new Students("21i-2240", "Muneer", 2, "CS", "32346", "muneel@gmail.com");
        Students s4 = new Students("21i-3340", "Muneeb", 1, "CS", "22346", "munees@gmail.com");

        public IActionResult Index()
        {

            //students.Add(s1);
            //students.Add(s2);
            //students.Add(s3);
            //students.Add(s4);

            return View(students);
        }

        public IActionResult Create()
        {

            return View();
        }

        [HttpPost]
        public IActionResult Create(Students student)
        {

            students.Add(student);
            return RedirectToAction("Index");
        }
    }
}
