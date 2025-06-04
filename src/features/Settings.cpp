// Settings.cpp - Menu and configuration UI for HappyTomato

#include "features/Settings.h"
#include "globals.h"
#include "hardware/DisplayManager.h"


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

  static unsigned long lastScrollTime = 0;
  const unsigned long scrollCooldown = 20; // match main menu rate

  int scroll = input.getScrollAmount();
  int pot = analogRead(39);

  if (mode == MENU) {
    if (scroll != 0 && millis() - lastScrollTime > scrollCooldown) {
      int prev = selection;
      selection += scroll;
      if (selection < 0) selection = 0;
      if (selection > 2) selection = 2;
      if (selection != prev && !muted) buzzer.click();
      lastScrollTime = millis();
    }

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
    if (scroll != 0 && millis() - lastScrollTime > scrollCooldown) {
      scrollLine += scroll;
      if (scrollLine < 0) scrollLine = 0;
      if (scrollLine > 4) scrollLine = 4;
      lastScrollTime = millis();
    }
  }
}

void Settings::draw(DisplayManager& display) {
  if (mode == INSTRUCTIONS) {
    sprite.drawWink(display, 90, 0);
  } else {
    sprite.drawIdle(display, 90, 0);
  }

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
    "Hold button to exit",
    "Set timer with pot",
    "Breathe with rhythm"
  };

  display.drawText(lines[scrollLine], 0, 30);
  display.drawText("Hold to exit", 0, 55);
}
