// Подключение: 
// ds18b20
// Gnd -> Gnd
// Dat -> GPIO4 (D4)
// Vcc -> 3.3V
//
// ANT20
// SCL -> GPIO22 (D22) 
// Gnd -> Gnd
// SDA -> GPIO21 (D21)
// Vdd -> 3.3V
//
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
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TFT_eSPI.h>

Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp;
TFT_eSPI tft = TFT_eSPI();

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

  Serial.println("init display");

  tft.init();
  //tft.initDMA();
  Serial.println("init successfuly");
  tft.setRotation(0);
  tft.fillScreen(TFT_BROWN);
  tft.setTextColor(TFT_WHITE, TFT_BROWN);
  tft.setTextSize(2);
  //tft.drawString("24.8", 20, 80, 8);
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

  tft.setTextColor(TFT_WHITE, TFT_BROWN);  

  String str = String(tempC);
  tft.drawString("Tin", 40, 60, 2);  tft.drawString(str.c_str(), 140, 60, 2);
  
  str = String(bmp.readTemperature() - 0.60);
  tft.drawString("Tbmp", 40, 100, 2); tft.drawString(str.c_str(), 140, 100, 2);
  
  str = String(temp.temperature );
  tft.drawString("Taht", 40, 140, 2); tft.drawString(str.c_str(), 140, 140, 2);

  delay(5000);
}