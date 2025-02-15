using Microsoft.Data.SqlClient;

namespace lab_06_web.Models.Respositories
{
    public class ReservationRespository
    {
        static private string connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=lab_06;Integrated Security=True;";

        // CREATE: Add a new reservation
        public bool AddReservation(Reservation reservation)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "INSERT INTO Reservations (UserId, DateTime, GuestCount) VALUES (@UserId, @DateTime, @GuestCount)";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", reservation.UserId);
                cmd.Parameters.AddWithValue("@DateTime", reservation.DateTime);
                cmd.Parameters.AddWithValue("@GuestCount", reservation.GuestCount);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // READ: Get all reservations for a specific user
        public List<Reservation> GetReservationsByUserId(int userId)
        {
            List<Reservation> reservations = new List<Reservation>();
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Reservations WHERE UserId = @UserId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@UserId", userId);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Reservation reservation = new Reservation
                    {
                        ReservationId = (int)reader["ReservationId"],
                        UserId = (int)reader["UserId"],
                        DateTime = (DateTime)reader["DateTime"],
                        GuestCount = (int)reader["GuestCount"]
                    };
                    reservations.Add(reservation);
                }
            }
            return reservations;
        }

        // READ: Get a single reservation by ReservationId
        public Reservation GetReservationById(int reservationId)
        {
            Reservation reservation = null;
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "SELECT * FROM Reservations WHERE ReservationId = @ReservationId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@ReservationId", reservationId);

                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    reservation = new Reservation
                    {
                        ReservationId = (int)reader["ReservationId"],
                        UserId = (int)reader["UserId"],
                        DateTime = (DateTime)reader["DateTime"],
                        GuestCount = (int)reader["GuestCount"]
                    };
                }
            }
            return reservation;
        }

        // UPDATE: Update reservation details
        public bool UpdateReservation(Reservation reservation)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "UPDATE Reservations SET DateTime = @DateTime, GuestCount = @GuestCount WHERE ReservationId = @ReservationId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@ReservationId", reservation.ReservationId);
                cmd.Parameters.AddWithValue("@DateTime", reservation.DateTime);
                cmd.Parameters.AddWithValue("@GuestCount", reservation.GuestCount);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }

        // DELETE: Delete a reservation
        public bool DeleteReservation(int reservationId)
        {
            using (SqlConnection conn = new SqlConnection(connString))
            {
                string query = "DELETE FROM Reservations WHERE ReservationId = @ReservationId";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@ReservationId", reservationId);

                conn.Open();
                int result = cmd.ExecuteNonQuery();
                return result > 0;
            }
        }
    }
}
