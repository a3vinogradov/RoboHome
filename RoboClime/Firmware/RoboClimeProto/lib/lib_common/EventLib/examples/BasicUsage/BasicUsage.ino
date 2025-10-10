#include <EventLib.h>

// Пример использования библиотеки
EventLib::EventDispatcher dispatcher;

class MyHandler : public EventLib::IEventHandler {
    void handleEvent(const EventLib::Event& event) override {
        if (event.type == EventLib::EventType::BUTTON_CLICK) {
            Serial.println("Event received!");
        }
    }
};

MyHandler handler;

void setup() {
    Serial.begin(115200);
    dispatcher.subscribe(&handler);
    
    // Тестовое событие
    EventLib::Event testEvent{EventLib::EventType::BUTTON_CLICK};
    dispatcher.dispatch(testEvent);
}

void loop() {}