// Buzzer.cpp - Implementation of buzzer control

#include "hardware/Buzzer.h"


// Track mute state for the buzzer.  Stored per-instance so multiple buzzers can
// coexist without interfering with each other.
void Buzzer::begin() {
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  isMuted = true; // ensure starting with sound enabled
}

void Buzzer::click() {
  if (isMuted) return; // Don't play sound if muted
  digitalWrite(buzzerPin, HIGH);
  delay(1); // Short pulse duration
  digitalWrite(buzzerPin, LOW);
}

void Buzzer::setMute(bool mute) {
  isMuted = mute;
}