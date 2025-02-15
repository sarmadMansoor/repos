using Microsoft.Data.SqlClient;

namespace lab_06_web.Models.Respositories
{
    public class MenuRepository
    {
        static private string connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=lab_06;Integrated Security=True;";

        public List<Menu> GetSearchData(string qu)
        {
            List<Menu> menuItems = new List<Menu>();
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Menu where ItemName like @i";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@i", "%"+qu+"%");
                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Menu menu = new Menu
                    {
                        ItemId = (int)reader["ItemId"],
                        ItemName = reader["ItemName"].ToString(),
                        Description = reader["Description"].ToString(),
                        Price = float.Parse(reader["Price"].ToString()),
                        Availability = reader["Availability"].ToString()
                    };
                    menuItems.Add(menu);
                }
            }
            return menuItems;
        }
        // CREATE
        public bool AddMenuItem(Menu menu)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "INSERT INTO Menu (ItemName, Description, Price, Availability) VALUES (@ItemName, @Description, @Price, @Availability)";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@ItemName", menu.ItemName);
                cmd.Parameters.AddWithValue("@Description", menu.Description);
                cmd.Parameters.AddWithValue("@Price", menu.Price);
                cmd.Parameters.AddWithValue("@Availability", menu.Availability);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // READ (Get All Menu Items)
        public List<Menu> GetAllMenuItems()
        {
            List<Menu> menuItems = new List<Menu>();
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Menu";
                SqlCommand cmd = new SqlCommand(query, conn);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Menu menu = new Menu
                    {
                        ItemId = (int)reader["ItemId"],
                        ItemName = reader["ItemName"].ToString(),
                        Description = reader["Description"].ToString(),
                        Price = float.Parse(reader["Price"].ToString()),
                        Availability = reader["Availability"].ToString()
                    };
                    menuItems.Add(menu);
                }
            }
            return menuItems;
        }

        // READ (Get Menu Item by ID)
        public Menu GetMenuItemById(int itemId)
        {
            Menu menu = null;
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Menu WHERE ItemId = @ItemId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@ItemId", itemId);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    menu = new Menu
                    {
                        ItemId = (int)reader["ItemId"],
                        ItemName = reader["ItemName"].ToString(),
                        Description = reader["Description"].ToString(),
                        Price = float.Parse(reader["Price"].ToString()),
                        Availability = reader["Availability"].ToString()
                    };
                }
            }
            return menu;
        }

        // UPDATE
        public bool UpdateMenuItem(Menu menu)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "UPDATE Menu SET ItemName = @ItemName, Description = @Description, Price = @Price, Availability = @Availability WHERE ItemId = @ItemId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@ItemId", menu.ItemId);
                cmd.Parameters.AddWithValue("@ItemName", menu.ItemName);
                cmd.Parameters.AddWithValue("@Description", menu.Description);
                cmd.Parameters.AddWithValue("@Price", menu.Price);
                cmd.Parameters.AddWithValue("@Availability", menu.Availability);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // DELETE
        public bool DeleteMenuItem(int itemId)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "DELETE FROM Menu WHERE ItemId = @ItemId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@ItemId", itemId);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }
    }
}
