#include <Arduino.h>
#include "EventDispatcher.h"
#include "Button.h"
#include "MainController.h"


EventDispatcher dispatcher;
Button button(16, dispatcher);
MainController controller(dispatcher, button);

void setup() {
    Serial.begin(115200);
}

void loop() {
    controller.update();  // Который вызовет button.update()
    delay(10);  // Небольшая задержка для стабильности
}