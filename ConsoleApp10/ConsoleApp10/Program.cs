using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using System;
using HospitalManagementDAL; // Ensure the correct using directive for your library
using HospitalManagementDAL.Entities; // If needed
namespace ConsoleApp10
{


        class Program
        {
            static void Main(string[] args)
            {
                PatientDataAccess patientDataAccess = new PatientDataAccess();

                // Example usage
                Patient newPatient = new Patient { Name = "John Doe", Email = "john@example.com", Disease = "Flu" };
                patientDataAccess.InsertPatient(newPatient);

                Console.WriteLine("Patient added successfully!");

                // You can add more code to test other methods...
            }
        }
    

}
