#pragma once
#include "TypeDef.h"
#include "FSManager.h"

class FSManagerESP8266: public FSManager {
    public:
        FSManagerESP8266() {};
        virtual bool Setup() override;
        virtual String ReadFile(const String& shortFileName) override; 
        virtual bool Exists(const String& shortFileName) override; 
    private:
        const String RootDir = "data"; 
};