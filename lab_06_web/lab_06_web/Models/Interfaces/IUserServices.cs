using Microsoft.Data.SqlClient;

namespace lab_06_web.Models.Interfaces
{
    public interface IUserServices
    {
        public bool AddUser(User user);

        // READ (Get All Users)
        public List<User> GetAllUsers();

        // READ (Get User by ID)
        public User GetUserById(int userId);

        public User GetUser(string use, string pass);

        // UPDATE
        public bool UpdateUser(User user);

        // DELETE
        public bool DeleteUser(int userId);
 

    }

}
