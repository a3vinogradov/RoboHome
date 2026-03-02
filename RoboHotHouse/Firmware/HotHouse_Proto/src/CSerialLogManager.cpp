#include "CSerialLogManager.h"

CSerialLogManager::CSerialLogManager(ILog *aLog)
{
    _Log = aLog;
}

void CSerialLogManager::Setup()
{
    //
}

void CSerialLogManager::update(SensorData *data)
{
    String msg = "Tds = " + String(float(data->Tds)/100) + " *C, ";
    msg += "Haht = " + String(data->Haht) + " % ,";
    msg += "Taht = " + String(float(data->Taht)/100) + " *C, ";
    msg += "Pbmp = " + String(float(data->Pbmp)/100) + " Pa, ";
    msg += "Tbmp = " + String(float(data->Tbmp)/100) + " *C;";
    _Log->WriteLn(msg);
}
