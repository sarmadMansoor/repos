using Microsoft.SqlServer.Server;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Data.SqlClient;
using System.IO.Packaging;
using System.Data;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace ConsoleApp2
{
    public class LeaderboardManager
    {
        private DataTable dataTable=new DataTable();
        private DataTable quiz=new DataTable();
        private void  fetchPlayerData()
        {
            string conString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Quiz;Integrated Security=True;";
            SqlConnection conn = new SqlConnection(conString);
            conn.Open();
            string query = "select * from player";
            SqlCommand sqlCommand = new SqlCommand(query, conn);
            SqlDataAdapter adapter = new SqlDataAdapter();
            adapter.SelectCommand = sqlCommand;
            adapter.Fill(dataTable);
            conn.Close();

        }

        private void fetchQuiz()
        {
            string conString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Quiz;Integrated Security=True;";
            SqlConnection conn = new SqlConnection(conString);
            conn.Open();
            string query = "select * from quiz";
            SqlCommand sqlCommand = new SqlCommand(query, conn);
            SqlDataAdapter adapter = new SqlDataAdapter();
            adapter.SelectCommand = sqlCommand;
            adapter.Fill(quiz);
            conn.Close();

        }
        private void displayTopPlayer()
        {
            for(int i=1;i<11;i++)
            {
                string conString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Quiz;Integrated Security=True;";
                SqlConnection conn = new SqlConnection(conString);
                conn.Open();
                int num = i;
                string query = $"select * from player  where ranking ={num} ";
                SqlCommand sqlCommand = new SqlCommand(query, conn);
                SqlDataReader reader = sqlCommand.ExecuteReader();
                while(reader.Read())
                {
                    Console.WriteLine(reader.GetInt32(0));
                    Console.WriteLine(reader.GetString(1));
                    Console.WriteLine(reader.GetInt32(2));
                    Console.WriteLine(reader.GetInt32(3));
                    Console.WriteLine(reader.GetInt32(4));
                    Console.WriteLine(reader.GetInt32(5));
                    Console.WriteLine(reader.GetInt32(6));
                }
                conn.Close();
            }
            
        }
        public void displayLeaderboard()
        {
            
        }
        private int CalculateRanking(int score)
        {
            int RANK = 0;
            return RANK;
        }
        public void SaveQuizResult(int playerId ,int totalQuestions,int correctAnswer)
        {
            UpdatePlayerStatistics(playerId, totalQuestions, correctAnswer,totalQuestions-correctAnswer);
            DataRow quizRow= quiz.NewRow();
            quizRow[1] = DateTime.Now;
            quizRow[2] = playerId;
            quizRow[3] = totalQuestions;
            quizRow[4] = correctAnswer;
            quizRow[5] = totalQuestions - correctAnswer;
            saveQuizData();


        }
        private void saveQuizData()
        {
            string conString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Quiz;Integrated Security=True;";
            SqlConnection conn = new SqlConnection(conString);
            conn.Open();
            string query = "update  player set DateTime =@t,playerid =@i,totalquestion =@q,correctAnswer  =@a,score =@sc where quizId = @q";

            SqlCommand sqlCommand = new SqlCommand(query, conn);
            SqlParameter Date = new SqlParameter("@t", SqlDbType.DateTime, 32, "QuizDate");
            SqlParameter playerid = new SqlParameter("@i", SqlDbType.Int, 32, "playerid");
            SqlParameter totalquestion = new SqlParameter("@q", SqlDbType.Int, 32, "totalquestion");
            SqlParameter score = new SqlParameter("@sc", SqlDbType.Int, 32, "score");
            SqlParameter quizId = new SqlParameter("@p", SqlDbType.Int, 32, "quizId");
            sqlCommand.Parameters.Add(Date);
            sqlCommand.Parameters.Add(playerid);
            sqlCommand.Parameters.Add(totalquestion);
            sqlCommand.Parameters.Add(score);
            sqlCommand.Parameters.Add(quizId);
            sqlCommand.Parameters.Add(playerid);
            SqlDataAdapter adapter = new SqlDataAdapter();
            adapter.UpdateCommand = sqlCommand;
            adapter.Update(quiz);
            conn.Close();
        }
        private void UpdatePlayerStatistics(int playerId ,int correctAnswer,int incorrectAnswers ,int scoreEarned)
        {
            DataRow[] targetRow = dataTable.Select($"PlayerId = {playerId}");
            if (targetRow.Length > 0)
            {
                DataRow dr = targetRow[0];
                dr["TotalCorrectAnswer"] =(int )dr["TotalCorrectAnswer"]+  correctAnswer;
                dr[5]=(int)dr[5] + incorrectAnswers;
                dr[6] = (int)dr[6] + scoreEarned;

            }        
        }
        private void  savePlayerData()
        {
            string conString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Quiz;Integrated Security=True;";
            SqlConnection conn = new SqlConnection(conString);
            conn.Open();
            string query = "update  player set TotalQuizzesTaken =@t,TotalCorrectAnswer =@a,TotalIncorrectAnswer =@s,score  =@s where playerid = @p";

            SqlCommand sqlCommand = new SqlCommand(query, conn);
            SqlParameter totalQuiz = new SqlParameter("@t",SqlDbType.Int,32 , "TotalQuizzesTaken");
            SqlParameter TotalCorrectAnswer = new SqlParameter("@a",SqlDbType.Int,32 , "TotalCorrectAnswer");
            SqlParameter TotalIncorrectAnswer = new SqlParameter("@i",SqlDbType.Int,32 , "TotalIncorrectAnswer");
            SqlParameter score = new SqlParameter("@s",SqlDbType.Int,32 , "score");
            SqlParameter playerid = new SqlParameter("@p",SqlDbType.Int,32 , "PlayerID");
            sqlCommand.Parameters.Add(totalQuiz);
            sqlCommand.Parameters.Add(TotalCorrectAnswer);
            sqlCommand.Parameters.Add(TotalIncorrectAnswer);
            sqlCommand.Parameters.Add(score);
            sqlCommand.Parameters.Add(playerid);
            SqlDataAdapter adapter = new SqlDataAdapter();
            adapter.UpdateCommand = sqlCommand;
            adapter.Update(dataTable);
            conn.Close();
        }
    }
}
