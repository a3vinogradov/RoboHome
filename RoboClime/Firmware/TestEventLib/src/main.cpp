#include <Arduino.h>
#include <EventLib.h>
#include <ButtonLib.h>  // Новая библиотека

EventLib::EventDispatcher dispatcher;
ButtonLib::Button button(1, 16, dispatcher);  // ID=1, GPIO16

class MainController : public EventLib::IEventHandler {
public:
    void handleEvent(const EventLib::Event& event) override {
        // Обработка событий от кнопки
        Serial.println("Button event received");
    }
};

MainController controller;

void setup() {
    Serial.begin(115200);
    dispatcher.subscribe(&controller);
}

void loop() {
    button.update();
    delay(10);
}