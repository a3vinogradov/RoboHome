using System;

namespace RoboDeviceEmulator
{
    /// <summary>
    /// Базовая реализация команды, реализующей интерфейс ICommand.
    /// Предоставляет стандартную функциональность для управления состоянием и уведомления об изменениях.
    /// </summary>
    public abstract class BaseCommand : ICommand
    {
        private bool _enabled = true;

        /// <summary>
        /// Получает или задает состояние команды: доступна ли она для выполнения.
        /// При изменении состояния генерируется событие OnStateChanged.
        /// </summary>
        public bool Enabled
        {
            get => _enabled;
            set
            {
                if (_enabled != value)
                {
                    _enabled = value;
                    OnStateChanged?.Invoke(this, EventArgs.Empty); // стандартный вызов делегата с проверкой на null
                }
            }
        }

        /// <summary>
        /// Событие, возникающее при изменении состояния команды (в частности, свойства Enabled).
        /// </summary>
        public event EventHandler OnStateChanged;

        /// <summary>
        /// Абстрактный метод, который должен быть реализован в производных классах.
        /// Содержит логику выполнения команды.
        /// </summary>
        public abstract void Execute();
    }
}
