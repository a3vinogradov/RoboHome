#pragma once

#include "EventTypes.h"

namespace EventLib {
    class IEventHandler {
    public:
        virtual void handleEvent(const Event& event) = 0;
    };
}