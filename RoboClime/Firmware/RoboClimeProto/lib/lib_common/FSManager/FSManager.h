#pragma once
#include "TypeDef.h"

class FSManager {
public:
    FSManager() = default;
    virtual ~FSManager() = default;
    virtual bool Setup()=0;
    virtual String ReadFile(const String& shortFileName)=0; 
    virtual bool Exists(const String& shortFileName)=0; 
};