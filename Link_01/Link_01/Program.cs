using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Conventions;

namespace Link_01
{
    public class Program
    {
        static void Main(string[] args)
        {
            /*string[] data = { "Pakistan", "Usa", "England", "Spain", "France" };
            var query = data.Where(s => s.StartsWith('P'));
            foreach(var item in query)
            {
                Console.WriteLine(item);
            }*/
            List<Student> students = new List<Student>
            {
                new Student{StudentId=1, StudentName="Ali",RollNumber="bsef22m029"},
                new Student{StudentId=2, StudentName="Zaeem",RollNumber="bsef22m036"},
                new Student{StudentId=3, StudentName="Sani",RollNumber="bsef22m037"}
            };
            var query = students.Where(s => s.StudentName.Equals("Ali"))
                .Select(x=>new {Id=x.StudentId,RollNumber=x.RollNumber});
            foreach(var student in query)
            {
                Console.WriteLine(student.Id);
                Console.WriteLine(student.RollNumber);
            }

            var data = DbContext.Categories
                        .Where(x => x.Name.Equals("Electronics"))
                        .SelectMany(x => x.Products)
                        .ToList();

            /*using (ApplicationContext applicationContext = new ApplicationContext())
            {
                var data = applicationContext.Categories
                                            .Where(x => x.CategoryName.Equals("Electronics"))
                                            .SelectMany(x => x.Product)
                                            .ToList();

                // You can use 'data' here as needed.
            }*/


        }
    }
}
