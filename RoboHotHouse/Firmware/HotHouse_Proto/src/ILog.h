#pragma once
#include "TypeDef.h"

class ILog {
    public:
    virtual void Write(String text) = 0;
    virtual void WriteLn(String text) = 0;
    virtual void Clear() = 0;
};