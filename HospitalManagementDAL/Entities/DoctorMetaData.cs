using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HospitalManagementDAL.Entities
{
    public class DoctorMetaData
    {
        public Doctor Doctor { get; set; }   
        public DateTime Timestamp { get; set; }  

        public DoctorMetaData(Doctor doctor)
        {
            Doctor = doctor;
            Timestamp = DateTime.Now; 
        }
        public DoctorMetaData()
        {
            Doctor = null;
            Timestamp = DateTime.MinValue; 
        }
    }

}
