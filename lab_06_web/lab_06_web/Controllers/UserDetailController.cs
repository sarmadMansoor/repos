using lab_06_web.Models.Respositories;
using lab_06_web.Models.Interfaces;
using lab_06_web.Models;
using Microsoft.AspNetCore.Mvc;

namespace lab_06_web.Controllers
{
    public class UserDetailController : Controller
    {
        private readonly  IUserServices _userServices;
        public UserDetailController(IUserServices userServices)
        {
            _userServices = userServices;
        }
        public IActionResult Index()
        {
            return View();
        }
        public IActionResult Details()
        {
            int userId = (int)HttpContext.Session.GetInt32("UserId");
            User user=_userServices.GetUserById(userId);
            return View(user);
        }
        public IActionResult Edit()
        {
            int userId = (int)HttpContext.Session.GetInt32("UserId");
            User user = _userServices.GetUserById(userId);
            return View(user);
        }
        [HttpPost]
        public IActionResult Edit(int userId, string username, string billingAddress, string phoneNumber)
        {
            User user = new User
            {
                UserId = userId,
                Username = username,
                BillingAddress = billingAddress,
                PhoneNumber = phoneNumber
            };
            _userServices.UpdateUser(user);
            return RedirectToAction("Details", "UserDetail");
        }

    }
}
