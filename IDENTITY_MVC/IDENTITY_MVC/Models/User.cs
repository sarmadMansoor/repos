using Microsoft.AspNetCore.Identity;

namespace IDENTITY_MVC.Models
{
    public class User : IdentityUser
    { 
        public string  City { get; set; }
    }
}
