// Stopwatch.cpp - Stopwatch logic for HappyTomato

#include "features/Stopwatch.h"
#include "globals.h"
#include "hardware/DisplayManager.h"


Stopwatch::Stopwatch() {
  running = false;
  startMillis = 0;
  elapsedMillis = 0;
}

void Stopwatch::update() {
  if (input.singleClicked()) {
    if (running) {
      // Stop the stopwatch
      elapsedMillis += millis() - startMillis;
      running = false;
    } else {
      // Start or resume the stopwatch
      startMillis = millis();
      running = true;
    }
    buzzer.click();
  }

  if (input.doubleClicked()) {
    // Reset stopwatch
    running = false;
    elapsedMillis = 0;
  }
}

void Stopwatch::draw(DisplayManager& display) {
  display.drawText("Stopwatch", 30, 0);

  if (running) {
    sprite.drawBored(display, 90, 0);
  } else {
    sprite.drawIdle(display, 90, 0);
  }

  unsigned long displayMillis = running ? (millis() - startMillis + elapsedMillis) : elapsedMillis;
  int sec = (displayMillis / 1000) % 60;
  int min = (displayMillis / 60000);

  char buf[16];
  sprintf(buf, "%02d:%02d", min, sec);
  display.drawText(buf, 30, 25, 2);

  if(running == false) {
    display.drawText("Stopped", 10, 48);
  }
}
