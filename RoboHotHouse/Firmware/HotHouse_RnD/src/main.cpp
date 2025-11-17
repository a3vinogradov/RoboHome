#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>
#include <OneWire.h>
#include <DallasTemperature.h>

Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp;

// Пин подключения DS18B20
const int oneWireBus = 4;     

// Настройка объектов OneWire и DallasTemperature
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  Serial.println("AHT20 & BMP280 & DS18b20 test");
  
  if (!aht.begin()) {
    Serial.println("Не удалось найти AHT20!");
    while (1);
  }
  Serial.println("AHT20 найден!");

  // Инициализация I2C и датчика
  if (!bmp.begin(0x77)) {  // Если не работает, попробуйте 0x77
    Serial.println("Не удалось найти BMP280!");
    while (1);
  }  
    // Настройка параметров датчика
  bmp.setSampling(
    Adafruit_BMP280::MODE_NORMAL,
    Adafruit_BMP280::SAMPLING_X2,
    Adafruit_BMP280::SAMPLING_X16,
    Adafruit_BMP280::FILTER_X16,
    Adafruit_BMP280::STANDBY_MS_500
  );

  sensors.begin();

}

void loop() {
  sensors_event_t humidity, temp;
  
  // Чтение данных
  aht.getEvent(&humidity, &temp);
  
  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" °C");
  
  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");
  /////////////////////
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" °C");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude(1013.25)); // 1013.25 - давление на уровне моря
  Serial.println(" m");
  ////////////////////
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




  Serial.println();
  delay(5000);
}