using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System;

namespace Calculator
{
    public class Weather : System.Object
    {
        int weath;
        string city;

        // Constructor
        public Weather(string city="", int weath=0)
        {
            this.city = city;
            this.weath = weath;
        }

        public int Weath
        {
            get { return weath; }
            set { weath = value; }
        }

        public string City
        {
            get { return city; }
            set { city = value; }
        }

        public void Print()
        {
            Console.WriteLine($"City is : {city} and Weather is : {weath}");
        }

        public override string ToString()
        {
            return $"City is : {city} and Weather is : {weath}";
        }
    }
}
