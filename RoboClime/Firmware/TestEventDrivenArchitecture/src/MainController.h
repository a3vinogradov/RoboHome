#pragma once

#include <Arduino.h>
#include "EventDispatcher.h"
#include "IEventHandler.h"
#include "Button.h"

class MainController : public IEventHandler {
private:
    EventDispatcher& dispatcher;
    Button& button;
    uint8_t clickCount = 0;  // Для демонстрации

public:
    MainController(EventDispatcher& eventDispatcher, Button& btn) 
        : dispatcher(eventDispatcher), button(btn) {
        dispatcher.subscribe(this);
    }

    void handleEvent(const Event& event) override {
        if (event.type == EventType::BUTTON_CLICK) {
            clickCount++;
            // Здесь реакция на клик
            Serial.print("Click #");
            Serial.println(clickCount);
        }
    }

    void update() {
        button.update();
    }
};