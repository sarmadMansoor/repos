using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Data.SqlClient;
using System.Text.Json;
using System.Data;
namespace ConsoleApp2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string name = "sarmad";
            string format = JsonSerializer.Serialize(name);
            Console.WriteLine(format);
        }
    }
}
