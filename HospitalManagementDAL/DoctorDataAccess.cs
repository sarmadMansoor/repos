using HospitalManagementDAL.Entities;
using Microsoft.Data.SqlClient;
using Microsoft.Identity.Client;
using System.Numerics;
using System.Text.Json;

namespace HospitalManagementDAL
{
    public class DoctorDataAccess
    {
        public int InsertDoctor(Doctor dr)
        {
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            int effect = 0;
            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "INSERT INTO Doctor (Name, Specialization) VALUES (@Name, @Specialization)";

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@Name", dr.Name);
                cmd.Parameters.AddWithValue("@Specialization", dr.Specialization);

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
        public List<Doctor> GetAllPatientsFromDatabase()
        {
            List<Doctor> doctor = new List<Doctor>(); 
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";

            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "SELECT * FROM doctor";

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    Doctor dr = new Doctor
                    {
                        DoctorId = reader.GetInt32(0), 
                        Name = reader.GetString(1),   
                        Specialization = reader.GetString(2)
                    };
                    doctor.Add(dr); 
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

            return doctor; 
        }
        public int UpdatePatientInDatabase(Doctor dr)
        {
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            int effect = 0;
            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "UPDATE Doctor SET Name = @Name, Specialization = @Specialization WHERE DoctorId = @DoctorId";

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@Name", dr.Name);
                cmd.Parameters.AddWithValue("@Specialization", dr.Specialization);
                cmd.Parameters.AddWithValue("@DoctorId", dr.DoctorId);

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
        public List<Doctor> SearchDoctorInDatabase(string spec)
        {
            List<Doctor> doctor = new List<Doctor>();
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";

            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "SELECT * FROM Doctor WHERE Specialization = @Specialization";

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@Specialization", spec);

                SqlDataReader reader = cmd.ExecuteReader();

                while (reader.Read())
                {
                    Doctor dr = new Doctor
                    {
                        DoctorId = reader.GetInt32(0), 
                        Name = reader.GetString(1),    
                        Specialization = reader.GetString(2) 
                    };
                    doctor.Add(dr);
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

            return doctor; 
        }
        private void SaveDeletedRecord(int DoctorId)
        {
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            Doctor deletedDoctor = null;

            SqlConnection sqlConnection = new SqlConnection(conn);
            try
            {
                sqlConnection.Open();
                string selectQuery = "SELECT * FROM Doctor WHERE DoctorId = @DoctorId";

                SqlCommand selectCmd = new SqlCommand(selectQuery, sqlConnection);
                selectCmd.Parameters.AddWithValue("@DoctorId", DoctorId);

                SqlDataReader reader = selectCmd.ExecuteReader();
                if (reader.Read())
                {
                    deletedDoctor = new Doctor
                    {
                        DoctorId = reader.GetInt32(0),
                        Name = reader.GetString(1),
                        Specialization = reader.GetString(2)
                    };

                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex);
            }
            finally
            {
                sqlConnection.Close();

            }

            if (deletedDoctor != null)
            {
                DoctorMetaData doctorMetaData = new DoctorMetaData
                { Doctor = deletedDoctor, Timestamp = DateTime.Now };
                string jsonRecord = JsonSerializer.Serialize(doctorMetaData);
                FileStream fileStream = new FileStream("DeletedPatients.txt", FileMode.Append, FileAccess.Write);
                StreamWriter writer = new StreamWriter(fileStream);
                    
                        writer.WriteLine(jsonRecord);
                writer.Close();
                fileStream.Close();


            }
        }

        public void DeletePatientFromDatabase(int drId)
        {
            SaveDeletedRecord(drId);
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            SqlConnection sqlConnection = new SqlConnection(conn);
            sqlConnection.Open();
            try
            {
                string query = "DELETE FROM Doctor WHERE DoctorId = @DoctorId";
                SqlCommand sqlCommand = new SqlCommand(query, sqlConnection);
                sqlCommand.Parameters.AddWithValue("@DoctorId", drId);
                sqlCommand.ExecuteNonQuery();

            }
            finally
            {
                sqlConnection.Close();
            }
        }

        public bool isPresentInDataBase(int id)
        { 
            string conn = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=HospitalManagment;Integrated Security=True;";
            bool status = false;
            SqlConnection sqlConnection = new SqlConnection(conn);

            try
            {
                sqlConnection.Open();
                string query = "SELECT * FROM Doctor WHERE DoctorId = @DoctorId";

                SqlCommand cmd = new SqlCommand(query, sqlConnection);
                cmd.Parameters.AddWithValue("@DoctorId", id);

                SqlDataReader reader = cmd.ExecuteReader();

                if (reader.Read())
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


    }
}