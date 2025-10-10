using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using RoboCore.Models;
using RoboCore.ViewModel.Home;
using System.Diagnostics;

namespace RoboCore.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly ApplicationDbContext _context;

        public HomeController(ILogger<HomeController> logger, ApplicationDbContext context)
        {
            _logger = logger;
            _context = context;
        }

        public IActionResult Index()
        {
            var devices = _context.RoboDeviceEntities
                .Select(device => new
                {
                    DeviceTypeName = device.DeviceType.Name,
                    DeviceName = device.Name,
                    LastStatus = device.History
                        .OrderByDescending(h => h.UpdateDate)
                        .ThenByDescending(h => h.Id)
                        .Select(h => (RoboDeviceStatus?)h.Status) // Делаем nullable
                        .FirstOrDefault() ?? RoboDeviceStatus.Warning     // Значение по умолчанию
                })
                .ToList();

            //var devices = _context.RoboDeviceEntities.ToList();
            IndexViewModel viewModel = new()
            {
                Devices = []
            };
            
            foreach (var device in devices)
            {
                viewModel.Devices.Add(
                    new RoboDeviceViewModel
                    {
                        Name = device.DeviceTypeName+": "+ device.DeviceName,
                        Status = device.LastStatus
                    }
                );
            }

            return View(viewModel);
        }


        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
