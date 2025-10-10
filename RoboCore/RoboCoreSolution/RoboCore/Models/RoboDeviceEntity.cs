using System.ComponentModel.DataAnnotations;

namespace RoboCore.Models
{
    // Основная сущность устройства
    public class RoboDeviceEntity
    {
        [Key]
        public int Id { get; set; }                       // Уникальный идентификатор

        public int DeviceTypeId { get; set; }
        public required RoboDeviceTypeEntity DeviceType { get; set; }     // Тип устройства

        public required string Name { get; set; }                  // Имя устройства

        public required RoboDeviceStatus Status { get; set; }       // Текущий статус

        public virtual ICollection<RoboDeviceHistoryEntity> History { get; set; } = [];

        public RoboDeviceEntity() { }
        // Полный конструктор для удобной инициализации
        public RoboDeviceEntity(int id, RoboDeviceTypeEntity deviceType, string name, RoboDeviceStatus status)
        {
            Id = id;
            DeviceType = deviceType ?? throw new ArgumentNullException(nameof(deviceType));
            Name = name ?? throw new ArgumentNullException(nameof(name));
            Status = status;
        }
    }
}
