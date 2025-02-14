using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HospitalManagementDAL.Entities
{
    public class PatientMetaData
    {
        public Patient Patient { get; set; }     
        public DateTime Timestamp { get; set; }  

        public PatientMetaData(Patient patient, DateTime timestamp)
        {
            Patient = patient;
            Timestamp = timestamp;
        }
        public PatientMetaData()
        {
            Patient = null;
            Timestamp = DateTime.MinValue; 
        }
    }
}
