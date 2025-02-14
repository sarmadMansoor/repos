using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    internal class Product
    {
        private int id;
        private string name;
        private string description;
        public int Id { get { return id; } set {id=value; } }
        public string Name { get{ return name; } set { name= value; } }
        public string Description { get; set; }
        public override string ToString()
        {
            return $"ID: {id}, Name: {name}, Description: {description}";
        }


    }
}
