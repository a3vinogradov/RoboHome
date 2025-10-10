#pragma once

#include <Arduino.h>
#include "IEventHandler.h"

class EventDispatcher {
private:
    static const uint8_t MAX_HANDLERS = 3;  // Минимум для теста
    IEventHandler* handlers[MAX_HANDLERS];
    uint8_t handlerCount = 0;

public:
    void subscribe(IEventHandler* handler) {
        if (handlerCount < MAX_HANDLERS) {
            handlers[handlerCount++] = handler;
        }
    }

    void dispatch(const Event& event) {
        for (uint8_t i = 0; i < handlerCount; i++) {
            handlers[i]->handleEvent(event);
        }
    }
};