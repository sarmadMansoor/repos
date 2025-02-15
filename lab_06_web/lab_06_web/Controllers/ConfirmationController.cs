using Microsoft.AspNetCore.Mvc;

namespace lab_06_web.Controllers
{
    public class ConfirmationController : Controller
    {
        public IActionResult Index(string message)
        {
            if(message == null)
            {
                ViewBag.Message = "Your task is done"; // Optional: Pass it to the view

            }
            else
            {
                ViewBag.Message = message; // Optional: Pass it to the view
            }
            return View();
        }
    }
}
