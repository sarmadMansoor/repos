using InventoryManagementDAL.Interfaces;
using InventoryManagementDTOs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryManagementBLL
{
	public class SupplierService         // Class for Supplier Business logic
	{
		private readonly ISupplierRepository _supplierRepository;

		// Constructor Injection of SupplierRepository (DAL)
		public SupplierService(ISupplierRepository supplierRepository)
		{
			_supplierRepository = supplierRepository;
		}
		public void AddSupplier(string name, string contact)
		{
			if (string.IsNullOrWhiteSpace(name))
				throw new Exception("Supplier name is required.");

			if (string.IsNullOrWhiteSpace(contact) || contact.Length < 10) 
				throw new Exception("Valid Contact Number is required.");

			if (_supplierRepository.GetSupplierByName(name) != null)
				throw new Exception("Supplier name must be unique.");

			var supplier = new Supplier
			{
				SupplierName = name,
				ContactNumber = contact
			};
			_supplierRepository.AddSupplier(supplier);
		}
		public void UpdateSupplier(string name, string newName, string contact)
		{
			var existingSupplier = _supplierRepository.GetSupplierByName(name);
			if (existingSupplier == null)
				throw new Exception("Supplier not found.");

			if (string.IsNullOrWhiteSpace(contact) || contact.Length < 10)
				throw new Exception("Valid Contact Number is required.");

			var sameName = _supplierRepository.GetSupplierByName(newName);

			if (sameName != null && sameName.SupplierID != existingSupplier.SupplierID)
				throw new Exception("Supplier name must be unique.");

			if (string.IsNullOrWhiteSpace(newName))
				throw new Exception("Valid Supplier name is required.");

			existingSupplier.SupplierName = newName;
			existingSupplier.ContactNumber = contact;

			_supplierRepository.UpdateSupplier(existingSupplier);
		}
		public void DeleteSupplier(string SupplierName)
		{
			var Supplier = _supplierRepository.GetSupplierByName(SupplierName);
			if (Supplier == null)
				throw new Exception("Supplier not found.");

			if (_supplierRepository.HasProducts(Supplier.SupplierID))
				throw new Exception("Cannot delete Supplier with Products.");

			_supplierRepository.DeleteSupplier(Supplier.SupplierID);
		}
	}
}
