using InventoryManagementDTOs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryManagementDAL.Interfaces
{
    public interface IProductRepository
    {
        List<Product> GetAllProducts();
        Product GetProductByName(string name);
        Product GetProductById(int id);
        bool HasTransactions(int productId);
        void AddProduct(Product product);
        void UpdateProduct(Product product);
        void UpdateQuantity(int id, int quantity);
        void DeleteProduct(int id);
    }
}
