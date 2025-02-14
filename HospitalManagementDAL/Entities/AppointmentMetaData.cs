using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HospitalManagementDAL.Entities
{
    public class AppointmentMetaData
    {
        public Appointment Appointment { get; set; }  
        public DateTime Timestamp { get; set; } 

        public AppointmentMetaData(Appointment pt)
        {
            Appointment = pt;
            Timestamp = DateTime.Now; 
        }
        public AppointmentMetaData()
        {
            Appointment = null;
            Timestamp = DateTime.MinValue;
        }
    }
}
