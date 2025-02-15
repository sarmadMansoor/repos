using Microsoft.AspNetCore.Mvc;
using lab_06_web.Models;
using lab_06_web.Models.Respositories;
namespace lab_06_web.Controllers
{
    public class ReservationController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
        [HttpPost]
        public IActionResult Index(DateTime DateTime ,int GuestCount)
        {
            ReservationRespository   reservationRespository = new ReservationRespository();
            int userId = (int)HttpContext.Session.GetInt32("UserId");
            Reservation reservation = new Reservation
            {
                DateTime = DateTime,
                GuestCount = GuestCount,
                UserId = userId
            };
            reservationRespository.AddReservation(reservation);
/*            TempData["message"]= "Your Reservation has been done! ";
*/            return RedirectToAction("Index", "Confirmation");    
        }
    }
}
