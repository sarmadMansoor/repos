using Microsoft.AspNetCore.Mvc;
using practice.Models;
using System.Diagnostics;

namespace practice.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public string  Index()
        {
            return "Aoa pakistan";
        }

        public string About()
        {
            return "Aoa student";
        }

        public IActionResult Privacy()
        {
            return View();
        }

       // [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        /*public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }*/
    }
}
