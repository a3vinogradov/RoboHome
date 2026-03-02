#pragma once
#include "IEnvironment.hpp"
#include "IObserver.hpp"
#include "CSensorManager.h"

class CHeartController //: public IObserver<SensorData>
{
    private:
    IEnvironment* _Env; 
    bool _HeartStatus;

    public:
    CHeartController(IEnvironment* aEnv);
    bool Setup();
    //virtual void update(SensorData* data = nullptr) override;
    void HeartPadON();
    void HeartPadOFF();
    bool GetHeartStatus();  
};