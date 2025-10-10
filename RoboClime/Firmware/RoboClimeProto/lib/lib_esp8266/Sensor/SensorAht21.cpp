#include "SensorAht21.h"

SensorAht21::SensorAht21(): _aht21()
{
    
}

void SensorAht21::Setup()
{
    if (! _aht21.begin()) {
        Serial.println("Could not find AHT? Check wiring");
        while (1) delay(10);
    }
    Serial.println("AHT10 or AHT20 found");

    return;
}

DataAht21 SensorAht21::Read()
{
    sensors_event_t humidity, temp;
    _aht21.getEvent(&humidity, &temp);  
    DataAht21 data;
    data.Temperature = temp.temperature;
    data.Hummidity = humidity.relative_humidity;
    return data;
}


