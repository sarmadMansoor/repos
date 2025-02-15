namespace lab_06_web.Models
{
    public class Reservation
    {
        public int ReservationId { get; set; }
        public int UserId { get; set; }
        public DateTime DateTime { get; set; }
        public int GuestCount { get; set; }
    }
}
