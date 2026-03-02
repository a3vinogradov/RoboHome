// Контроллер обогревателя
// Сейчас он работает только с ковриком
// в планах добавить поддержку HeartCell5V

#pragma once
#include "CHeartController.h"

void CHeartController::HeartPadON()
{
    //todo Убрать магическое число
    _HeartStatus = true;
    _Env->DigitalWrite(19, false); // логика инвертирована
}

void CHeartController::HeartPadOFF()
{
    _HeartStatus = false;
    _Env->DigitalWrite(19, true); // логика инвертирована для 
}

bool CHeartController::GetHeartStatus()
{
    return _HeartStatus;
}

CHeartController::CHeartController(IEnvironment *aEnv)
{
    _Env = aEnv; 
    _HeartStatus = false;
}

bool CHeartController::Setup()
{
    _Env->PinMode(19, OUTPUT);
    HeartPadOFF();
    return true;
}

// void CHeartController::update(SensorData *data)
// {
//     if (data->Tds < 2800)
//     {
//         HeartPadON();
//     };
    
//     if (data->Tds > 3000)
//     {
//         HeartPadOFF();
//     };

//     if (_HeartStatus)
//     {
//         _Env->GetLog()->WriteLn("Heart pad ON");
//     }
//     else{
//         _Env->GetLog()->WriteLn("Heart pad OFF");
//     };
// }