#pragma once
#include "ILog.h"

class CStringLog : public ILog 
{
    private: 
        String Buffer;
        String EOL;
    public:
    CStringLog(const String eol = "");
    virtual void Write(String text);
    virtual void WriteLn(String text);
    virtual void Clear();
    String GetBuffer();
};