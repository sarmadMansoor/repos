using lab_06_web.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace lab_06_web.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly IWebHostEnvironment Environment;

        public HomeController(ILogger<HomeController> logger, IWebHostEnvironment environment)
        {
            _logger = logger;
            Environment = environment;
        }

        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Index(List<IFormFile> postedFiles)
        {
            string wwwpath=this.Environment.WebRootPath;
            string pathWithFolder = Path.Combine(wwwpath, "Uploads");
            if(!Directory.Exists(pathWithFolder))
            {
                Directory.CreateDirectory(pathWithFolder);
            }
            foreach(var file in postedFiles)
            {
                string fileName = Path.GetFileName(file.FileName);
                string pathWithFileName= Path.Combine(pathWithFolder, fileName);
                using (FileStream stream = new FileStream(pathWithFileName, FileMode.Create))
                {
                    file.CopyTo(stream);
                }
            }
            return View();
        }
        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
