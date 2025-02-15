using InventoryManagementDAL.Interfaces;
using InventoryManagementDTOs.Models;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion.Internal;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryManagementBLL
{
	public class InventoryTransactionService    // Class for InventoryTransaction Business logic
	{
		private readonly IInventoryTransactionRepository _transactionRepository;
		private readonly IProductRepository _productRepository;

		// Constructor Injection of InventoryTransactionRepository (DAL)
		public InventoryTransactionService(IInventoryTransactionRepository transactionRepository, IProductRepository productRepository)
		{
			_transactionRepository = transactionRepository;
			_productRepository = productRepository;
		}
		public void ProcessTransaction(string productName, string type, int quantity)    // To process a Transaction
		{
			var product = _productRepository.GetProductByName(productName);
			if (product == null)
				throw new Exception("No Product found to make transaction");

			if (type != "IN" && type != "OUT")
				throw new Exception("Transaction type must be 'IN' or 'OUT'.");

			if (quantity <= 0)
				throw new Exception("Quantity must be greater than 0.");

			if (type == "OUT" && product.StockQuantity < quantity)
				throw new Exception("Not enough quantity to OUT");


			var transaction = new InventoryTransaction
			{
				ProductID = product.ProductID,
				Quantity = quantity,
				TransactionType = type,
				TransactionDate = DateTime.Now
			};
			if (type == "IN")													// Update Products stock quantity
				_productRepository.UpdateQuantity(product.ProductID, product.StockQuantity + quantity);
			else
				_productRepository.UpdateQuantity(product.ProductID, product.StockQuantity - quantity);

			_transactionRepository.AddTransaction(transaction);
		}
		public InventoryTransaction GetTransactionById(int transactionId)
		{
			return _transactionRepository.GetTransactionById(transactionId);
		}
		public List<InventoryTransaction> GetAllTransactions()
		{
			return _transactionRepository.GetAllTransactions();
		}
		public void DeleteTransaction(int transactionId)
		{
			_transactionRepository.DeleteTransaction(transactionId);
		}
		public List<InventoryTransaction> GetTransactionsByProduct(string productName)
		{
			return _transactionRepository.GetTransactionsByProduct(productName);
		}
		public List<InventoryTransaction> GetTransactionsByType(string transactionType)
		{
			if (transactionType != "IN" && transactionType != "OUT")
				throw new Exception("Transaction type must be 'IN' or 'OUT'.");

			return _transactionRepository.GetTransactionsByType(transactionType);
		}
	}
}
