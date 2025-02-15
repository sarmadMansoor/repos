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
    public class SupplierRepository : ISupplierRepository
    {
		private readonly InventoryDbContext _context;

		// Constructor dependency injection
		public SupplierRepository(InventoryDbContext context)
		{
			_context = context;
		}
		public List<Supplier> GetAllSuppliers()
		{
			return _context.Suppliers.ToList();
		}
		public Supplier GetSupplierByName(string name)
		{
			return _context.Suppliers.FirstOrDefault(p => p.SupplierName == name);
		}
		public Supplier GetSupplierById(int id)
		{
			return _context.Suppliers.Find(id);
		}
		public bool HasProducts(int id)      // To check if there are products with supplier
		{
			return _context.Products.Any(p => p.SupplierID == id);
		}
		public void AddSupplier(Supplier supplier)
		{
			_context.Suppliers.Add(supplier);
			_context.SaveChanges();
		}
		public void UpdateSupplier(Supplier supplier)
		{
			_context.Suppliers.Update(supplier);
			_context.SaveChanges();
		}
		public void DeleteSupplier(int id)
		{
			var supplier = _context.Suppliers.Find(id);
			if (supplier != null)
			{
				_context.Suppliers.Remove(supplier);
				_context.SaveChanges();
			}
		}
	}
}
