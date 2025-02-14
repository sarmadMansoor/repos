using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HospitalManagementDAL.Entities
{
    public class Doctor
    {
        public int DoctorId { get; set; }
        public string Name { get; set; }
        public string Specialization { get; set; }

        public Doctor(int doctorId, string name, string specialization)
        {
            DoctorId = doctorId;
            Name = name;
            Specialization = specialization;
        }
        public Doctor()
        {
            DoctorId = 0;
            Name = "";
            Specialization = "";
        }

        public override string ToString()
        {
            return $"DoctorId: {DoctorId}, Name: {Name}, Specialization: {Specialization}";
        }
    }
}
