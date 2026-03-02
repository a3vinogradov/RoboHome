// Настройки в файле .pio\libdeps\esp32\TFT_eSPI\User_Setup.h
// #define TFT_HEIGHT 240 // GC9A01 240 x 240
// ...
// #define GC9A01_DRIVER // оставить только этот, остальные закоментарить
// ...
// Определить пины для дисплея. Остальные закоментарить
// #define TFT_MOSI (SDA) 15 // In some display driver board, it might be written as "SDA" and so on.
// #define TFT_SCLK (SCL) 14
// #define TFT_CS   (CS)   5 // Chip select control pin
// #define TFT_DC   (DC)  27 // Data Command control pin
// #define TFT_RST  (RST) 33 // Reset pin (could connect to Arduino RESET pin)

#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("init display");

  tft.init();
  //tft.initDMA();
  Serial.println("init successfuly");
  tft.setRotation(0);
  tft.fillScreen(TFT_BROWN);
  tft.setTextColor(TFT_WHITE, TFT_BROWN);
  tft.setTextSize(1);
  //tft.setCursor(40, 120);
  //tft.println("Hello, GC9A01!");
  Serial.println("Draw string ""24.8"" ...");
  tft.drawString("24.8", 20, 80, 8);
  Serial.println("finish cketch");
}

void loop() {
  tft.setTextColor(TFT_BLACK, TFT_BROWN);  
  tft.drawString("25.8", 20, 80, 8);
  tft.setTextColor(TFT_WHITE, TFT_TRANSPARENT);  
  tft.drawString("25.8", 23, 83, 8);
  delay(2000);
  tft.setTextColor(TFT_BLACK, TFT_BROWN);  
  tft.drawString("0.00", 20, 80, 8);
  tft.setTextColor(TFT_WHITE, TFT_TRANSPARENT);  
  tft.drawString("0.00", 23, 83, 8);
  delay(2000);
}