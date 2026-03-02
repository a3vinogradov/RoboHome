#pragma once
#include <DallasTemperature.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>
#include "IEnvironment.hpp"

struct SensorData {
    int16_t Tds;
    int16_t Haht;
    int16_t Taht;
    int16_t Tbmp;
    int16_t Pbmp;
};

class CSensorManager
{
    private:
    IEnvironment* _Env;
    DallasTemperature* _DS18b20;
    Adafruit_AHTX0* _aht;
    Adafruit_BMP280* _bmp;

    public:
    CSensorManager(IEnvironment* aEnv, DallasTemperature* aDS18b20, Adafruit_AHTX0* aAHT, Adafruit_BMP280* aBMP);
    void Setup();
    SensorData ReadSensors();
};