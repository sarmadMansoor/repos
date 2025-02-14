using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    public  class Player
    {
        public int PlayerID { get; set; }
        public string  Username { get; set; }
        public int Ranking { get; set; }
        public int TotalQuizzesToken { get; set; }
        public int TotalCorrectAnswers { get; set; }
        public int TotalIncorrectAnswers { get; set; }
        public int Score { get; set; }

    }
}
