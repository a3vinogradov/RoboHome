#pragma once
#include "ILog.h"

class CSerialLog : public ILog {
public:
    void Write(String text) override {
        Serial.print(text);
    }
    
    void WriteLn(String text) override {
        Serial.println(text);
    }
    
    void Clear() override {
        // Для Serial очистка не имеет смысла
    }
};