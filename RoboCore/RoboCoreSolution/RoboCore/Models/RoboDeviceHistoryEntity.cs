using System.ComponentModel.DataAnnotations;

namespace RoboCore.Models
{
    // Класс для хранения исторических данных устройства
    public class RoboDeviceHistoryEntity
    {
        [Key]
        public int Id { get; set; }

        // Ссылка на устройство
        public int RoboDeviceId { get; set; }
        public RoboDeviceEntity RoboDevice { get; set; }

        // Статус устройства на момент записи
        public RoboDeviceStatus Status { get; set; }

        // Дата и время фиксации показания
        public DateTime UpdateDate { get; set; } = DateTime.Now;

        // Дополнительные метаданные (опционально)
        public string? AdditionalInfo { get; set; }

        public RoboDeviceHistoryEntity() { }

        // Конструктор для удобного создания записей
        public RoboDeviceHistoryEntity(int roboDeviceId, RoboDeviceStatus status, DateTime? recordDate = null)
        {
            RoboDeviceId = roboDeviceId;
            Status = status;
            if (recordDate.HasValue)
            {
                UpdateDate = recordDate.Value;
            }
        }
    }
}
