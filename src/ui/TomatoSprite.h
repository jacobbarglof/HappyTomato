#ifndef TOMATO_SPRITE_H
#define TOMATO_SPRITE_H

#include "hardware/DisplayManager.h"

class TomatoSprite {
public:
  void drawIdle(DisplayManager& display, int x, int y);
  void drawCheer(DisplayManager& display, int x, int y);
  void drawBored(DisplayManager& display, int x, int y);
  void drawSad(DisplayManager& display, int x, int y);
  void cycleIdle(DisplayManager& display, int x, int y);
private:
  void drawBitmap(DisplayManager& display, int x, int y, const uint8_t* bitmap);
};

#endif
