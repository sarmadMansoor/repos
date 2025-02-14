using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace f21_lab1
{
    internal class Person
    {
        string name;
        int age;
        List<string> email;
        public string Name { get; set; }
        public int Age { get; set; }
        public List<string> Email { get; set; }
        public Person(string name ,int age )
        {
            Name = name;
            Age = age;
            Email = new List<string>();
        }
    }
}
