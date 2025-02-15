using Microsoft.EntityFrameworkCore;
using Orm_Ef;

namespace Orm_Ef
{
    internal class Program
    {
        static void CreateStudent(Student s1)
        {
            if(s1==null)
            {
                return;
            }
            using (var context = new SchoolContext())
            {
                
                context.Students.Add(s1);
                context.SaveChanges();
            }
        }

        static void ReadStudent(int id)
        {
            using (var context = new SchoolContext())
            {
                var student = context.Students.Include(s => s.Address).FirstOrDefault(s => s.Id == id);

                if (student != null)
                {
                    Console.WriteLine($"Name: {student.Name}, Address: {student.Address.Street}, {student.Address.City}");
                }
                else
                {
                    Console.WriteLine("No Record Found!");
                }
            }
        }

        static void UpdateStudent(Student d)
        {
            using (var context = new SchoolContext())
            {
                var student = context.Students.Include(s=>s.Address).FirstOrDefault(s => s.Id == d.Id);
                if (student != null)
                {
                    student.Name = d.Name;
                    student.Address.Street = d.Address.Street;
                    student.Address.City = d.Address.City;
                    context.SaveChanges();
                }
            }
        }



        static void DeleteStudent(int id)
        {
            using (var context = new SchoolContext())
            {

                var student = context.Students.FirstOrDefault(s => s.Id == id);
                if (student != null)
                {
                    context.Students.Remove(student);
                    context.SaveChanges();
                }
            }
        }

        static void InsertMultipleStudents()
        {
            using (var context = new SchoolContext())
            {
                var students = new[]
                {
                       new Student { Name = "ahmad", Address = new Address { Street = "23 Khalid", City = "Layyah" } },
                       new Student { Name = "fasial", Address = new Address { Street = "101 multan", City = "Multan" } }
                   };
                context.Students.AddRange(students);
                context.SaveChanges();
            }
        }

        static void CheckRelation(int id)
        {
            using (var context = new SchoolContext())
            {
                var student = context.Students.Include(s => s.Address).FirstOrDefault(s => s.Id == id);
                Console.WriteLine($"Student: {student.Name}, Address: {student.Address.Street}, {student.Address.City}");
            }
        }


        static void Main(string[] args)
        {
            var student = new Student
            {
                Name = "Ali",
                Address = new Address { Street = "123 layyah", City = "layyah" }
            };
            // CreateStudent(student);
            //ReadStudent(1);
             student.Id = 3;
             UpdateStudent(student);
          //  DeleteStudent(2);

           // InsertMultipleStudents();
           // CheckRelation(2);
        }
    }
}





























