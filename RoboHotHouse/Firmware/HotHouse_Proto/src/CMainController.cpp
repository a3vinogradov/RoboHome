#include "CMainController.h"

CMainController::CMainController(IEnvironment *aEnv, CDisplayManager *aDisplayManager, CHeartController *aHeartController)
{
    _Env = aEnv;
    _DisplayManager = aDisplayManager;
    _HeartController = aHeartController;
}

bool CMainController::Setup()
{
    return false;
}

void CMainController::Exec()
{
}

void CMainController::SetSensorData(SensorData *data)
{
    // todo: убрать магические числа
    if (data->Tds < 2800)
    {
        _HeartController->HeartPadON();
    };
    
    if (data->Tds > 3000)
    {
        _HeartController->HeartPadOFF();
    };

    if (_HeartController->GetHeartStatus())
    {
        _Env->GetLog()->WriteLn("Heart pad ON");
    }
    else{
        _Env->GetLog()->WriteLn("Heart pad OFF");
    };
 
    DisplayData displayData;
    displayData.Haht = data->Haht;
    displayData.Taht = data->Taht;
    displayData.Tds = data->Tds;
    displayData.Tbmp = data->Tbmp;
    displayData.Pbmp = data->Pbmp;
    displayData.HeartStatus = _HeartController->GetHeartStatus();
    _DisplayManager->Draw(displayData);
} 

