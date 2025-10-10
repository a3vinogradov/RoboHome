using System.ComponentModel.DataAnnotations;

namespace RoboCore.Models
{
    // Тип устройства
    public class RoboDeviceTypeEntity
    {
        [Key]
        public int Id { get; set; }               // Уникальный идентификатор
        public required string Name { get; set; }          // Название типа (например, "Поливалка")
        public required string Description { get; set; }   // Описание типа устройства

        public virtual ICollection<RoboDeviceEntity> History { get; set; } = [];

        // Конструктор для удобной инициализации
        public RoboDeviceTypeEntity(int id, string name, string description)
        {
            Id = id;
            Name = name ?? throw new ArgumentNullException(nameof(name));
            Description = description ?? string.Empty;
        }
    }
}
