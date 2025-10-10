#pragma once
#include <Arduino.h>
#include <EventLib.h>

namespace ButtonLib {
    enum class ButtonEventType {
        PRESS,
        RELEASE, 
        CLICK,
        LONG_PRESS
    };

    struct ButtonEvent {
        ButtonEventType type;
        uint8_t buttonId;
        uint32_t durationMs;
    };

    class Button : public EventLib::IEventHandler {
    private:
        uint8_t _pin;
        uint8_t _id;
        bool _lastState;
        uint32_t _pressStartTime;
        EventLib::EventDispatcher& _dispatcher;
        
    public:
        Button(uint8_t id, uint8_t pin, EventLib::EventDispatcher& dispatcher);
        void update();
        void handleEvent(const EventLib::Event& event) override;
    };
}