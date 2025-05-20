#ifndef SETTINGS_H
#define SETTINGS_H

#include "features/Feature.h"

class Settings : public Feature {
public:
  Settings();
  void update() override;
  void draw(DisplayManager& display) override;

private:
  enum Mode {
    MENU,
    BRIGHTNESS,
    INSTRUCTIONS
  };

  Mode mode;
  int selection;
  boolean muted;
  int brightness;
  int scrollLine;

  void drawMenu(DisplayManager& display);
  void drawBrightness(DisplayManager& display);
  void drawInstructions(DisplayManager& display);
};

#endif
