using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*Task number 1*/

            /* Console.WriteLine("Enter your name:");
             string name = Console.ReadLine();
             Console.WriteLine("Enter your age:");
             int age = int.Parse(Console.ReadLine());
             while( age <= 0 ) 
             {
                 Console.WriteLine("Enter correct age: ");
                 age = int.Parse(Console.ReadLine());
             }
             Console.WriteLine("Enter your Course:");
             string course = Console.ReadLine();
             Console.WriteLine("Enter your GPA:");
             float GPA = float.Parse(Console.ReadLine());
             while (GPA < 0 ||  GPA>4)
             {
                 Console.WriteLine("Enter CORRECT GPA: ");
                 GPA = int.Parse(Console.ReadLine());
             }

             Console.WriteLine("Hello " + name + ',');
             Console.WriteLine("age: " + age + ',');
             Console.WriteLine("Course: " + course + ',');
             Console.WriteLine("GPA " + GPA);*/


            //task number 2
            



            //task number 3


            /*Console.WriteLine("Enter a number: ");
            int num = int.Parse(Console.ReadLine());
            while (num < 0) 
            {
                Console.WriteLine("Enter +ive number : ");
                num=int.Parse(Console.ReadLine()); 
            }
            if (num % 2 == 0)
            {
                Console.WriteLine("Number is Even");
            }
            else
            {
                Console.WriteLine("Number is odd");
            }*/

            Weather w = new Weather("Layyah",100);
            /*w.Weath = 10;
            w.City = "lhr";*/
            Console.WriteLine(w);


        }
    }
}
