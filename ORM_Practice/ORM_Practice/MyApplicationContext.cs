using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ORM_Practice
{
    internal class MyApplicationContext:DbContext
    {



        public DbSet<Tire> Tires { get; set; } 
        //public DbSet<Person> Person { get; set; } 
        public DbSet<Car> Cars { get; set; } 
        public DbSet<Engine> Engines { get; set; } 

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(@"Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=Orm_practice2;Integrated Security=True;Connect Timeout=30;Encrypt=False;Trust Server Certificate=False;Application Intent=ReadWrite;Multi Subnet Failover=False");
        }
    }
}
