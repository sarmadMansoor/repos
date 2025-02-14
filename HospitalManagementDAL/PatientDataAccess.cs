using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using HospitalManagementDAL.Entities;
using Microsoft.Data.SqlClient;
using System.Text.Json;
using System.IO;

namespace HospitalManagementDAL
{
    public class PatientDataAccess
    {
        public bool isPresentInDataBase(int id)
        {
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            bool status = false;
            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "SELECT * FROM patient WHERE patientId = @patientId";

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@patientId", id);

                SqlDataReader reader = cmd.ExecuteReader();
                if (reader.HasRows)
                {
                    status = true;
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

            return status; 
        }
        public int  InsertPatient(Patient patient)
        {
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True";
            int effect = 0;
            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "INSERT INTO patient (Name, Email, Disease) VALUES (@Name, @Email, @Disease)";

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@Name", patient.Name);
                cmd.Parameters.AddWithValue("@Email", patient.Email);
                cmd.Parameters.AddWithValue("@Disease", patient.Disease);

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
        public List<Patient> GetAllPatientsFromDatabase()
        {
            List<Patient> patients = new List<Patient>(); 
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";

            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "SELECT PatientId, Name, Email, Disease FROM Patient"; 

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Patient patient = new Patient
                    {
                        PatientId = reader.GetInt32(0), 
                        Name = reader.GetString(1),     
                        Email = reader.GetString(2),    
                        Disease = reader.GetString(3)    
                    };
                    patients.Add(patient); 
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

            return patients;
        }
        public int UpdatePatientInDatabase(Patient patient)
        {
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            int effect = 0;
            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "UPDATE Patient SET Name = @Name, Email = @Email, Disease = @Disease WHERE PatientId = @PatientId";

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@Name", patient.Name);
                cmd.Parameters.AddWithValue("@Email", patient.Email);
                cmd.Parameters.AddWithValue("@Disease", patient.Disease);
                cmd.Parameters.AddWithValue("@PatientId", patient.PatientId);

                effect = cmd.ExecuteNonQuery();

            }
            catch (SqlException ex)
            {
                Console.WriteLine($"SQL Error: {ex.Message}");
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
        public List<Patient> SearchPatientsInDatabase(string name)
        {
            List<Patient> patients = new List<Patient>();
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";

            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "SELECT PatientId, Name, Email, Disease FROM Patient WHERE Name LIKE @Name";

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@Name", $"%{name}%");

                SqlDataReader reader = cmd.ExecuteReader();

                while (reader.Read())
                {
                    Patient patient = new Patient
                    {
                        PatientId = reader.GetInt32(0), 
                        Name = reader.GetString(1),     
                        Email = reader.GetString(2),    
                        Disease = reader.GetString(3)   
                    };
                    patients.Add(patient); 
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

            return patients; 
        }
        private void SaveDeletedRecord(int patientId)
        {
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            Patient deletedPatient = null;
            SqlConnection sqlConnection = new SqlConnection(conn);
            try
            {
                sqlConnection.Open();
                string selectQuery = "SELECT PatientId, Name, Email, Disease FROM Patient WHERE PatientId = @PatientId";

                SqlCommand selectCmd = new SqlCommand(selectQuery, sqlConnection);
                selectCmd.Parameters.AddWithValue("@PatientId", patientId);

                SqlDataReader reader = selectCmd.ExecuteReader();

                if (reader.Read())
                {
                    deletedPatient = new Patient
                    {
                        PatientId = reader.GetInt32(0),
                        Name = reader.GetString(1),
                        Email = reader.GetString(2),
                        Disease = reader.GetString(3)
                    };
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("Error : "+ex);
            }
            finally { sqlConnection.Close(); }  
            if (deletedPatient != null)
            {
                PatientMetaData patientMetaData = new PatientMetaData {Patient=deletedPatient,Timestamp=DateTime.Now };
                string jsonRecord = JsonSerializer.Serialize(patientMetaData);
                FileStream fileStream = new FileStream("DeletedPatients.txt", FileMode.Append, FileAccess.Write);
                
                    StreamWriter writer = new StreamWriter(fileStream);
                        writer.WriteLine(jsonRecord);
                writer.Close();
                fileStream.Close();
            }
        }

        public void DeletePatientFromDatabase(int patientId)
        {
            SaveDeletedRecord(patientId);
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            SqlConnection sqlConnection = new SqlConnection(conn); 
            sqlConnection.Open();
            try
            {
                string query = "DELETE FROM patient WHERE PatientId = @PatientId";
                SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
                sqlCommand.Parameters.AddWithValue("@PatientId", patientId);
                sqlCommand.ExecuteNonQuery();

            }
            finally
            {
                sqlConnection.Close();
            }
        }




    }
}
