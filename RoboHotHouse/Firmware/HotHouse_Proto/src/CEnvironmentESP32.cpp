#include "CEnvironmentESP32.hpp"

CEnvironmentESP32::CEnvironmentESP32(ILog *log)
{
    _Log = log;
}

ILog *CEnvironmentESP32::GetLog()
{
    return _Log;
}

unsigned long CEnvironmentESP32::Millis()
{
    return millis();
}

void CEnvironmentESP32::DigitalWrite(const uint8_t aPinNumer, bool aValue)
{
    digitalWrite(aPinNumer, aValue?HIGH:LOW);
}

void CEnvironmentESP32::PinMode(const uint8_t aPinNumer, uint8_t aMode)
{
    pinMode(aPinNumer, aMode);
}
