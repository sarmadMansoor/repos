using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;

namespace SchoolManagement
{
    // Define the Student entity
    public class Student
    {
        public int StudentId { get; set; }
        public string Name { get; set; }
        public List<Course> Courses { get; set; } // Many-to-many relationship with Course
    }

    // Define the Course entity
    public class Course
    {
        public int CourseId { get; set; }
        public string Title { get; set; }
        public List<Student> Students { get; set; } // Many-to-many relationship with Student
    }

    // SchoolContext to manage the database
    public class SchoolContext : DbContext
    {
        public DbSet<Student> Students { get; set; }
        public DbSet<Course> Courses { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            // Configure SQL Server as the database provider
            optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Many_to_Many_Orm;Integrated Security=True;Connect Timeout=30;Encrypt=False;Trust Server Certificate=False;Application Intent=ReadWrite;Multi Subnet Failover=False"); // Replace with your connection string
        }
    }

    // StudentManager to handle CRUD operations
    public class StudentManager
    {
        private readonly SchoolContext _context;

        public StudentManager()
        {
            _context = new SchoolContext();
        }

        // Update a specific course for a student
        public void UpdateStudentCourse(int studentId, int courseId, string newCourseTitle)
        {
            // Retrieve the student and include their courses
            var student = _context.Students
                                            .FirstOrDefault(s => s.StudentId == studentId);

            if (student != null)
            {
                // Find the specific course the student is enrolled in
                var courseToUpdate = student.Courses.FirstOrDefault(c => c.CourseId == courseId);

                if (courseToUpdate != null)
                {
                    // Update the course details
                    courseToUpdate.Title = newCourseTitle;
                    _context.SaveChanges();  // Save changes to the database
                    Console.WriteLine($"Course '{courseToUpdate.Title}' updated to '{newCourseTitle}' for student {student.Name}.");
                }
                else
                {
                    Console.WriteLine("Course not found for this student.");
                }
            }
            else
            {
                Console.WriteLine("Student not found.");
            }
        }

        // Add a new student and assign them courses
        public void AddStudentWithCourses(Student student, List<Course> courses)
        {
            student.Courses = courses;
            _context.Students.Add(student);
            _context.SaveChanges();
        }

        // Update a student's courses (replace all courses)
        public void UpdateStudentCourses(int studentId, List<Course> newCourses)
        {
            var student = _context.Students.Include(s => s.Courses).FirstOrDefault(s => s.StudentId == studentId);
            if (student != null)
            {
                student.Courses = newCourses;
                _context.SaveChanges();
            }
        }

        // Retrieve and display all students with their enrolled courses
        public void DisplayStudentsWithCourses()
        {
            var students = _context.Students.Include(s => s.Courses).ToList();
            foreach (var student in students)
            {
                Console.WriteLine($"Student: {student.Name}");
                foreach (var course in student.Courses)
                {
                    Console.WriteLine($"  Enrolled in: {course.Title}");
                }
            }
        }

        // Delete a student by their ID
        public void DeleteStudent(int studentId)
        {
            var student = _context.Students.FirstOrDefault(s => s.StudentId == studentId);
            if (student != null)
            {
                _context.Students.Remove(student);
                _context.SaveChanges();
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            using (SchoolContext schoolContext = new SchoolContext())
            {
                var studentsWithCourseF = schoolContext.Students
                                                       .Where(s => s.Courses.Any(c => c.Title == "f"))
                                                       .ToList();

                // Optionally, iterate over and print the results
                foreach (var student in studentsWithCourseF)
                {
                    Console.WriteLine($"Student ID: {student.StudentId}, Name: {student.Name}");
                }
            }

            /*var manager = new StudentManager();

            // Example student and courses
            var student = new Student
            {
                Name = "John Doe"
            };
            var courses = new List<Course>
            {
                new Course { Title = "Mathematics" },
                new Course { Title = "Science" }
            };

            // Add a new student with courses
            manager.AddStudentWithCourses(student, courses);
            Console.WriteLine("Student added with courses.");

            // Retrieve and display all students with their courses
            manager.DisplayStudentsWithCourses();

            // Update a specific student's course (update "Mathematics" to "Advanced Mathematics")
            manager.UpdateStudentCourse(student.StudentId, courses[0].CourseId, "Advanced Mathematics");
            Console.WriteLine("\nStudent's course updated.");

            // Display all students again
            manager.DisplayStudentsWithCourses();

            // Delete the student by ID
            manager.DeleteStudent(student.StudentId);
            Console.WriteLine("\nStudent deleted.");

            // Display all students again
            manager.DisplayStudentsWithCourses();*/
        }
    }
}
