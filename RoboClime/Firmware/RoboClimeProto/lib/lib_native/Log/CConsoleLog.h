// ConsoleLogger.h  
#pragma once
#include "ILog.h"
#include <iostream>

class CConsoleLog : public ILog {
public:
    void Write(String text) override {
        std::cout << text;
    }
    
    void WriteLn(String text) override {
        std::cout << text << std::endl;
    }
    
    void Clear() override {
        // Очистка консоли - system dependent
        //system("clear"); // Linux/Mac
        // system("cls"); // Windows
    }
};