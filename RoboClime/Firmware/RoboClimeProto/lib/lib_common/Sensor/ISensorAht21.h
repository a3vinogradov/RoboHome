#pragma once

struct DataAht21
{
    float Temperature;
    float Hummidity;
};

class ISensorAht21
{
    public: 
    virtual void Setup(){ return; };
    virtual DataAht21 Read() = 0;
};