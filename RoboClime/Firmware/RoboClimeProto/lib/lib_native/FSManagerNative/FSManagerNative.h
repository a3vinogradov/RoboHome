#pragma once
#include "TypeDef.h"
#include "FSManager.h"

class FSManagerNative: public FSManager {
    public:
        FSManagerNative() : RootDir("data"){};
        FSManagerNative(const String& root_dir) ;
        // virtual ~FSManagerNative() = default; 
        
        virtual bool Setup() override;
        virtual String ReadFile(const String& shortFileName) override; 
        virtual bool Exists(const String& shortFileName) override; 
    private:
        const String RootDir = "data"; 
};

