#pragma once

#include "IEnvironment.hpp"
#include "CDisplayManager.h"
#include "CHeartController.h"
#include "CSensorManager.h"

class CMainController {
    private:
    IEnvironment* _Env;
    CDisplayManager* _DisplayManager;
    CHeartController* _HeartController;
    
    public:
    CMainController(IEnvironment* aEnv, CDisplayManager* aDisplayManager, CHeartController* aHeartController);
    bool Setup();
    void Exec();
    void SetSensorData(SensorData* data);
};

