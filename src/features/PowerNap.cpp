// PowerNap.cpp - Nap timer feature logic

#include "features/PowerNap.h"
#include "globals.h"


PowerNap::PowerNap() {
  state = SELECTING;
  napMinutes = 10;
}

void PowerNap::update() {
  if (state == SELECTING) {
    int potVal = analogRead(39);
    napMinutes = map(potVal, 0, 4095, 5, 30); // Select between 5–30 mins

    if (input.singleClicked()) {
      startNap();
      buzzer.click();
    }
  }

  else if (state == NAPPING) {
    if (millis() - startMillis >= napDuration) {
      endNap();
      buzzer.click();
    }
  }

  if (input.doubleClicked()) {
    state = SELECTING;
  }
}

void PowerNap::draw(DisplayManager& display) {
  display.drawText("Power Nap", 30, 0);

  if (state == DONE) {
    sprite.drawCheer(display, 90, 0);
  } else if (state == NAPPING) {
    sprite.drawBored(display, 90, 0);
  } else {
    sprite.drawIdle(display, 90, 0);
  }

  if (state == SELECTING) {
    display.drawText("Set: ", 10, 20);
    display.drawText(String(napMinutes).c_str(), 50, 20);
    display.drawText("min", 80, 20);
    display.drawText("Click to start", 10, 40);
  } else if (state == NAPPING) {
    int remainingSec = (napDuration - (millis() - startMillis)) / 1000;
    int min = remainingSec / 60;
    int sec = remainingSec % 60;
    char buf[16];
    sprintf(buf, "%02d:%02d", min, sec);
    display.drawText("Time Left:", 10, 20);
    display.drawText(buf, 40, 35);
  } else if (state == DONE) {
    display.drawText("Wake up!", 35, 25);
    display.drawText("Double-click", 10, 45);
  }
}

void PowerNap::startNap() {
  napDuration = napMinutes * 60UL * 1000UL;
  startMillis = millis();
  state = NAPPING;
}

void PowerNap::endNap() {
  state = DONE;
}
