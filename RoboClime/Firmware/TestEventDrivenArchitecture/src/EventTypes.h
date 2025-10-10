#pragma once

// Максимально простой тип события
enum class EventType {
    BUTTON_CLICK
};

// Структура события
struct Event {
    EventType type;
};