#include "TomatoSprite.h"
#include "hardware/DisplayManager.h"
extern DisplayManager display;

void TomatoSprite::drawIdle(DisplayManager& display, int x, int y) {
  display.drawText(" (o_o) ", x, y);
}

void TomatoSprite::drawCheer(DisplayManager& display, int x, int y) {
  display.drawText(" (^o^) ", x, y);
}

void TomatoSprite::drawSad(DisplayManager& display, int x, int y) {
  display.drawText(" (;_;) ", x, y);
}

void TomatoSprite::drawWink(DisplayManager& display, int x, int y) {
  display.drawText(" (^_~) ", x, y);
}
