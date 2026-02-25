#include "CPullTask.h"

void CPullTask::PullSensors()
{
    
    unsigned long time = _Env->Millis();
    SensorData data;
    data = _SensorManager->ReadSensors(); 
    _MainController->SetSensorData(&data);
    _Env->GetLog()->WriteLn(String("Pull sensors. time = ") + String(_Env->Millis()-time) + " ms.");
    notify(&data);

}

CPullTask::CPullTask(IEnvironment *aEnv, CSensorManager *aSensorManager, CMainController *aMainController) : 
    _timer(aEnv)
{
    _Env = aEnv;
    _SensorManager = aSensorManager;
    _MainController = aMainController;
};

void CPullTask::Setup()
{
    _timer.SetDelay(2000);
    _timer.Start();
}

void CPullTask::Exec()
{
    if (!_timer.IsActive())
    {
        _timer.ReStart();
        //_Env->GetLog()->WriteLn("Pull Exec!");
        PullSensors();
    }
}
