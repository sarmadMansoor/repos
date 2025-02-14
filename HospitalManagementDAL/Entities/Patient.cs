using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HospitalManagementDAL.Entities
{

    public class Patient
    {
        public int PatientId { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Disease { get; set; }

        public Patient(int patientId, string name, string email, string disease)
        {
            PatientId = patientId;
            Name = name;
            Email = email;
            Disease = disease;
        }
        public Patient()
        {
            PatientId = 0;
            Name = "";
            Email = "";
            Disease = "";
        }

        public override string ToString()
        {
            return $"PatientId: {PatientId}, Name: {Name}, Email: {Email}, Disease: {Disease}";
        }
    }

}
