#include "CLogDisplay.h"

CLogDisplay::CLogDisplay(ILog* log)
{
    _log = log;
    return;
}

void CLogDisplay::Refresh()
{
    switch (_NewData.SheetNumber)
    {
    case 0:
        _log->WriteLn(INT_TO_STRING(_NewData.SheetNumber));
        _log->WriteLn(INT_TO_STRING(_NewData.ElapsedDayPercent));
        _log->WriteLn(FLOAT_TO_STRING(_NewData.CurrentTemperature,2));
        _log->WriteLn(FLOAT_TO_STRING(_NewData.MaxTemperature,2));
        _log->WriteLn(FLOAT_TO_STRING(_NewData.MinTemperature,2));
        break;
    case 1:
        _log->WriteLn(INT_TO_STRING(_NewData.SheetNumber));
        _log->WriteLn(INT_TO_STRING(_NewData.ElapsedDayPercent));
        for(int i=0; i<LOG_LENGTH; i++)
        {
            _log->WriteLn(FLOAT_TO_STRING(_NewData.MinLog[i],2));
        };
        for(int i=0; i<LOG_LENGTH; i++)
        {
            _log->WriteLn(FLOAT_TO_STRING(_NewData.MaxLog[i],2));
        };
        break;
    default:
        break;
    }
    return;
}

CLogDisplay::~CLogDisplay()
{
    return;
}
