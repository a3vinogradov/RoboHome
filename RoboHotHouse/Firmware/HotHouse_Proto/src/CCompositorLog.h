#pragma once
#include "ILog.h"

class CCompositorLog: public ILog
{
    private:
    
    static constexpr const unsigned short int Capacity = 5;        
    ILog* Children[Capacity];
    
    public:

    CCompositorLog();
    virtual void Write(String text);
    virtual void WriteLn(String text);
    virtual void Clear();

    bool Add(ILog* logger);
    bool Remove(ILog* logger);
    bool IsExists(ILog* logger);
    unsigned short int Count();
};