#include "TypeDef.h"
#include "ILog.h"
#include "CSerialLog.h"

CSerialLog gLog;
ILog* pLog = &gLog; 

void setup() {
    Serial.begin(115200);

    pLog->WriteLn("Init CSerialLog object");
}

void loop() {
}

