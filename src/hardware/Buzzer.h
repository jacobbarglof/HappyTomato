#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
public:
  void begin();
  void click(); // Short beep
  void setMute(bool mute);

private:
  const int buzzerPin = 15;
  boolean isMuted = false; // Mute state
};

#endif
