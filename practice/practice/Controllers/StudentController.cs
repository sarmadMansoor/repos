using Microsoft.AspNetCore.Mvc;
using practice.Models;

namespace practice.Controllers
{
    public class StudentController : Controller
    {
        public ViewResult Index()
        {
            return View("Index");
        }
        public ViewResult StudentForm()
        {
            return View();
        }
    }
}
