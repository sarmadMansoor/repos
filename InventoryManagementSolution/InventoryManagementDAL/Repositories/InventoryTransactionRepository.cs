using InventoryManagementDAL.Interfaces;
using InventoryManagementDTOs.Models;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryManagementDAL.Repositories
{
    public class InventoryTransactionRepository : IInventoryTransactionRepository
    {
		private readonly InventoryDbContext _context;

		// Constructor dependency injection
		public InventoryTransactionRepository(InventoryDbContext context)
		{
			_context = context;
		}
		public void AddTransaction(InventoryTransaction transaction)
		{
			_context.InventoryTransactions.Add(transaction);
			_context.SaveChanges();
		}
		public InventoryTransaction GetTransactionById(int transactionId)
		{
			return  _context.InventoryTransactions.FirstOrDefault(t => t.TransactionID == transactionId);
		}
		public List<InventoryTransaction> GetAllTransactions()
		{
			return  _context.InventoryTransactions.ToList();
		}
		public void  UpdateTransaction(InventoryTransaction transaction)
		{
			_context.InventoryTransactions.Update(transaction);
			_context.SaveChanges();
		}
		public void DeleteTransaction(int transactionId)
		{
			var transaction =  _context.InventoryTransactions.Find(transactionId);
			if (transaction != null)
			{
				_context.InventoryTransactions.Remove(transaction);
				 _context.SaveChanges();
			}
		}
		public  List<InventoryTransaction> GetTransactionsByProduct(string productName)  // To get transactions related to a product
		{
			var product = _context.Products.Single(p=>p.ProductName == productName);
			return  _context.InventoryTransactions.Where(t => t.ProductID == product.ProductID).ToList();
		}
		public  List<InventoryTransaction> GetTransactionsByType(string transactionType)  // To get transactions based on type(IN or OUT)
		{
			return  _context.InventoryTransactions.Where(t => t.TransactionType == transactionType).ToList();
		}
	}
}
