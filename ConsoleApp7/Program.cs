using System;
using System.Collections.Generic;
using HospitalManagementDAL.Entities; // Include your entity namespace
using HospitalManagementDAL; // Include your DAL namespace

namespace HospitalManagementTester
{
    class Program
    {
        static void Main(string[] args)
        {
            /*PatientDataAccess patientDataAccess = new PatientDataAccess();

            // 1. Insert a new patient
            Patient newPatient = new Patient { Name = "John Doe", Email = "john@example.com", Disease = "Flu" };
            patientDataAccess.InsertPatient(newPatient);

            // 2. Retrieve all patients
            List<Patient> patients = patientDataAccess.GetAllPatientsFromDatabase();
            Console.WriteLine("All Patients:");
            foreach (var patient in patients)
            {
                Console.WriteLine($"Patient ID: {patient.PatientId}, Name: {patient.Name}, Email: {patient.Email}, Disease: {patient.Disease}");
            }

            // 3. Update a patient (using the ID of the inserted patient)
            newPatient.Name = "John Updated"; // Change the name for the update
            patientDataAccess.UpdatePatientInDatabase(newPatient);

            // 4. Search for patients by name
            var searchedPatients = patientDataAccess.SearchPatientsInDatabase("John");
            Console.WriteLine("\nSearched Patients:");
            foreach (var patient in searchedPatients)
            {
                Console.WriteLine($"Patient ID: {patient.PatientId}, Name: {patient.Name}, Email: {patient.Email}, Disease: {patient.Disease}");
            }

            // 5. Delete the patient (use the ID of the inserted patient)
            patientDataAccess.DeletePatientFromDatabase(newPatient.PatientId);

            Console.WriteLine("\nPatient deleted. Checking remaining patients...");
            patients = patientDataAccess.GetAllPatientsFromDatabase();
            Console.WriteLine("Remaining Patients:");
            foreach (var patient in patients)
            {
                Console.WriteLine($"Patient ID: {patient.PatientId}, Name: {patient.Name}, Email: {patient.Email}, Disease: {patient.Disease}");
            }*/

            // Optional: Check the contents of the DeletedPatients.json file
        }
    }
}
