#include <Arduino.h>
#define KEY_PIN 16 // D0/GPIO16 - вибродатчик и тактовая кнопка. Она нормально разомкнуты

int gLastState;

void setup() {
  Serial.begin(9600);
  Serial.println();

  pinMode(KEY_PIN, INPUT);
  gLastState = digitalRead(KEY_PIN);
  if (gLastState == LOW)
  {
    delay(3000);
    gLastState = digitalRead(KEY_PIN);
  }
  if (gLastState == LOW)
  {
    Serial.println("Reset Mode detected");
  } else
  {
    Serial.println("Normal mode detected");
  }

}

void loop() {
  int _CurState = digitalRead(KEY_PIN);
  if (gLastState != _CurState)
  {
    gLastState = _CurState;
    Serial.print("Switch to ");
    Serial.println(_CurState==HIGH?"Up":"Push");
  };
}

