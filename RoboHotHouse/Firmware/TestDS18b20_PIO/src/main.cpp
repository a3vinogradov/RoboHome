// Подключение модуля датчика 
// ds18d20 ->  ESP32
// -----------------
// Gnd     ->  Gnd
// Vcc     ->  5V
// Dat     ->  D4 - любой цифровой
// Dat     ->  R4700  ->  D2  - только для голого датчика, без платы модуля

#include <OneWire.h>
#include <DallasTemperature.h>

// Пин подключения DS18B20
const int oneWireBus = 4;     

// Настройка объектов OneWire и DallasTemperature
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  // Запрос температуры
  sensors.requestTemperatures(); 
  
  // Чтение температуры в Цельсиях
  float tempC = sensors.getTempCByIndex(0);
  
  // Проверка ошибок чтения
  if (tempC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println(" °C");
  } else {
    Serial.println("Error: Could not read temperature data");
  }
  
  delay(2000);
}