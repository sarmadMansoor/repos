using Microsoft.AspNetCore.Mvc;
using Microsoft.Data.SqlClient;
using static Azure.Core.HttpHeader;
using System.Text.Json;
using lab_06_web.Models;
using lab_06_web.Models.Respositories;
namespace lab_06_web.Controllers
{
    public class CartController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
        public IActionResult Payment()
        {
            return View();
        }
        public IActionResult AddToCart(int ItemId, int Quantity)
        {
            int userId =(int)HttpContext.Session.GetInt32("UserId");
            if (userId==null) { userId = 0; }
            CartRepository cartRepository1 = new CartRepository();
            if(cartRepository1.isPresent(userId, ItemId))
            {
                int qan = cartRepository1.GetQuantity(userId, ItemId);
                cartRepository1.UpdateSingleCart(userId,ItemId, qan+Quantity);
            }
            else
            {
                Cart cart = new Cart { ItemId = ItemId, Quantity = Quantity, UserId = userId };
                cartRepository1.AddToCart(cart);
            }
            return RedirectToAction("MenuForDelivery","Menu");
        }
        public IActionResult DisplayCart()
        {
            int userId = (int)HttpContext.Session.GetInt32("UserId");
            CartRepository cartRepository = new CartRepository();
            List<Cart> allCart = cartRepository.GetCartItemsByUserId(userId);

            List<CartItemViewModel> cartItemViewModels = new List<CartItemViewModel>();
            MenuRepository menuRepository = new MenuRepository();

            foreach (var cart in allCart)
            {
                Menu menuItem = menuRepository.GetMenuItemById(cart.ItemId); // Fetch the menu item by ItemId
                var cartItemViewModel = new CartItemViewModel
                {
                    CartId = cart.CartId,
                    UserId = cart.UserId,
                    ItemId = cart.ItemId,
                    Quantity = cart.Quantity,
                    ItemName = menuItem.ItemName,
                    Price = menuItem.Price,
                    Description = menuItem.Description
                };
                cartItemViewModels.Add(cartItemViewModel); // Add to the list
            }

            return View(cartItemViewModels); // Pass the combined list to the view
        }

        public IActionResult DeleteCart(int id)
        {
           CartRepository   cartRepository    =new CartRepository();
            cartRepository.DeleteCart(id);

            return RedirectToAction("DisplayCart", "Cart"); // Pass the combined list to the view
        }

        public IActionResult UpdateQuantity(int id)
        {
            CartRepository cartRepository = new CartRepository();
            Cart cart= cartRepository.GetCartItemById(id);
            MenuRepository menuRepository = new MenuRepository();
            Menu menuItem = menuRepository.GetMenuItemById(cart.ItemId);
            var cartItemViewModel = new CartItemViewModel
            {
                CartId = cart.CartId,
                UserId = cart.UserId,
                ItemId = cart.ItemId,
                Quantity = cart.Quantity,
                ItemName = menuItem.ItemName,
                Price = menuItem.Price,
                Description = menuItem.Description
            };
            return View(cartItemViewModel); // Pass the combined list to the view
        }
        [HttpPost]
        public IActionResult UpdateQuantity(int CartId, int UserId, int ItemId, int Quantity)
        {
            CartRepository  cartRepository      =new CartRepository();  
            cartRepository.UpdateSingleCart(UserId, ItemId, Quantity); 
            return RedirectToAction("DisplayCart", "Cart");
        }

    }
}
