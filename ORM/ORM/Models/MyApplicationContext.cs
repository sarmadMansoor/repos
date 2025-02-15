using Microsoft.EntityFrameworkCore;
namespace ORM.Models
{
    public class MyApplicationContext:DbContext
    {
        public DbSet<User> Users { get; set; }
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=se22;Integrated Security=True;");
        }
    }
}
