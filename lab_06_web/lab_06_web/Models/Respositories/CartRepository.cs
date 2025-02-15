using Microsoft.Data.SqlClient;

namespace lab_06_web.Models.Respositories
{
    public class CartRepository
    {
        static private string connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=lab_06;Integrated Security=True;";

        // CREATE: Add item to Cart
        public bool AddToCart(Cart cart)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "INSERT INTO Cart (UserId, ItemId, Quantity) VALUES (@UserId, @ItemId, @Quantity)";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", cart.UserId);
                cmd.Parameters.AddWithValue("@ItemId", cart.ItemId);
                cmd.Parameters.AddWithValue("@Quantity", cart.Quantity);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // READ: Get All Items in Cart by UserId
        public List<Cart> GetCartItemsByUserId(int userId)
        {
            List<Cart> cartItems = new List<Cart>();
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Cart WHERE UserId = @UserId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", userId);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Cart cart = new Cart
                    {
                        CartId = (int)reader["CartId"],
                        UserId = (int)reader["UserId"],
                        ItemId = (int)reader["ItemId"],
                        Quantity = (int)reader["Quantity"]
                    };
                    cartItems.Add(cart);
                }
            }
            return cartItems;
        }
        public bool isPresent(int userId ,int itemId)
        {
            bool status = false;
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Cart WHERE UserId = @UserId and ItemId=@i";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", userId);
                cmd.Parameters.AddWithValue("@i", itemId);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                if(reader.HasRows)
                {
                    status = true;
                }
            }
            return status;
        }
        public int GetQuantity(int userId,int itemId)
        {
            int quan = 0;
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Cart  WHERE UserId = @UserId and ItemId=@i";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", userId);
                cmd.Parameters.AddWithValue("@i", itemId);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    quan = (int)reader["Quantity"];

                }
            }
            return quan;
        }
        public bool UpdateSingleCart(int userId,int itemId, int quantity)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "UPDATE Cart SET Quantity = @Quantity WHERE UserId = @UserId and ItemId=@i";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", userId);
                cmd.Parameters.AddWithValue("@Quantity", quantity);
                cmd.Parameters.AddWithValue("@i", itemId);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // READ: Get Single Cart Item by CartId
        public Cart GetCartItemById(int cartId)
        {
            Cart cart = null;
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Cart WHERE CartId = @CartId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@CartId", cartId);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    cart = new Cart
                    {
                        CartId = (int)reader["CartId"],
                        UserId = (int)reader["UserId"],
                        ItemId = (int)reader["ItemId"],
                        Quantity = (int)reader["Quantity"]
                    };
                }
            }
            return cart;
        }

        // UPDATE: Update Cart Item Quantity
        public bool UpdateCartItemQuantity(int cartId, int quantity)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "UPDATE Cart SET Quantity = @Quantity WHERE CartId = @CartId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@CartId", cartId);
                cmd.Parameters.AddWithValue("@Quantity", quantity);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // DELETE: Remove Item from Cart
        public bool RemoveFromCart(int cartId)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "DELETE FROM Cart WHERE CartId = @CartId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@CartId", cartId);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // DELETE: Clear Cart for a Specific User
        public bool ClearCart(int userId)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "DELETE FROM Cart WHERE UserId = @UserId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", userId);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        public bool DeleteCart(int cartid)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "DELETE FROM Cart WHERE CartId = @c";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@c", cartid);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }
    }
}
