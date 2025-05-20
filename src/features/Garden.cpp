// Garden.cpp - Tracks tomato growth based on completed focus sessions

#include "features/Garden.h"
#include "hardware/InputManager.h"
#include "ui/TomatoSprite.h"

extern InputManager input;
extern TomatoSprite sprite;

Garden::Garden() {
  tomatoes = 0;
}

void Garden::update() {
  if (input.doubleClicked()) {
    // Exit to menu
  }
}

void Garden::draw(DisplayManager& display) {
  display.drawText("My Garden", 30, 0);
  sprite.drawIdle(display, 100, 0);

  for (int i = 0; i < tomatoes; ++i) {
    int x = 10 + (i % 6) * 18;
    int y = 20 + (i / 6) * 20;
    display.drawText("(o)", x, y);
  }

  if (tomatoes == 0)
    display.drawText("No tomatoes yet.", 10, 35);

  display.drawText("Double to exit", 10, 55);
}


void Garden::addTomato() {
  tomatoes++;
}
