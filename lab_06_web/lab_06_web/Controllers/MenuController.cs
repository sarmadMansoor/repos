using Microsoft.AspNetCore.Mvc;
using lab_06_web.Models;
using lab_06_web.Models.Respositories;
namespace lab_06_web.Controllers
{
    public class MenuController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
        public IActionResult MenuForDelivery()
        {
            MenuRepository menuRepository = new MenuRepository();  
            List<Menu> AllProducts= menuRepository.GetAllMenuItems();
            return View(AllProducts);
        }
        public IActionResult SearchMenu(string query)
        {
            MenuRepository menuRepository = new MenuRepository();
            List<Menu> all= menuRepository.GetSearchData(query);
            return View("MenuForDelivery", all);
        }

    }
}
