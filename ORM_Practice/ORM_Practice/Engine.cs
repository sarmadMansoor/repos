using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Text;
using System.Threading.Tasks;

namespace ORM_Practice
{
    public class Engine
    {
        [Key] // Primary Key
        public int EngineId { get; set; }
        public string Type { get; set; } // Type of engine, e.g., V6, V8

        public int HorsePower { get; set; } // Horsepower of the engine

        // Navigation property (One-to-One relationship with Car)
        public Car Car { get; set; }
    }
}
