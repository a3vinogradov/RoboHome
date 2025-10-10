#pragma once
#include <Adafruit_AHTX0.h>
#include "ISensorAht21.h"

class SensorAht21: public ISensorAht21
{
    public: 
    SensorAht21();
    void Setup();
    virtual DataAht21 Read();

    private:
    Adafruit_AHTX0 _aht21;

};