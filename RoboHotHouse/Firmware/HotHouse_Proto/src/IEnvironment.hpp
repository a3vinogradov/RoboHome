#pragma once
#include "ILog.h"

class IEnvironment
{
    public:
    virtual ILog* GetLog() = 0;
    virtual unsigned long Millis() = 0;
    virtual void DigitalWrite(const uint8_t aPinNumer, bool aValue ) = 0;
    virtual void PinMode(const uint8_t aPinNumer, uint8_t aMode) = 0;
};
