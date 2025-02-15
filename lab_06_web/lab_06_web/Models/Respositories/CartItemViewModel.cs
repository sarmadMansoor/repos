namespace lab_06_web.Models.Respositories
{
    public class CartItemViewModel
    {
        public int CartId { get; set; }
        public int UserId { get; set; }
        public int ItemId { get; set; }
        public int Quantity { get; set; }

        // Menu details
        public string ItemName { get; set; }
        public float Price { get; set; }
        public string Description { get; set; }
    }

}
