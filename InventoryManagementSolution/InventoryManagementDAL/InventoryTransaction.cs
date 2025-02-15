using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryManagementDAL
{
    public class InventoryTransaction
    {
        [Key]
        public int TransactionID { get; set; }

        [Required]
        public int ProductID { get; set; }

        [Required]
        public string TransactionType { get; set; }

        [Required]
        public int Quantity { get; set; }

        [Required]
        public DateTime TransactionDate { get; set; }
        public Product Product { get; set; }
    }
}
