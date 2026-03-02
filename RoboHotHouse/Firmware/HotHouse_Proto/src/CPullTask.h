#pragma once
#include "IEnvironment.hpp"
#include "ILog.h"
#include "CTimer.h"
#include "CSubjectArray.hpp"
#include "CSensorManager.h"
#include "CMainController.h"

class CPullTask: public CSubjectArray<SensorData> 
{
    private:
    //ILog* _log;
    IEnvironment* _Env;
    CTimer _timer;
    CSensorManager* _SensorManager;
    CMainController* _MainController;
 
    void PullSensors();

    public:
    CPullTask(IEnvironment* aEnv, CSensorManager* aSensorManager, CMainController* aMainController);
    void Setup();
    void Exec();

};