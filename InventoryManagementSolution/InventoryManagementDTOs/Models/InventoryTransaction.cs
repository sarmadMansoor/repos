using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryManagementDTOs.Models
{
    public class InventoryTransaction
    {
        [Key]
        public int TransactionID { get; set; }
        public int ProductID { get; set; }
        public string TransactionType { get; set; } 
        public int Quantity { get; set; }
        public DateTime TransactionDate { get; set; } 
    }
}
