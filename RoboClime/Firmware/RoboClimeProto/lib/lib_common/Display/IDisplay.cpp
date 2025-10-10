#include "IDisplay.h"

void CBaseDisplay::UpdateData(DisplayData data)
{
    _NewData = data;
}

void CBaseDisplay::RefreshAndSwitch()
{
    Refresh();
    _CurrentData = _NewData;
}

void CBaseDisplay::Draw()
{
    RefreshAndSwitch();
}

void CBaseDisplay::Draw(DisplayData data)
{
    UpdateData(data);
    RefreshAndSwitch();
}

void CBaseDisplay::Draw(DisplayData *data)
{
    UpdateData(*data);
    RefreshAndSwitch();
}

void CBaseDisplay::Draw(unsigned short int elapsedDayPercent)
{
    _NewData.ElapsedDayPercent = elapsedDayPercent;
    RefreshAndSwitch();
}

void CBaseDisplay::Draw(unsigned short int sheetNumber, unsigned short int elapsedDayPercent)
{
    _NewData.SheetNumber = sheetNumber;
    _NewData.ElapsedDayPercent = elapsedDayPercent;
    RefreshAndSwitch();  
}

void CBaseDisplay::Draw(float cur, unsigned short int elapsedDayPercent)
{
    _NewData.CurrentTemperature = cur;
    _NewData.ElapsedDayPercent = elapsedDayPercent;
    RefreshAndSwitch();          
}

void CBaseDisplay::Draw(float cur, float max, float min, unsigned short int elapsedDayPercent)
{
    _NewData.CurrentTemperature = cur;
    _NewData.MaxTemperature = max;
    _NewData.MinTemperature = min;
    _NewData.ElapsedDayPercent = elapsedDayPercent;
    RefreshAndSwitch();          
}
