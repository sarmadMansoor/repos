using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    public class Quiz
    {
        public int QuizID { get; set; }
        public DateTime DateTime { get; set; }
        public int PlayerID { get; set; }
        public int TotalQuestion { get; set; }
        public int CorrectAnswer { get; set; }
        public int ScoreEarned  { get; set; }
    }
}
