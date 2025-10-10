#include "Button.h"
#include "ButtonConfig.h"

namespace ButtonLib {
    Button::Button(uint8_t id, uint8_t pin, EventLib::EventDispatcher& dispatcher) 
        : _id(id), _pin(pin), _dispatcher(dispatcher), _lastState(HIGH) {
        pinMode(_pin, ButtonConfig::DEFAULT_PULLUP ? INPUT_PULLUP : INPUT);
    }

    void Button::update() {
        bool currentState = digitalRead(_pin);
        uint32_t currentTime = millis();
        
        // Логика обработки нажатий с антидребезгом
        if (currentState != _lastState) {
            if (currentState == LOW) { // Нажатие (для PULLUP)
                _pressStartTime = currentTime;
                
                ButtonEvent event{ButtonEventType::PRESS, _id, 0};
                // Конвертируем в базовое событие EventLib
                EventLib::Event baseEvent{/* ... */};
                _dispatcher.dispatch(baseEvent);
            } else { // Отпускание
                uint32_t pressDuration = currentTime - _pressStartTime;
                
                ButtonEventType type = (pressDuration > ButtonConfig::LONG_PRESS_DELAY_MS) 
                    ? ButtonEventType::LONG_PRESS 
                    : ButtonEventType::CLICK;
                    
                ButtonEvent event{type, _id, pressDuration};
                // Конвертируем и диспатчим
            }
            _lastState = currentState;
        }
    }
    
    void Button::handleEvent(const EventLib::Event& event) {
        // Обработка событий от других компонентов (если нужно)
    }
}