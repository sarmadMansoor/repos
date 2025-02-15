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
    public class ProductRepository : IProductRepository
    {
		private readonly InventoryDbContext _context;

		// Constructor dependency injection
		public ProductRepository(InventoryDbContext context)
		{
			_context = context;
		}
		public List<Product> GetAllProducts()
		{
			return _context.Products.Include(p => p.Supplier).ToList();
		}
		public Product GetProductByName(string name)
		{
			return _context.Products.FirstOrDefault(p => p.ProductName == name);
		}
		public Product GetProductById(int id)
		{
			return _context.Products.Find(id);
		}
		public bool HasTransactions(int productId)          // To check if there transactions processed of product
		{
			return _context.InventoryTransactions.Any(t => t.ProductID == productId);
		}
		public void AddProduct(Product product)
		{
			_context.Products.Add(product);
			_context.SaveChanges();
		}
		public void UpdateProduct(Product product)
		{ 
			_context.Products.Update(product);
			_context.SaveChanges();
		}
		public void UpdateQuantity(int id, int quantity)
		{
			var product = _context.Products.Single(p => p.ProductID == id);
			product.StockQuantity = quantity;
			_context.Products.Update(product);
			_context.SaveChanges();
		}
		public void DeleteProduct(int id)
		{
			var product = _context.Products.Find(id);
			if (product != null)
			{
				_context.Products.Remove(product);
				_context.SaveChanges();
			}
		}
	}
}
