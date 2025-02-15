using Microsoft.AspNetCore.Mvc;
using lab_06_web.Models.Respositories;
using lab_06_web.Models;
namespace lab_06_web.Controllers
{
    public class WelcomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
        public IActionResult Login()
        {
            return View();
        }
        [HttpPost]
        public IActionResult Login(string username, string password)
        {
            UserRepository userRepository = new UserRepository();
            User user = userRepository.GetUser(username, password);

            if (user == null)
            {
                ViewBag.ErrorMessage = "Invalid username or password.";
                return View();
            }
            HttpContext.Session.SetInt32("UserId", user.UserId);
            return RedirectToAction("LandingPage", "Welcome");
        }

        public IActionResult LandingPage()
        {
            return View();
        }

    }
}
