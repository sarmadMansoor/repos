using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security.Cryptography;

namespace ConsoleApp3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //byte oriented stream 
            /*char a='A';
            FileStream fin = new FileStream("file.txt",FileMode.Create);
            for (int i = 0; i <= 25; i++) 
            {
                fin.WriteByte((byte)a);
                a++;
            }
            fin.Close();*/

            /* FileStream fin = new FileStream("file.txt", FileMode.Open);
             FileStream newFin = new FileStream("Newfile.txt", FileMode.Create);
             int data =fin.ReadByte();
             while (data!=-1)
             {
                newFin.WriteByte((byte)data);
                 data = fin.ReadByte();
             }
             fin.Close();
             newFin.Close();*/


            // character oriented stream 
            /*FileStream fin  = new FileStream("file.txt", FileMode.Open);
            StreamWriter streamWriter = new StreamWriter(fin);
            streamWriter.WriteLine("good morning");
            streamWriter.Close();
            fin.Close();*/


            /*FileStream fin = new FileStream("file.txt", FileMode.Open);
            StreamReader streamRead= new StreamReader(fin);
            Console.WriteLine(streamRead.ReadLine());
            Console.WriteLine(streamRead.ReadLine());
            streamRead.Close();
            fin.Close();*/














            /*Product product = new Product();
            Console.WriteLine("Enter the id : ");
            product.Id=int.Parse(Console.ReadLine());

            Console.WriteLine("Enter the product name : ");
            product.Name=Console.ReadLine();

            Console.WriteLine("Enter the product description : ");
            product.Description = Console.ReadLine();


            ProductService service = new ProductService();
            service.add(product);*/

            /* ProductService service = new ProductService();

             Product product = service.get(10);
             if (product != null)
             {
                 Console.WriteLine($"{product.Id} ,{product.Name}  , {product.Description}");

             }
             else
             {
                 Console.WriteLine("not Found");
             }*/



            /*ProductService service = new ProductService();
            List<Product> products = service.getAllProducts();

            foreach (Product product in products)
            {
                Console.WriteLine("ID: " + product.Id);
                Console.WriteLine("Name: " + product.Name);
                Console.WriteLine("Description: " + product.Description);
                Console.WriteLine("----------------------------");
            }*/


            /*StreamWriter streamWriter = new StreamWriter("test.txt", append: true);
            double number = 100.3;
            for(int i = 0;i < 10; i++)
            {
                streamWriter.Write(number);
                streamWriter.Write(',');
                number++;
            }
            streamWriter.Close();*/

            /*StreamReader streamReader = new StreamReader("test.txt");
            string data =streamReader.ReadToEnd();
            string[] datinfo=data.Split(',');
            for(int i=0;i<datinfo.Length;i++)
            {
                double num = double.Parse(datinfo[i]);
                Console.WriteLine(num);
            }
            streamReader.Close();*/
            ProductService productService = new ProductService();
            productService.deleteRecord(1);
        }
    }
}
