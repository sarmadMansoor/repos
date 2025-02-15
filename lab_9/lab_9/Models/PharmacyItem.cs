﻿namespace lab_9.Models
{
    public class PharmacyItem
    {
        public int Id { get; set; } 
        public string Name { get; set; }
        public string Description { get; set; } 
        public string Category { get; set; } 
        public decimal Price { get; set; }
        public int Quantity { get; set; }
        public string Image { get; set; } 
    }

}
