#pragma once
#include <TFT_eSPI.h> 
#include "IEnvironment.hpp"
#include "IObserver.hpp"
#include "CSensorManager.h"

struct DisplayData {
    int16_t Tds;
    int16_t Haht;
    int16_t Taht;
    int16_t Tbmp;
    int16_t Pbmp;
    uint8_t HeartStatus;
};

class CDisplayManager 
{
    private:
        IEnvironment* _Env;
        TFT_eSPI* _TFT;

    public:
    CDisplayManager(IEnvironment* aEnv, TFT_eSPI* aTFT);
    bool Setup();

    void Draw(DisplayData aData);
};