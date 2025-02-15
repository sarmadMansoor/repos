using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ORM_Practice
{
    public class Car
    {
        [Key]
        public int CarId { get; set; } // Primary Key
        public string Model { get; set; } // Model of the car


        // One-to-Many relationship with Tire
        public List<Tire> Tires { get; set; }

        // One-to-One relationship with Person
        //public Person Person { get; set; }
    }
}
