#pragma once
#include <Arduino.h>
#include "EventTypes.h"
#include "EventDispatcher.h"


class Button {
private:
    uint8_t pin;
    EventDispatcher& dispatcher;
    bool lastState = true;  // Предполагаем PULLUP

public:
    Button(uint8_t buttonPin, EventDispatcher& eventDispatcher) 
        : pin(buttonPin), dispatcher(eventDispatcher) {
        pinMode(pin, INPUT_PULLUP);
    }

    void update() {
        bool currentState = digitalRead(pin);
        
        // Обнаружение нажатия (LOW для PULLUP)
        if (lastState == true && currentState == false) {
            Event event{EventType::BUTTON_CLICK};
            dispatcher.dispatch(event);
        }
        
        lastState = currentState;
    }
};