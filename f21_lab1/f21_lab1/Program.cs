using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace f21_lab1
{
    public class Person
    {
       private  string name;
        private int age;
        private List<string> emails;
        public string Name { get; set; }
        public int Age { get; set; }
        public List<string> Emails { get; set; }

        // Constructor
        public Person()
        {
            Emails = new List<string>();
        }

        // Method to add multiple emails using params keyword
        public void AddEmails(params string[] emails)
        {
            foreach (var email in emails)
            {
                Emails.Add(email);
            }
        }

        // Override ToString method to display person's details
        public override string ToString()
        {
            string emailList = string.Join(", ", Emails);
            return $"Name: {this.Name}, Age: {Age}, Emails: {emailList}";
        }

        // Method to save person information to a file using BinaryWriter
        public void SaveToFile(string filePath)
        {
            using (FileStream fs = new FileStream(filePath, FileMode.Create))
            using (BinaryWriter writer = new BinaryWriter(fs))
            {
                writer.Write(Name);
                writer.Write(Age);
                writer.Write(Emails.Count);
                foreach (var email in Emails)
                {
                    writer.Write(email);
                }
            }
        }
    }
}
