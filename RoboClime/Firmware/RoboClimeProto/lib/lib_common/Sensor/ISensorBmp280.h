#pragma once

struct DataBmp280
{
    float Temperature;
    float Pressure;
};

class ISensorBmp280
{
    public: 
    virtual DataBmp280 Read() = 0;
};