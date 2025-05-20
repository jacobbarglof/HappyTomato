// Buzzer.cpp - Implementation of buzzer control

#include "hardware/Buzzer.h"


boolean isMuted = false; // Mute state
void Buzzer::begin() {
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
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