using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HospitalManagementDAL.Entities
{
    public class Appointment
    {
        public int AppointmentId { get; set; }
        public int PatientId { get; set; }
        public int DoctorId { get; set; }
        public DateTime AppointmentDate { get; set; }

        public Appointment(int appointmentId, int patientId, int doctorId, DateTime appointmentDate)
        {
            AppointmentId = appointmentId;
            PatientId = patientId;
            DoctorId = doctorId;
            AppointmentDate = appointmentDate;
        }

        public Appointment()
        {
            AppointmentId = 0;
            PatientId = 0;
            DoctorId = 0;
            AppointmentDate = DateTime.MinValue; 
        }

        public override string ToString()
        {
            return $"AppointmentId: {AppointmentId}, PatientId: {PatientId}, DoctorId: {DoctorId}, AppointmentDate: {AppointmentDate}";
        }
    }
}
