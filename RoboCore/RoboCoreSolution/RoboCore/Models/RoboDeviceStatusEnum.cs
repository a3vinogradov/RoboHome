using System.ComponentModel;

namespace RoboCore.Models
{
    public enum RoboDeviceStatus
    {
        [Description("Работает нормально")]
        Ok = 0,

        [Description("Критическая ошибка")]
        Error = 1,

        [Description("Требуется внимание")]
        Warning = 2
    }
}
