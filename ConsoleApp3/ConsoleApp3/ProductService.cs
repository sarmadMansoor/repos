using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Globalization; 
using System.Runtime.InteropServices.ComTypes;

namespace ConsoleApp3
{
    internal class ProductService
    {
        private  bool isPresent(int id)
        {
            StreamReader streamReader = new StreamReader("products.txt");
            string data = streamReader.ReadLine();
            while (data != null)
            {
                string[] dataInfo = data.Split(',');
                if (int.Parse(dataInfo[0])==id)
                {
                    streamReader.Close();
                    return true;
                }
                data= streamReader.ReadLine();
            }
            streamReader.Close();
            return false;

        }
        public void deleteRecord(int id)
        {
            StreamReader streamreader = new StreamReader("products.txt");
            string data = streamreader.ReadLine();
            StreamWriter streamWriter = new StreamWriter("test.txt", true);
            while (data != null)
            {
                string[] dataInfo = data.Split(',');
                if (int.Parse(dataInfo[0])!=id)
                {
                    streamWriter.WriteLine(data);
                }
                data = streamreader.ReadLine();
            }
            streamreader.Close();
            streamWriter.Close();
            File.Delete("products.txt");
            File.Move("test.txt", "products.txt");
        }
        public void add(Product prod)
        {
          //  FileStream fin = new FileStream("products.txt", FileMode.Append);
            //StreamWriter streamWriter =new StreamWriter(fin);
            if (!isPresent(prod.Id))
            {
                StreamWriter streamWriter = new StreamWriter("products.txt", append: true);
                string data = $"{prod.Id},{prod.Name},{prod.Description}";
                streamWriter.WriteLine(data);
                streamWriter.Close();
            }
            //fin.Close();
        }
   
        public Product get(int id)
        {
            Product product = null;
            StreamReader streamReader = new StreamReader("products.txt");
            string dataInfo = streamReader.ReadLine();
            bool flag = true;
            while (flag && dataInfo != null)
            {
                string[] dataArr = dataInfo.Split(',');
                int dataID = int.Parse(dataArr[0]);
                if (dataID == id)
                {
                    product = new Product();
                    product.Id = dataID;
                    product.Name = dataArr[1];
                    product.Description = dataArr[2];
                    flag = false;
                }
                dataInfo = streamReader.ReadLine();
            }
            streamReader.Close();
           
            return product;

        }
        public List<Product> getAllProducts()
        {
            List<Product> products = new List<Product>();
            StreamReader streamReader = new StreamReader("products.txt");
            string dataInfo = streamReader.ReadLine();

            while (dataInfo != null)
            {
                string[] dataArr = dataInfo.Split(',');
                Product product = new Product();
                product.Id = int.Parse(dataArr[0]);
                product.Name = dataArr[1];
                product.Description = dataArr[2];
                products.Add(product);
                dataInfo = streamReader.ReadLine();
            }

            streamReader.Close();
            return products;
        }
        public override string ToString()
        {
            return "This is an intermediate class providing services about product liberary.";
        }


    }
}
