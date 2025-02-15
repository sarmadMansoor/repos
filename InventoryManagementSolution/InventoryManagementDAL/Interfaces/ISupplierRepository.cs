using InventoryManagementDTOs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryManagementDAL.Interfaces
{
    public interface ISupplierRepository
    {
        List<Supplier> GetAllSuppliers();
        Supplier GetSupplierByName(string name);
        Supplier GetSupplierById(int id);
        bool HasProducts(int id);
        void AddSupplier(Supplier supplier);
        void UpdateSupplier(Supplier supplier);
        void DeleteSupplier(int id);
    }
}
