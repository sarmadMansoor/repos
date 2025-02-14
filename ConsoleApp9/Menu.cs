using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using HospitalManagementDAL;
using HospitalManagementDAL.Entities;
using Microsoft.Data.SqlClient;

namespace HospitalManagementSystem
{
    class Menu
    { 
        public void startApp()
        {
            bool exit = false;

            while (!exit)
            {
                Console.WriteLine("\n--- Hospital Management System ---");
                Console.WriteLine("1. Add Patient");
                Console.WriteLine("2. Update Patient");
                Console.WriteLine("3. Delete Patient");
                Console.WriteLine("4. Search Patient by Name");
                Console.WriteLine("5. View All Patients");
                Console.WriteLine("6. Add Doctor");
                Console.WriteLine("7. Update Doctor");
                Console.WriteLine("8. Delete Doctor");
                Console.WriteLine("9. Search Doctor by Specialization");
                Console.WriteLine("10. View All Doctors");
                Console.WriteLine("11. Book Appointment");
                Console.WriteLine("12. Search Appointment");
                Console.WriteLine("13. Cancel Appointment");
                Console.WriteLine("14. View Deleted Records");
                Console.WriteLine("15. View All Appointments");
                Console.WriteLine("16. Exit");
                Console.Write("Choose an option (1-16): ");

                string input = Console.ReadLine();

                switch (input)
                {
                    case "1":
                        addPatient();
                        break;
                    case "2":
                        UpdatePatient();
                        break;
                    case "3":
                        DeletePatient();
                        break;
                    case "4":
                        
                        SearchPatientByName();
                        break;
                    case "5":
                        ViewAllPatients();
                        break;
                    case "6":
                        AddDoctor();
                        break;
                    case "7":
                        UpdateDoctor();
                        break;
                    case "8":
                        DeleteDoctor();
                        break;
                    case "9":
                        SearchDoctorBySpecialization();
                        break;
                    case "10":
                        ViewAllDoctors();
                        break;
                    case "11":
                        bookAppointment();
                        break;
                    case "12":
                        searchAppointment();
                        break;
                    case "13":
                        cancelAppointment();
                        break;
                    case "14":
                        DisplayDeletedRecords();
                        break;
                    case "15":
                        ViewAllAppointments();
                        break;
                    case "16":
                        exit = true;
                        Console.WriteLine("Exiting the program...");
                        break;
                    default:
                        Console.WriteLine("Invalid choice. Please select a valid option.");
                        break;
                }
            }
        }
        private void addPatient()
        {
            PatientDataAccess patientDataAccess = new PatientDataAccess();
            Console.WriteLine("Enter the Name : ");
            string name = Console.ReadLine();
            string email = null;
            bool isValidEmail = false;
            while (!isValidEmail)
            {
                Console.WriteLine("Enter the email: ");
                email = Console.ReadLine();

                if (email.EndsWith("@gmail.com", StringComparison.OrdinalIgnoreCase))
                {
                    isValidEmail = true;
                }
                else
                {
                    Console.WriteLine("Invalid Gmail email. Please try again.");
                }
            }
            Console.WriteLine("Enter your Disease: ");
            string dis= Console.ReadLine();
            Patient patient = new Patient { Name =name,Email=email,Disease=dis};
            int count =patientDataAccess.InsertPatient(patient);
            if (count > 0)
            {
                Console.WriteLine("Patient Inserted!");
            }
            else
            {
                Console.WriteLine("failed");
            }

        }
        private int getCorrectPatientId()
        {
            PatientDataAccess patientDataAccess = new PatientDataAccess();
            int id = -1;
            bool isValidId = false;
            while (!isValidId)
            {
                try
                {
                    Console.Write("Enter Patient's Id: ");
                    id = int.Parse(Console.ReadLine());

                    if (patientDataAccess.isPresentInDataBase(id))
                    {
                        isValidId = true;
                    }
                    else
                    {
                        Console.WriteLine("Enter a valid Patient's Id. ");
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Enter a valid Patient's Id. ");
                }
            }
            return id;
        }
        private  void UpdatePatient()
        {
            int id = getCorrectPatientId();
            Console.WriteLine("Enter the new Name: ");
            string name = Console.ReadLine();
            string email = null;
            bool isValidEmail = false;
            while (!isValidEmail)
            {
                Console.WriteLine("Enter the new email: ");
                email = Console.ReadLine();

                if (email.EndsWith("@gmail.com", StringComparison.OrdinalIgnoreCase))
                {
                    isValidEmail = true;
                }
                else
                {
                    Console.WriteLine("Invalid Gmail email. Please try again.");
                }
            }
            Console.WriteLine("Enter the new Disease: ");
            string disease = Console.ReadLine();

            Patient patient = new Patient { PatientId = id, Name = name, Email = email, Disease = disease };
            PatientDataAccess patientDataAccess = new PatientDataAccess();
            int count = patientDataAccess.UpdatePatientInDatabase(patient);
            if (count > 0)
            {
                Console.WriteLine("Patient updated successfully!");
            }
            else
            {
                Console.WriteLine("Failed to update patient.");
            }
        }
        private void DeletePatient()
        {
            int patientId = getCorrectPatientId();

            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            SqlConnection sqlcon = new SqlConnection(conn);
            List<int> appointmentIds = new List<int>();
            try
            {
                sqlcon.Open();
                string query = "SELECT appointmentId FROM appointment WHERE PatientId = @PatientId";

                SqlCommand sqlCommand = new SqlCommand(query, sqlcon);
                sqlCommand.Parameters.AddWithValue("@PatientId", patientId);

                SqlDataReader dataReader = sqlCommand.ExecuteReader();

                while (dataReader.Read()) 
                {
                    int appointmentId = dataReader.GetInt32(0);
                    appointmentIds.Add(appointmentId);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error");
            }
            finally
            {
                sqlcon.Close();
            }
            AppointmentDataAccess appointmentDataAccess = new AppointmentDataAccess();
            for (int i = 0; i < appointmentIds.Count; i++)
            {
                appointmentDataAccess.DeletePatientFromDatabase(appointmentIds[i]);
            }
            PatientDataAccess patientDataAccess = new PatientDataAccess();
            patientDataAccess.DeletePatientFromDatabase(patientId);
            Console.WriteLine("Patient and related appointments deleted successfully.");

        }
        private  void SearchPatientByName()
        {
            PatientDataAccess patientDataAccess = new PatientDataAccess();
            Console.WriteLine("Enter the Patient Name: ");
            string name = Console.ReadLine();

            List<Patient> patients = patientDataAccess.SearchPatientsInDatabase(name);
            if (patients.Count > 0)
            {
                foreach (var patient in patients)
                {
                    Console.WriteLine($"Patient ID: {patient.PatientId}, Name: {patient.Name}, Email: {patient.Email}, Disease: {patient.Disease}");
                }
            }
            else
            {
                Console.WriteLine("No patients found with the given name.");
            }
        }
        private  void ViewAllPatients()
        {
            PatientDataAccess patientDataAccess = new PatientDataAccess();
            List<Patient> patients = patientDataAccess.GetAllPatientsFromDatabase();
            if (patients.Count > 0)
            {
                foreach (var patient in patients)
                {
                    Console.WriteLine($"Patient ID: {patient.PatientId}, Name: {patient.Name}, Email: {patient.Email}, Disease: {patient.Disease}");
                }
            }
            else
            {
                Console.WriteLine("No patients found.");
            }
        }
        private  void AddDoctor()
        {
            DoctorDataAccess doctorDataAccess =new DoctorDataAccess();
            Console.WriteLine("Enter the Doctor Name: ");
            string name = Console.ReadLine();
            Console.WriteLine("Enter the Doctor Specialization: ");
            string specialization = Console.ReadLine();

            Doctor doctor = new Doctor { Name = name, Specialization = specialization };
            int count = doctorDataAccess.InsertDoctor(doctor);
            if (count > 0)
            {
                Console.WriteLine("Doctor inserted successfully!");
            }
            else
            {
                Console.WriteLine("Failed to insert doctor.");
            }
        }
        private int  getCorrectDoctorId()
        {
            DoctorDataAccess doctorDataAccess = new DoctorDataAccess();
            int doctorId = -1;
            bool isValidId = false;
            while (!isValidId)
            {
                try
                {
                    Console.Write("Enter Doctor's Id: ");
                    doctorId = int.Parse(Console.ReadLine());

                    if (doctorDataAccess.isPresentInDataBase(doctorId))
                    {
                        isValidId = true;
                    }
                    else
                    {
                        Console.WriteLine("Enter a valid Doctor's Id. ");
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Enter a valid Doctor's Id. ");
                }
            }
            return doctorId;
        }
        private  void UpdateDoctor()
        {
            int doctorId = getCorrectDoctorId();
            DoctorDataAccess doctorDataAccess = new DoctorDataAccess();
            Console.WriteLine("Enter the new Doctor Name: ");
            string name = Console.ReadLine();
            Console.WriteLine("Enter the new Doctor Specialization: ");
            string specialization = Console.ReadLine();

            Doctor doctor = new Doctor { DoctorId = doctorId, Name = name, Specialization = specialization };
            int count = doctorDataAccess.UpdatePatientInDatabase(doctor);
            if (count > 0)
            {
                Console.WriteLine("Doctor updated successfully!");
            }
            else
            {
                Console.WriteLine("Failed to update doctor.");
            }
        }
        private void DeleteDoctor()
        {
            int doctorId = getCorrectDoctorId();
            DoctorDataAccess doctorDataAccess = new DoctorDataAccess();
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            SqlConnection sqlcon = new SqlConnection(conn);
            List<int> appointmentIds = new List<int>();
            try
            {
                sqlcon.Open();
                string query = "SELECT appointmentId FROM appointment WHERE doctorId = @DoctorId";

                SqlCommand sqlCommand = new SqlCommand(query, sqlcon);
                sqlCommand.Parameters.AddWithValue("@DoctorId", doctorId);

                SqlDataReader dataReader = sqlCommand.ExecuteReader();

                while (dataReader.Read())
                {
                    int appointmentId = dataReader.GetInt32(0);
                    appointmentIds.Add(appointmentId);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error");
            }
            finally
            {
                sqlcon.Close();
            }
            AppointmentDataAccess appointmentDataAccess = new AppointmentDataAccess();
            for (int i = 0; i < appointmentIds.Count; i++)
            {
                appointmentDataAccess.DeletePatientFromDatabase(appointmentIds[i]);
            }
            doctorDataAccess.DeletePatientFromDatabase(doctorId);
            Console.WriteLine("Doctor and related appointments deleted successfully.");

        }
        private  void SearchDoctorBySpecialization()
        {
            DoctorDataAccess doctorDataAccess = new DoctorDataAccess();
            Console.WriteLine("Enter the Doctor Specialization: ");
            string specialization = Console.ReadLine();

            List<Doctor> doctors = doctorDataAccess.SearchDoctorInDatabase(specialization);
            if (doctors.Count > 0)
            {
                foreach (var doctor in doctors)
                {
                    Console.WriteLine($"Doctor ID: {doctor.DoctorId}, Name: {doctor.Name}, Specialization: {doctor.Specialization}");
                }
            }
            else
            {
                Console.WriteLine("No doctors found with the given specialization.");
            }
        }
        private  void ViewAllDoctors()
        {
            DoctorDataAccess doctorDataAccess = new DoctorDataAccess();

            List<Doctor> doctors = doctorDataAccess.GetAllPatientsFromDatabase();
            if (doctors.Count > 0)
            {
                foreach (Doctor doctor in doctors)
                {
                    Console.WriteLine($"Doctor ID: {doctor.DoctorId}, Name: {doctor.Name}, Specialization: {doctor.Specialization}");
                }
            }
            else
            {
                Console.WriteLine("No doctors found.");
            }
        }
        private DateTime getCorrectDate()
        {
            DateTime appointmentDateTime = DateTime.Now;
            bool isValidDate = false;

            while (!isValidDate)
            {
                Console.WriteLine("Enter appointment date and time (MM/dd/yyyy HH:mm) for future: ");
                string input = Console.ReadLine();
                try
                {
                    appointmentDateTime = DateTime.Parse(input);
                    if (appointmentDateTime > DateTime.Now)
                    {
                        isValidDate = true;
                    }
                    else
                    {
                        Console.WriteLine("The date and time must be in the future. Please try again.");
                    }
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid date format. Please use MM/dd/yyyy HH:mm.");
                }
            }
            return appointmentDateTime;
        }
        private void bookAppointment()
        {
            int patientId = getCorrectPatientId();
            int doctorId = getCorrectDoctorId();
            DateTime appointmentDateTime = getCorrectDate();

            string connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            SqlConnection sqlConnection =new SqlConnection   (connString);
            sqlConnection.Open();
            string query = "SELECT * FROM appointment WHERE appointmentDate = @appointmentDate";
            SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
            sqlCommand.Parameters.AddWithValue("@appointmentDate", appointmentDateTime);
            SqlDataReader reader = sqlCommand.ExecuteReader();
            if (reader.HasRows)
            {
                Console.WriteLine("This Slot is already booked! ");
                sqlConnection.Close();
                return;
            }

            sqlConnection.Close();
            Appointment appointment = new Appointment {PatientId=patientId,DoctorId=doctorId,AppointmentDate= appointmentDateTime };
            AppointmentDataAccess appointmentDataAccess = new AppointmentDataAccess();
            if(appointmentDataAccess.InsertAppointment(appointment)>0)
            {
                Console.WriteLine($"Appointment date and time set to: {appointmentDateTime}");
            }
            else
            {
                Console.WriteLine($"Appointment booking Failed!");
            }


        }
        private void searchAppointment()
        {
            Console.WriteLine("Do you want to search Appointment by Patient ID, Doctor ID, or both?");
            Console.WriteLine("Press 1 for Patient ID, 2 for Doctor ID, 3 for both:");
            int choice = -1;
            bool isValidId = false;
            while (!isValidId)
            {
                try
                {
                    Console.Write("Enter Choice :  ");
                    choice = int.Parse(Console.ReadLine());
                    if(choice == 1||choice==2||choice==3)
                    {
                        isValidId =true;
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Enter a valid choice: ");
                }
            }
            int patientId = -1; 
            int doctorId = -1; 

            if (choice == 1 || choice == 3) 
            {
                patientId = getCorrectPatientId();
            }

            if (choice == 2 || choice == 3) 
            {
                doctorId = getCorrectDoctorId();
            }

            AppointmentDataAccess appointmentDataAccess = new AppointmentDataAccess();
            List<Appointment> appointments = appointmentDataAccess.SearchAppointmentsInDatabase(patientId, doctorId);

            if (appointments != null && appointments.Count > 0)
            {
                Console.WriteLine("Appointments found:");
                foreach (var appointment in appointments)
                {
                    Console.WriteLine($"Appointment ID: {appointment.AppointmentId}, Patient ID: {appointment.PatientId}, Doctor ID: {appointment.DoctorId}, Appointment Date: {appointment.AppointmentDate}");
                }
            }
            else
            {
                Console.WriteLine("No appointments found with the specified criteria.");
            }
        }
        private void cancelAppointment()
        {
            bool isValid = false;
            int id = -1;
            AppointmentDataAccess appointmentDataAccess=new AppointmentDataAccess();
            while (!isValid)
            {
                try
                {
                    Console.WriteLine("Enter the Appointment Id : ");
                    id = int.Parse(Console.ReadLine());
                    if(appointmentDataAccess.SearchAppointmentsInDatabaseById(id))
                    {
                        isValid = true;
                    }
                    else
                    {
                        Console.WriteLine("Enter Correct Id ");
                    }
                }
                catch
                {
                    Console.WriteLine("Enter Data like number : ");
                }
            }
            appointmentDataAccess.DeletePatientFromDatabase(id);
        }
        private void DisplayDeletedRecords()
        {
            HistoryLogger logger = new HistoryLogger();

            Console.WriteLine("Which deleted records do you want to view?");
            Console.WriteLine("1. Patients");
            Console.WriteLine("2. Doctors");
            Console.WriteLine("3. Appointments");
            int choice = -1;
            bool isValid= false;
            while (!isValid)
            {
                try
                {
                    Console.Write("Enter Choice :  ");
                    choice = int.Parse(Console.ReadLine());
                    if (choice == 1 || choice == 2 || choice == 3)
                    {
                        isValid = true;
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Enter a valid choice ");
                }
            }
            switch (choice)
            {
                case 1:
                    DisplayDeletedPatients(logger);
                    break;
                case 2:
                    DisplayDeletedDoctors(logger);
                    break;
                case 3:
                    DisplayDeletedAppointments(logger);
                    break;
                default:
                    Console.WriteLine("Invalid choice.");
                    break;
            }
        }

        private void DisplayDeletedPatients(HistoryLogger logger)
        {
            List<PatientMetaData> deletedPatients = logger.PatientDeletedRecordHistory();

            if (deletedPatients.Count > 0)
            {
                Console.WriteLine("Deleted Patients:");
                foreach (PatientMetaData record in deletedPatients)
                {
                    if (record.Patient!=null)
                    {
                        Console.WriteLine($"Patient ID: {record.Patient.PatientId}, Name: {record.Patient.Name}, Disease: {record.Patient.Disease}, Deleted On: {record.Timestamp.ToString("dddd, MMMM dd, yyyy h:mm tt")}");

                    }
                }
            }
            else
            {
                Console.WriteLine("No deleted patient records found.");
            }
        }

        private void DisplayDeletedDoctors(HistoryLogger logger)
        {
            List<DoctorMetaData> deletedDoctors = logger.DoctorDeletedRecordHistory();

            if (deletedDoctors.Count > 0)
            {
                Console.WriteLine("Deleted Doctors:");
                foreach (DoctorMetaData record in deletedDoctors)
                {
                    Console.WriteLine($"Doctor ID: {record.Doctor.DoctorId}, Name: {record.Doctor.Name}, Specialization: {record.Doctor.Specialization}, Deleted On: {record.Timestamp.ToString("dddd, MMMM dd, yyyy h:mm tt")}");
                }
            }
            else
            {
                Console.WriteLine("No deleted doctor records found.");
            }
        }

        private void DisplayDeletedAppointments(HistoryLogger logger)
        {
            List<AppointmentMetaData> deletedAppointments = logger.AppointmentDeletedRecordHistory();

            if (deletedAppointments.Count > 0)
            {
                Console.WriteLine("Deleted Appointments:");
                foreach (AppointmentMetaData record in deletedAppointments)
                {
                    Console.WriteLine($"Appointment ID: {record.Appointment.AppointmentId}, Patient ID: {record.Appointment.PatientId}, Doctor ID: {record.Appointment.DoctorId}, Date: {record.Appointment.AppointmentDate}, Deleted On: {record.Timestamp.ToString("dddd, MMMM dd, yyyy h:mm tt")}");
                }
            }
            else
            {
                Console.WriteLine("No deleted appointment records found.");
            }
        }
        private void ViewAllAppointments()
        {
            AppointmentDataAccess appointmentDataAccess = new AppointmentDataAccess();
            List<Appointment> appointments = appointmentDataAccess.GetAllPatientsFromDatabase(); 

            if (appointments.Count > 0)
            {
                Console.WriteLine("Appointments:");
                foreach (Appointment appointment in appointments)
                {
                    Console.WriteLine($"Appointment ID: {appointment.AppointmentId}, Patient ID: {appointment.PatientId}, Doctor ID: {appointment.DoctorId}, Appointment Date: {appointment.AppointmentDate}");
                }
            }
            else
            {
                Console.WriteLine("No appointments found.");
            }
        }

    }
}
