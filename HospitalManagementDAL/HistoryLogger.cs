using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.Json;
using HospitalManagementDAL.Entities;
using System.IO;



namespace HospitalManagementDAL
{
    public class HistoryLogger
    {

        public List<DoctorMetaData> DoctorDeletedRecordHistory()
        {
            List<DoctorMetaData> doctorMetaDatas = new List<DoctorMetaData>();
            string filePath = "DeletedDoctors.txt"; 

            if (File.Exists(filePath))
            {
                FileStream fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);


                     StreamReader reader = new StreamReader(fileStream);
                    
                        string line;
                        while ((line = reader.ReadLine()) != null)
                        {
                            DoctorMetaData record = JsonSerializer.Deserialize<DoctorMetaData>(line);

                            if (record != null)
                            {
                                doctorMetaDatas.Add(record); 
                            }
                        }
                    
                fileStream.Close();
            }
            

            return doctorMetaDatas; 
        }


        public List<AppointmentMetaData> AppointmentDeletedRecordHistory()
        {
            List<AppointmentMetaData> appointmentMetaDatas = new List<AppointmentMetaData>();
            string filePath = "DeletedAppointments.txt"; 

            if (File.Exists(filePath))
            {
                FileStream fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
                StreamReader reader = new StreamReader(fileStream);

                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    AppointmentMetaData record = JsonSerializer.Deserialize<AppointmentMetaData>(line);

                    if (record != null)
                    {
                        appointmentMetaDatas.Add(record); 
                    }
                }
                fileStream.Close();
            }
            return appointmentMetaDatas; 
        }

        public List<PatientMetaData> PatientDeletedRecordHistory()
         {
             List<PatientMetaData> patientMetaDatas = new List<PatientMetaData>();
             string filePath = "DeletedPatients.txt"; 

             if (File.Exists(filePath))
             {
                 FileStream fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read);
                 StreamReader reader = new StreamReader(fileStream);

                 string line;
                 while ((line = reader.ReadLine()) != null)
                 {
                     PatientMetaData record = JsonSerializer.Deserialize<PatientMetaData>(line);

                     if (record != null)
                     {
                         patientMetaDatas.Add(record); 
                     }
                 }
                 fileStream.Close();
             }
             return patientMetaDatas; 
         }


    }
}
