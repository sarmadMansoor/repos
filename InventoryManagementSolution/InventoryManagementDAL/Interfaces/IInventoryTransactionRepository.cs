using InventoryManagementDTOs.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryManagementDAL.Interfaces
{
    public interface IInventoryTransactionRepository
    {
        void AddTransaction(InventoryTransaction transaction);
        InventoryTransaction GetTransactionById(int transactionId);
        List<InventoryTransaction> GetAllTransactions();
        void DeleteTransaction(int transactionId);
        List<InventoryTransaction> GetTransactionsByProduct(string productName);
        List<InventoryTransaction> GetTransactionsByType(string transactionType);

    }
}
