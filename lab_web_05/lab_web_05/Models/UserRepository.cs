using Microsoft.Data.SqlClient;
using System.Data;
using System.Globalization;
namespace lab_web_05.Models
{
    public class UserRepository
    {
        static private string connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Lab_05;Integrated Security=True;";



        static public List<User> GetAllUsers()
        {
            List<User> users = new  List<User>();


            SqlConnection sqlConnection = new SqlConnection(connString);
            sqlConnection.Open();
            string query = "select * from users";
            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            SqlDataReader reader = sqlCommand.ExecuteReader();
            while (reader.Read())
            {
                User user = new User();
                user.Id = reader.GetInt32(0);
                user.Name = reader.GetString(1);
                user.Email = reader.GetString(2);
                user.Password = reader.GetString(3);
                user.CreatedDate = (DateTime)reader.GetDateTime(4);
                users.Add(user);
            }
            return users;
        }
        public User GetUserByEmailAndPassword(string email, string password)
        {
            User user = null;


            SqlConnection sqlConnection = new SqlConnection(connString);
            sqlConnection.Open();
            string query = "select * from users where email =@em and password =@ps";
            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            sqlCommand.Parameters.AddWithValue("@em", email);
            sqlCommand.Parameters.AddWithValue("@ps", password);
            SqlDataReader reader = sqlCommand.ExecuteReader();
            if (reader.Read())
            {
                user= new User();
                user.Id = reader.GetInt32(0);
                user.Name = reader.GetString(1);
                user.Email = reader.GetString(2);
                user.Password = reader.GetString(3);
                user.CreatedDate = (DateTime)reader.GetDateTime(4);
            }
            return user;
        }
        public bool IsEmailExists(string email)
        {
            SqlConnection sqlConnection = new SqlConnection(connString);
            sqlConnection.Open();
            string query = "select * from users where email =@em ";
            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            sqlCommand.Parameters.AddWithValue("@em", email);
            SqlDataReader reader = sqlCommand.ExecuteReader();
            if (reader.HasRows)
            {
                return true;
            }
            return false;
        }
        public bool AddUser(User user)
        {
            SqlConnection sqlConnection = new SqlConnection(connString);
            sqlConnection.Open();
            string query = "insert into  users(Name ,Email ,Password ,CreatedDate) values (@nam ,@em ,@ps,@cd)";
            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            sqlCommand.Parameters.AddWithValue("@em", user.Email);
            sqlCommand.Parameters.AddWithValue("@ps", user.Password);
            sqlCommand.Parameters.AddWithValue("@nam", user.Name);
            sqlCommand.Parameters.AddWithValue("@cd", user.CreatedDate);
            int effect = sqlCommand.ExecuteNonQuery();
            if (effect > 0)
            {
                return true;
            }
            return false;
        }
        public bool UpdateUser(User user)
        {
            SqlConnection sqlConnection = new SqlConnection(connString);
            sqlConnection.Open();
            string query = "update   users set name = @nam, password =@ps where email =@em ";
            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            sqlCommand.Parameters.AddWithValue("@em", user.Email);
            sqlCommand.Parameters.AddWithValue("@ps", user.Password);
            sqlCommand.Parameters.AddWithValue("@nam", user.Name);
            int effect = sqlCommand.ExecuteNonQuery();
            if (effect > 0)
            {
                return true;
            }
            return false;
        }
        public bool  DeleteUser(string email)
        {
            SqlConnection sqlConnection = new SqlConnection(connString);
            sqlConnection.Open();
            string query = "delete from   users where email = @e";
            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            sqlCommand.Parameters.AddWithValue("@e", email);
            int effect = sqlCommand.ExecuteNonQuery();
            if (effect > 0)
            {
                return true;
            }
            return false;
        }

    }
}
