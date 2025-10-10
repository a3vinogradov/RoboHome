using RoboCore.Models;

namespace RoboCore.ViewModel.Home
{
    public class RoboDeviceViewModel
    {
        public required string Name { get; set; }
        public required RoboDeviceStatus Status { get; set; }
    }
}
