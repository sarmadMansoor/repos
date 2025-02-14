using HospitalManagementDAL.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Data.SqlClient;
using System.IO;
using System.Text.Json;

namespace HospitalManagementDAL
{
    public class AppointmentDataAccess
    {
        public int InsertAppointment(Appointment appointment)
        {
            int effect = 0;
            string connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";

            using (SqlConnection conn = new SqlConnection(connString))
            {
                try
                {
                    conn.Open();
                    string query = "INSERT INTO Appointment (PatientId, DoctorId, AppointmentDate) VALUES (@PatientId, @DoctorId, @AppointmentDate)";

                    SqlCommand cmd = new SqlCommand(query, conn);
                    
                        cmd.Parameters.AddWithValue("@PatientId", appointment.PatientId);
                        cmd.Parameters.AddWithValue("@DoctorId", appointment.DoctorId);
                        cmd.Parameters.AddWithValue("@AppointmentDate", appointment.AppointmentDate);

                        effect = cmd.ExecuteNonQuery();
                    
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
            return effect;
        }
        public List<Appointment> GetAllPatientsFromDatabase()
        {
            List<Appointment> appointments = new List<Appointment>(); 
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";

            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "SELECT * FROM Appointment"; 

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Appointment app = new Appointment
                    {
                        AppointmentId = reader.GetInt32(0),
                        PatientId = reader.GetInt32(1),
                        DoctorId = reader.GetInt32(2),
                        AppointmentDate = reader.GetDateTime(3)
                    };
                    appointments.Add(app);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            finally
            {
                sqlConnection.Close();
            }

            return appointments; 
        }
        public int  UpdatePatientInDatabase(Appointment appointment)
        {
            int effect = 0;
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";

            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "UPDATE Appointment SET PatientId = @PatientId, DoctorId = @DoctorId, AppointmentDate = @AppointmentDate WHERE AppointmentId = @AppointmentId";
                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@AppointmentId", appointment.AppointmentId);
                cmd.Parameters.AddWithValue("@PatientId", appointment.PatientId);
                cmd.Parameters.AddWithValue ("@DoctorId", appointment.DoctorId);
                cmd.Parameters.AddWithValue("@AppointmentDate", appointment.AppointmentDate);
                 effect = cmd.ExecuteNonQuery();
            }
            
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            finally
            {
                sqlConnection.Close();
            }
            return effect;
        }

        public  List<Appointment> SearchAppointmentsInDatabase (int patientId,int doctorId)
        {
            List<Appointment> appointments = new List<Appointment>(); 
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True";

            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = null;
                if (patientId !=-1 &&  doctorId!=-1 )
                {
                    query = $"SELECT * FROM Appointment WHERE patientId = @patientId and doctorId =@doctorId";
                }
                else
                {
                    query = $"SELECT * FROM Appointment WHERE patientId = @patientId or doctorId =@doctorId";

                }

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@patientId", patientId);
                cmd.Parameters.AddWithValue("@doctorId", doctorId);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Appointment app = new Appointment
                    {
                        AppointmentId = reader.GetInt32(0),
                        PatientId = reader.GetInt32(1),
                        DoctorId = reader.GetInt32(2),
                        AppointmentDate = reader.GetDateTime(3)
                    };
                    appointments.Add(app); 
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            finally
            {
                sqlConnection.Close(); 
            }

            return appointments; 
        }


        public  bool SearchAppointmentsInDatabaseById(int id)
        {
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True";

            SqlConnection sqlConnection = new SqlConnection(conn);
            bool flag = false;
            try
            {
                sqlConnection.Open();
                string query = $"SELECT * FROM Appointment WHERE AppointmentId = @id ";


                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@id", id);
                SqlDataReader reader = cmd.ExecuteReader();
                if(reader.HasRows)
                {
                    flag = true;
                }
            }

            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            finally
            {
                sqlConnection.Close();
            }

            return flag;
        }
        private void SaveDeletedRecord(int appointmentId)
        {
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            Appointment deletedApp = null;
            SqlConnection sqlConnection = new SqlConnection(conn);
            try
            {
                sqlConnection.Open();
                string selectQuery = "SELECT * FROM appointment WHERE appointmentId = @AppointmentId";

                SqlCommand selectCmd = new SqlCommand(selectQuery, sqlConnection);
                selectCmd.Parameters.AddWithValue("@AppointmentId", appointmentId);


                SqlDataReader reader = selectCmd.ExecuteReader();
                if (reader.Read())
                {
                    deletedApp = new Appointment
                    {
                        AppointmentId = reader.GetInt32(0),
                        PatientId = reader.GetInt32(1),
                        DoctorId = reader.GetInt32(2),
                        AppointmentDate = reader.GetDateTime(3)
                    };

                }
            }
            finally { sqlConnection.Close(); }
            if (deletedApp != null)
            {
                AppointmentMetaData appointmentMetaData = new AppointmentMetaData { Appointment = deletedApp, Timestamp = DateTime.Now };
                string jsonRecord = JsonSerializer.Serialize(appointmentMetaData);
                FileStream fileStream = new FileStream("DeletedAppointments.txt", FileMode.Append, FileAccess.Write);
                StreamWriter writer = new StreamWriter(fileStream);
                        writer.WriteLine(jsonRecord);
                writer.Close();
                fileStream.Close();
            }
        }

        public void DeletePatientFromDatabase(int appointmentId)
        {
            SaveDeletedRecord(appointmentId);
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            SqlConnection sqlConnection = new SqlConnection(conn);
            sqlConnection.Open();
            try
            {
                string query = "DELETE FROM Appointment WHERE appointmentId = @AppointmentId";
                SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
                sqlCommand.Parameters.AddWithValue("@AppointmentId", appointmentId);
                sqlCommand.ExecuteNonQuery();

            }
            finally
            {
                sqlConnection.Close();
            }
        }


    }
}
