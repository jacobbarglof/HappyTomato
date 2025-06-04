// Garden.cpp - Tracks tomato growth based on completed focus sessions

#include "features/Garden.h"
#include "globals.h"


Garden::Garden() {
  stage = 0;
  cloud1X = 0;
  cloud2X = 60;
  swayOffset = 0;
  swayDir = 1;
  lastCloudMove = 0;
  lastSway = 0;
}

void Garden::update() {
  unsigned long now = millis();

  if (now - lastCloudMove > 100) {
    cloud1X -= 1;
    cloud2X -= 1;
    if (cloud1X < -20) cloud1X = 128;
    if (cloud2X < -20) cloud2X = 128;
    lastCloudMove = now;
  }

  if (now - lastSway > 300) {
    swayOffset += swayDir;
    if (swayOffset > 2 || swayOffset < -2) swayDir *= -1;
    lastSway = now;
  }
}

void Garden::draw(DisplayManager& display) {
  display.drawText("My Garden", 30, 0);

  if (stage >= 4) {
    sprite.drawCheer(display, 90, 0);
  } else {
    sprite.drawIdle(display, 90, 0);
  }

  // moving clouds
  display.drawText("~~~", cloud1X, 10);
  display.drawText("~~", cloud2X, 20);

  // ground line
  display.drawLine(0, 56, 127, 56, SSD1306_WHITE);

  int baseX = 64 + swayOffset;
  int baseY = 56;

  if (stage > 0) {
    display.drawLine(baseX, baseY, baseX, baseY - 8, SSD1306_WHITE);
  }

  if (stage > 1) {
    display.drawLine(baseX, baseY - 4, baseX - 3, baseY - 10, SSD1306_WHITE);
    display.drawLine(baseX, baseY - 4, baseX + 3, baseY - 10, SSD1306_WHITE);
  }

  if (stage > 2) {
    display.fillCircle(baseX, baseY - 11, 2, SSD1306_WHITE);
  }

  if (stage > 3) {
    display.fillCircle(baseX - 4, baseY - 8, 1, SSD1306_WHITE);
    display.fillCircle(baseX + 4, baseY - 8, 1, SSD1306_WHITE);
  }

  display.drawText("Hold to exit", 0, 55);
}


void Garden::addTomato() {
  if (stage < 4) stage++;
}
