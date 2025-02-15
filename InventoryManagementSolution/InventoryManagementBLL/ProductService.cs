using InventoryManagementDAL.Interfaces;
using InventoryManagementDTOs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryManagementBLL
{
	public class ProductService                     // Class for Product Business logic
	{
		private readonly IProductRepository _productRepository;
		private readonly ISupplierRepository _supplierRepository;

		// Constructor Injection of ProductRepository (DAL)
		public ProductService(IProductRepository productRepository, ISupplierRepository supplierRepository)
		{
			_productRepository = productRepository;
			_supplierRepository = supplierRepository;
		}
		public List<Product> GetAllProducts()
		{
			return _productRepository.GetAllProducts();
		}
		public Product GetProductByName(string productName)
		{
			return _productRepository.GetProductByName(productName);
		}
		public void AddProduct(string name, string category, decimal price, int stock, string supplierName)
		{
			if (string.IsNullOrWhiteSpace(name))				// Validations
				throw new Exception("Product name is required.");

			if (_productRepository.GetProductByName(name) != null)
				throw new Exception("Product name must be unique.");

			if (price <= 0)
				throw new Exception("Price must be greater than zero.");

			if (stock < 0)
				throw new Exception("Stock quantity cannot be negative.");

			var supplier = _supplierRepository.GetSupplierByName(supplierName);

			if (supplier == null)
				throw new Exception("No Supplier Found.");

			var product = new Product
			{
				ProductName = name,
				Category = category,
				Price = price,
				StockQuantity = stock,
				SupplierID = _supplierRepository.GetSupplierByName(supplierName).SupplierID,
			};

			_productRepository.AddProduct(product);
		}
		public void UpdateProduct(string name, string newName, string category, decimal price, int stock)
		{
			var existingProduct = _productRepository.GetProductByName(name);
			if (existingProduct == null)
				throw new Exception("Product not found.");

			if (price <= 0)
				throw new Exception("Price must be greater than zero.");

			if (stock < 0)
				throw new Exception("Stock quantity cannot be negative.");

			var sameName = _productRepository.GetProductByName(newName);

			if (sameName != null && sameName.ProductID != existingProduct.ProductID)  // Check if new name already exists
				throw new Exception("Product name must be unique.");

			existingProduct.ProductName = name;
			existingProduct.Category = category;
			existingProduct.Price = price;
			existingProduct.StockQuantity = stock;

			_productRepository.UpdateProduct(existingProduct);
		}
		public void DeleteProduct(string productName)
		{
			var product = _productRepository.GetProductByName(productName);
			if (product == null)
				throw new Exception("Product not found.");

			if (_productRepository.HasTransactions(product.ProductID))
				throw new Exception("Cannot delete product with existing transactions.");

			_productRepository.DeleteProduct(product.ProductID);
		}
		public List<Product> SearchProducts(string searchTerm)   // Search product by Name, Category and Supplier
		{
			var products = _productRepository.GetAllProducts();
			var filtered = products.FindAll(p =>
				p.ProductName.Contains(searchTerm, StringComparison.OrdinalIgnoreCase) ||
				p.Category.Contains(searchTerm, StringComparison.OrdinalIgnoreCase) ||
				p.Supplier.SupplierName.Contains(searchTerm, StringComparison.OrdinalIgnoreCase)
			);

			return filtered;
		}
		public List<Product> GetLowStockAlerts()    // Return Stocks less then 5
		{
			var products = _productRepository.GetAllProducts();
			return products.FindAll(p => p.StockQuantity < 5);
		}
		public Dictionary<string, decimal> CalculateStockValuePerCategory()    // Total value per Category
		{
			var products = _productRepository.GetAllProducts();
			var categoryStockValues = new Dictionary<string, decimal>();

			foreach (var product in products)
			{
				if (categoryStockValues.ContainsKey(product.Category))
				{
					categoryStockValues[product.Category] += product.Price * product.StockQuantity;
				}
				else
				{
					categoryStockValues[product.Category] = product.Price * product.StockQuantity;
				}
			}
			return categoryStockValues;
		}
	}
}
