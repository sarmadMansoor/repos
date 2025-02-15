using Microsoft.AspNetCore.Mvc;
using lab_web_05.Models;
using Microsoft.AspNetCore.Components;
using System.Text.Json;
using System.Security;
namespace lab_web_05.Controllers
{
    public class AccountController : Controller
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
        public IActionResult Login(string email, string password)
        {
            UserRepository userRepository = new UserRepository();
            User user = userRepository.GetUserByEmailAndPassword(email, password);

            if (user != null)
            {
                ViewBag.Message = "Login successful!";
                ViewBag.User = user;

                CookieOptions cookieOptions = new CookieOptions
                {
                    Secure = true,
                    Expires = DateTime.Now.AddDays(1)
                };

                List<string> emails = new List<string>();

                if (!HttpContext.Request.Cookies.ContainsKey("UserEmail"))
                {
                    // If the cookie does not exist, create a new list and add the email
                    emails.Add(email);
                    string format = JsonSerializer.Serialize(emails);
                    HttpContext.Response.Cookies.Append("UserEmail", format, cookieOptions);
                }
                else
                {
                    // If the cookie exists, retrieve and deserialize it
                    string format = HttpContext.Request.Cookies["UserEmail"];
                   
                        // Attempt to deserialize the cookie value
                        emails = JsonSerializer.Deserialize<List<string>>(format);
                   

                    // Check if the email is not already in the list
                    if (!emails.Contains(email))
                    {
                        emails.Add(email);
                        string emailsFormat = JsonSerializer.Serialize(emails);
                        HttpContext.Response.Cookies.Append("UserEmail", emailsFormat, cookieOptions);
                    }
                }
            }
            else
            {
                ViewBag.Message = "Login failed. Please check your email and password.";
            }

            ViewBag.Email = email;
            return View();
        }


        public IActionResult Logout()
        {
            // Loop through all cookies and delete each one
            foreach (var cookie in Request.Cookies.Keys)
            {
                Response.Cookies.Delete(cookie);
            }

            // Redirect to the login view
            return RedirectToAction("Login");
        }



        public IActionResult Register()
        {
            return View();
        }
        [HttpPost]
        public IActionResult Register(string email,string name,string password)
        {
            bool status = false;
            UserRepository userRepo = new UserRepository(); 
            if (!userRepo.IsEmailExists(email))
            {
                User user = new User() { Email = email, Name = name, Password = password, CreatedDate = System.DateTime.Now };
                if (userRepo.AddUser(user)==true)
                {
                    status = true;
                }
                
            }
            object message =String.Empty;
            if(status == true)
            {
                message = $"User name : {name} is added successfully";
            }
            else
            {
                message = $"User with this email is already exit .Try again";
            }
            //ViewBag.message = message;
            return View(message);
        }
        

        public IActionResult UserDetails()
        {
            return View();
        }
        [HttpPost]
        public IActionResult UserDetails(string email, string password)
        {
            UserRepository userRepo = new UserRepository();
            User user = userRepo.GetUserByEmailAndPassword(email, password);

            if (user != null)
            {
                ViewBag.User = user;
            }
            else
            {
                ViewBag.Message = "User not found.";
            }

            return View();
        }
        public IActionResult EditUser()
        {
            return View();
        }

        [HttpPost]
        public IActionResult EditUser(string email, string name, string password)
        {
            UserRepository userRepo = new UserRepository();
            if (userRepo.IsEmailExists(email))
            {
                User user = new User() { Name = name, Email = email, Password = password };
                if (userRepo.UpdateUser(user))
                {
                    // Fetch the updated user from the database to ensure all fields are populated correctly
                    user = userRepo.GetUserByEmailAndPassword(email, password);
                    ViewBag.User = user;
                    ViewBag.Message = "User updated successfully!";
                }
                else
                {
                    ViewBag.Message = "Failed to update user. Please try again.";
                }
            }
            else
            {
                ViewBag.Message = "Email does not exist. Try again.";
            }

            return View();
        }

        public IActionResult DeleteUser()
        {
            return View();
        }
        [HttpPost]
        public IActionResult DeleteUser(string email)
        {
            UserRepository userRepo = new UserRepository();
            object deletedMessge = null;
            if (userRepo.DeleteUser(email))
            {
                deletedMessge = $"User Email {email} is deleted successfully!";
            }
            else
            {
                deletedMessge = $"Failed to delete user with Email {email}.";
            }
            return View(deletedMessge);
        }

        public IActionResult ViewUsers()
        {

            List<User> users = UserRepository.GetAllUsers();
            return View(users);
        }

    }
}
