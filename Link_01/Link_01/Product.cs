using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Link_01
{
    public class Product
    {
        public int Id { get; set; }
        public string Name { get; set; }

        // Navigation property
        public Category Category { get; set; }  // Make sure this is public
    }
}
