#pragma once
#include "TypeDef.h"
#include "ILog.h"
#include "IDisplay.h"

class CLogDisplay : public CBaseDisplay 
{
    private:
    ILog* _log;

    public:
    
    CLogDisplay  (ILog* log);
    virtual void Refresh();
    ~CLogDisplay ();
};
