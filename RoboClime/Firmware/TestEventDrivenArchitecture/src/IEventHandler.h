#pragma once

#include "EventTypes.h"

class IEventHandler {
public:
    virtual void handleEvent(const Event& event) = 0;
};