// Подключение модуля датчика 
// ds18d20 ->  ESP32
// -----------------
// Gnd     ->  Gnd
// Vcc     ->  5V
// Dat     ->  D4 - любой цифровой
// Dat     ->  R4700  ->  D2  - только для голого датчика, без платы модуля
//
//========================================================================
// TFT 1.28 !!!ВАЖНО!!!
// Настройки в файле .pio\libdeps\esp32\TFT_eSPI\User_Setup.h
// #define TFT_HEIGHT 240 // GC9A01 240 x 240
// ...
// #define GC9A01_DRIVER // оставить только этот, остальные закоментарить 
// !!!**КРИТИЧНО** не правильная настройка драйвера приведет к выходу из строя дисплея и/или контроллера
// ...
// Определить пины для дисплея. Остальные закоментарить
// #define TFT_MOSI (SDA) 15 // In some display driver board, it might be written as "SDA" and so on.
// #define TFT_SCLK (SCL) 14
// #define TFT_CS   (CS)   5 // Chip select control pin
// #define TFT_DC   (DC)  27 // Data Command control pin
// #define TFT_RST  (RST) 33 // Reset pin (could connect to Arduino RESET pin)
// 

#include "TypeDef.h"
#include "ILog.h"
#include "IEnvironment.hpp"
#include "CEnvironmentESP32.hpp"
#include "CSerialLog.h"
#include "CSensorManager.h"
#include "CPullTask.h"
#include "CSerialLogManager.h"
#include "IObserver.hpp"
#include "CMainController.h"

//#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// библиотека для дисплея и проверка настройки в конфигурационном файле библиотеки
#include <TFT_eSPI.h> 
// 
#ifndef GC9A01_DRIVER
    #error "❌ ОШИБКА: В файле User_Setup.h не выбран драйвер GC9A01. Раскомментируйте строку '#define GC9A01_DRIVER' в файле .pio\\libdeps\\esp32\\TFT_eSPI\\User_Setup.h" 
#endif
#if !defined(TFT_HEIGHT)
    #error "❌ ОШИБКА: Не определен TFT_HEIGHT в User_Setup.h"
#elif TFT_HEIGHT != 240 
    #error "❌ ОШИБКА: Разрешение TFT дисплея не 240x240. Для GC9A01 ожидается 240x240"
#endif
#include "CDisplayManager.h"
#include "CHeartController.h"

TFT_eSPI gTFT = TFT_eSPI();

// Создаем лог (терминал Serial)
CSerialLog gLog;
ILog* pLog = &gLog; 

// Создание системного объекта 
CEnvironmentESP32 gEnv(pLog);
IEnvironment* pEnv = &gEnv;

// Датчик температуры
// Пин подключения DS18B20
const int oneWireBus = 4;     
// Настройка объектов OneWire и DallasTemperature
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp;
// Создание объекта для работы с сенсорами
CSensorManager gSensorManager(pEnv, &sensors, &aht, &bmp);
// Создание объекта для работы с дисплеем 
CDisplayManager gDisplayManager(pEnv, &gTFT);
CDisplayManager* pDisplayManager = &gDisplayManager;

CSerialLogManager gSerialLogMng(pLog);
IObserver<SensorData>* pSerialLogMng = &gSerialLogMng;

// Создание контроллера обогревателя
CHeartController gHeartController(pEnv);
CHeartController* pHeartController = &gHeartController;

// Создание объекта - контроллера
CMainController gMainController(pEnv, pDisplayManager, pHeartController);

// Создание объекта - шедулера
CPullTask gPullTask(pEnv, &gSensorManager, &gMainController);


void setup() {
    Serial.begin(115200);
    gSerialLogMng.Setup();
    gSensorManager.Setup();
    gDisplayManager.Setup();
    gHeartController.Setup();
    gMainController.Setup();

    pEnv->GetLog()->WriteLn("Init CSerialLog object");

    gPullTask.Setup();
    bool res = gPullTask.attach(pSerialLogMng);
    //res = gPullTask.attach(pHeartController);
}

void loop() {
    gPullTask.Exec();
    gMainController.Exec();
}

