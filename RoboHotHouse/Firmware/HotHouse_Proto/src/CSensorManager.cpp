#include "CSensorManager.h"

CSensorManager::CSensorManager(IEnvironment* aEnv, DallasTemperature *aDS18b20, Adafruit_AHTX0 *aAHT, Adafruit_BMP280 *aBMP)
{
    _Env = aEnv;
    _DS18b20 = aDS18b20;
    _aht = aAHT;
    _bmp = aBMP;
}

void CSensorManager::Setup()
{
    _DS18b20->begin();

    // 
    if (!_aht->begin()) {
        _Env->GetLog()->WriteLn("Не удалось найти AHT20!");
        while (1);
    }
    //Serial.println("AHT20 найден!");

    // Инициализация I2C и датчика 
    if (!_bmp->begin(0x77)) {  // Если не работает, попробуйте 0x77
        _Env->GetLog()->WriteLn("Не удалось найти BMP280!");
        while (1);
    }  
    // Настройка параметров датчика
    _bmp->setSampling(
        Adafruit_BMP280::MODE_NORMAL,
        Adafruit_BMP280::SAMPLING_X2,
        Adafruit_BMP280::SAMPLING_X16,
        Adafruit_BMP280::FILTER_X16,
        Adafruit_BMP280::STANDBY_MS_500
    );    
}

SensorData CSensorManager::ReadSensors()
{
  SensorData result;

  // Запрос температуры ds18b20
  _DS18b20->requestTemperatures(); 
  // Чтение температуры в Цельсиях
  result.Tds = int16_t(_DS18b20-> getTempCByIndex(0)*100);

  sensors_event_t humidity, temp;
  // Чтение данных
  _aht->getEvent(&humidity, &temp);
  result.Taht = int16_t(temp.temperature*100);
  result.Haht = int16_t(humidity.relative_humidity);

  result.Tbmp = float(_bmp->readTemperature()*100);
  result.Pbmp = float(_bmp->readPressure()*100);

  return result;
}