using lab_9.Models;
using Microsoft.AspNetCore.Mvc;

namespace lab_9.Controllers
{
    public class PharmacyController : Controller
    {
        private readonly IPharmacyService _pharmacyService;

        public PharmacyController(IPharmacyService pharmacyService)
        {
            _pharmacyService = pharmacyService;
        }

        public IActionResult Index()
        {
            var items = _pharmacyService.GetAllItems();
            return View(items);
        }

        public IActionResult Create()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Create(PharmacyItem item)
        {
            if (ModelState.IsValid)
            {
                _pharmacyService.AddItem(item);
                return RedirectToAction("Index");
            }
            return View(item);
        }

        public IActionResult Details(int id)
        {
            var item = _pharmacyService.GetItemById(id);
            if (item == null)
            {
                return NotFound();
            }
            return View(item);
        }
    }
    
}
