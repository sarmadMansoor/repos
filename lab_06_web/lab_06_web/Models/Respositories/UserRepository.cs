using Microsoft.Data.SqlClient;
using lab_06_web.Models.Interfaces;
namespace lab_06_web.Models.Respositories
{
    public class UserRepository:IUserServices
    {
        static private string connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=lab_06;Integrated Security=True;";
        public bool AddUser(User user)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "INSERT INTO Users (Username, Password, BillingAddress, PhoneNumber) VALUES (@Username, @Password, @BillingAddress, @PhoneNumber)";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@Username", user.Username);
                cmd.Parameters.AddWithValue("@Password", user.Password);
                cmd.Parameters.AddWithValue("@BillingAddress", user.BillingAddress);
                cmd.Parameters.AddWithValue("@PhoneNumber", user.PhoneNumber);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // READ (Get All Users)
        public List<User> GetAllUsers()
        {
            List<User> users = new List<User>();
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Users";
                SqlCommand cmd = new SqlCommand(query, conn);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    User user = new User
                    {
                        UserId = (int)reader["UserId"],
                        Username = reader["Username"].ToString(),
                        Password = reader["Password"].ToString(),
                        BillingAddress = reader["BillingAddress"].ToString(),
                        PhoneNumber = reader["PhoneNumber"].ToString()
                    };
                    users.Add(user);
                }
            }
            return users;
        }

        // READ (Get User by ID)
        public User GetUserById(int userId)
        {
            User user = null;
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Users WHERE UserId = @UserId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", userId);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    user = new User
                    {
                        UserId = (int)reader["UserId"],
                        Username = reader["Username"].ToString(),
                        Password = reader["Password"].ToString(),
                        BillingAddress = reader["BillingAddress"].ToString(),
                        PhoneNumber = reader["PhoneNumber"].ToString()
                    };
                }
            }
            return user;
        }

        public User GetUser(string use ,string pass)
        {
            User user = null;
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Users WHERE Username = @U and password = @p";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@U", use);
                cmd.Parameters.AddWithValue("@p", pass);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    user = new User
                    {
                        UserId = (int)reader["UserId"],
                        Username = reader["Username"].ToString(),
                        Password = reader["Password"].ToString(),
                        BillingAddress = reader["BillingAddress"].ToString(),
                        PhoneNumber = reader["PhoneNumber"].ToString()
                    };
                }
            }
            return user;
        }

        // UPDATE
        public bool UpdateUser(User user)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "UPDATE Users SET Username = @Username, BillingAddress = @BillingAddress, PhoneNumber = @PhoneNumber WHERE UserId = @UserId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", user.UserId);
                cmd.Parameters.AddWithValue("@Username", user.Username);
                cmd.Parameters.AddWithValue("@BillingAddress", user.BillingAddress);
                cmd.Parameters.AddWithValue("@PhoneNumber", user.PhoneNumber);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // DELETE
        public bool DeleteUser(int userId)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "DELETE FROM Users WHERE UserId = @UserId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", userId);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }
    }

}
