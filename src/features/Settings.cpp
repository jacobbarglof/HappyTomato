#include "features/Settings.h"
#include "hardware/InputManager.h"
#include "hardware/Buzzer.h"
#include "hardware/DisplayManager.h"

extern DisplayManager display;
extern InputManager input;
extern Buzzer buzzer;

Settings::Settings() {
  mode = MENU;
  selection = 0;
  muted = false;
  brightness = 255;
  scrollLine = 0;
}

void Settings::update() {
  if (mode == INSTRUCTIONS && input.doubleClicked()) {
    mode = MENU;
    return;
  }

  int pot = analogRead(39);
  if (mode == MENU) {
    selection = map(pot, 0, 4095, 0, 2);
    if (input.singleClicked()) {
      if (selection == 0) {
        muted = !muted;
        buzzer.setMute(muted);
      } else if (selection == 1) {
        mode = BRIGHTNESS;
      } else if (selection == 2) {
        mode = INSTRUCTIONS;
        scrollLine = 0;
      }
      if (!muted) buzzer.click();
    }
  } else if (mode == BRIGHTNESS) {
    brightness = map(pot, 0, 4095, 0, 255);
    display.setContrast(0x81);           // SSD1306_SETCONTRAST
    display.setContrast(brightness);     // 0–255

    if (input.singleClicked()) {
      mode = MENU;
      if (!muted) buzzer.click();
    }
  } else if (mode == INSTRUCTIONS) {
    scrollLine = map(pot, 0, 4095, 0, 4);
  }
}

void Settings::draw(DisplayManager& display) {
  if (mode == MENU) {
    drawMenu(display);
  } else if (mode == BRIGHTNESS) {
    drawBrightness(display);
  } else if (mode == INSTRUCTIONS) {
    drawInstructions(display);
  }
}

void Settings::drawMenu(DisplayManager& display) {
  display.drawText("Settings", 40, 0);
  display.drawText(selection == 0 ? "> Mute: " : "  Mute: ", 0, 15);
  display.drawText(muted ? "On" : "Off", 65, 15);

  display.drawText(selection == 1 ? "> Brightness" : "  Brightness", 0, 30);
  display.drawText(selection == 2 ? "> Help" : "  Help", 0, 45);
}

void Settings::drawBrightness(DisplayManager& display) {
  display.drawText("Brightness", 20, 0);
  char buf[16];
  sprintf(buf, "%d / 255", brightness);
  display.drawText(buf, 40, 30, 2);
  display.drawText("Click to save", 20, 55);
}

void Settings::drawInstructions(DisplayManager& display) {
  display.drawText("How to Use", 30, 0);

  const char* lines[] = {
    "Scroll to select",
    "Click to enter mode",
    "Double click to exit",
    "Set timer with pot",
    "Breathe with rhythm"
  };

  display.drawText(lines[scrollLine], 0, 30);
  display.drawText("Double-click to exit", 0, 55);
}
