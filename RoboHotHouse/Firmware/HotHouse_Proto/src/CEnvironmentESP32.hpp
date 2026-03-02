#pragma once
#include "IEnvironment.hpp"


class CEnvironmentESP32: public IEnvironment 
{
    private:
    ILog* _Log;

    public:
    CEnvironmentESP32(ILog* log);
    virtual ILog* GetLog();
    virtual unsigned long Millis();
    virtual void DigitalWrite(const uint8_t aPinNumer, bool aValue ) override;
    virtual void PinMode(const uint8_t aPinNumer, uint8_t aMode) override;

};