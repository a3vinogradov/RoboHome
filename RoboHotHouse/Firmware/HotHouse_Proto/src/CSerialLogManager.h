#pragma once
#include "ILog.h"
#include "CSensorManager.h"
#include "IObserver.hpp"

class CSerialLogManager : public IObserver<SensorData>
{
    private:
        ILog* _Log;

    public:
    CSerialLogManager(ILog* aLog);
    void Setup();
    virtual void update(SensorData* data = nullptr) override;
};