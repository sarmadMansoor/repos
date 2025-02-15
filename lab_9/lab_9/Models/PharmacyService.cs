namespace lab_9.Models
{
    public class PharmacyService : IPharmacyService
    {
        public List<PharmacyItem> GetAllItems()
        {
            HttpContext.Session.GetString("Items")
            return items ?? new List<PharmacyItem>();
        }

        public PharmacyItem GetItemById(int id)
        {
            var items = GetAllItems();
            return items.FirstOrDefault(i => i.Id == id);
        }

        public void AddItem(PharmacyItem item)
        {
            var items = GetAllItems();
            items.Add(item);
            HttpContext.Session["Items"] = items;
        }
    }

}
