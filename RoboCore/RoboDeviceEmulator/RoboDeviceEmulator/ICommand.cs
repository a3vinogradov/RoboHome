using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoboDeviceEmulator
{
    internal interface ICommand
    {
        bool Enabled { get; set; }
        void Execute();

        event EventHandler OnStateChanged;
    }
}
