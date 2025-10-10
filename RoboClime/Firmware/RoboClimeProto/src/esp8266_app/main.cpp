#include "constants.h"
#include "TypeDef.h"
#include "IDisplay.h"
#include "DisplayTFT_1_28.h"
#include "ISensorBmp280.h"
#include "ISensorAht21.h"
#include "SensorAht21.h"
#include "common.h"
#include "IMainController.h"
#include "ILog.h"
#include "EventLib.h"
#include "ButtonLib.h"


DisplayTFT_1_28 gDisplayTFT_1_28;
DisplayTFT_1_28* pDisplay = &gDisplayTFT_1_28;
//IDisplay* gDisplay = &gDisplayTFT_1_28;


SensorAht21 gSensorAHT21;
ISensorAht21* pSensorAHT21 = &gSensorAHT21;

DataAht21 gDataAht21;
float maxTemp = 0;
float minTemp = 0;  

unsigned long lastResetTimer = 0;
unsigned long lastReadTimer = 0;

DisplayData _displayData;

EventLib::EventDispatcher dispatcher;

ButtonLib::Button button(1, 16, dispatcher);  // ID=1, GPIO16

class MainController : public EventLib::IEventHandler {
  private:
    unsigned short _SheetNumber = 0;  
  public:
    void handleEvent(const EventLib::Event& event) override {
      // Обработка событий от кнопки
      Serial.println("Button event received");
      _SheetNumber = (_SheetNumber==1?0:1);
    }

    unsigned short GetSheetNumber()
    {
      return _SheetNumber;
    }
};

MainController controller;

//////////////////////////

// Display tft 1.28
void renderDisplay()
{
  float elapsed = 100*(millis()-lastResetTimer)/(RESET_PERIOD); //todo: убрать первую 10ку
  
  _displayData.SheetNumber = controller.GetSheetNumber();
  _displayData.CurrentTemperature = gDataAht21.Temperature;
  _displayData.MaxTemperature = maxTemp;
  _displayData.MinTemperature = minTemp;
  _displayData.ElapsedDayPercent = elapsed;
  //pDisplay->Draw(gDataAht21.Temperature, maxTemp, minTemp, elapsed);
  pDisplay->Draw(&_displayData);
} 

// SensorManager
void updateExtremum()
{
  minTemp = gDataAht21.Temperature < minTemp ? gDataAht21.Temperature : minTemp;
  maxTemp = gDataAht21.Temperature > maxTemp ? gDataAht21.Temperature : maxTemp;
}

void resetExtremum()
{
  for (int i=LOG_LENGTH-1; i>0; --i)
  {
    _displayData.MaxLog[i] = _displayData.MaxLog[i-1];
    _displayData.MinLog[i] = _displayData.MinLog[i-1];
  }
  _displayData.MaxLog[0] = maxTemp;
  _displayData.MinLog[0] = minTemp;

  minTemp = gDataAht21.Temperature;
  maxTemp = gDataAht21.Temperature;  
}

// Timer
bool checkResetTimer()
{
  return  (millis() - lastResetTimer) > RESET_PERIOD;
}

void resetTimer()
{
  lastResetTimer = millis();
}
//////////////////////////

void setup() {
  Serial.begin(115200);
  pSensorAHT21->Setup();

  gDataAht21 = pSensorAHT21->Read();
  maxTemp = gDataAht21.Temperature;
  minTemp = gDataAht21.Temperature;
  //resetExtremum();

  resetTimer();
  
  dispatcher.subscribe(&controller);
  lastReadTimer = millis(); // todo: удалить
}

void loop() {

  button.update();
  delay(20);

  if (_displayData.SheetNumber != controller.GetSheetNumber())
  {
    renderDisplay();
  }

  if (checkResetTimer())
  {
    resetTimer();
    resetExtremum();
  }

  if (millis() - lastReadTimer > DISPLAY_UPDATE_PERIOD)
  {
    lastReadTimer = millis();

    gDataAht21 = pSensorAHT21->Read();
    Serial.print("Temperature: "); Serial.print(gDataAht21.Temperature); Serial.println(" degrees C");
    Serial.print("Humidity: "); Serial.print(gDataAht21.Hummidity); Serial.println("% rH");
    updateExtremum();

    renderDisplay();

  }

 
  //delay(DISPLAY_UPDATE_PERIOD);
}
