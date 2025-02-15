using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ORM_Practice
{
    public class Tire
    {
        [Key]
        public int TireId { get; set; } // Primary Key
        public string Brand { get; set; } // Brand of the tire

        public int Size { get; set; } // Size of the tire
        public Car Car { get; set; }
    }
}
