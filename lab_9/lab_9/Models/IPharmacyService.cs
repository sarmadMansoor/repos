﻿namespace lab_9.Models
{
    public interface IPharmacyService
    {
        List<PharmacyItem> GetAllItems(); 
        PharmacyItem GetItemById(int id); 
        void AddItem(PharmacyItem item); 
    }

}
