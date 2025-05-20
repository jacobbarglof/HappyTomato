// Menu.cpp - Scrollable feature menu for HappyTomato

#include "ui/Menu.h"
#include "hardware/Buzzer.h"

extern Buzzer buzzer;

void Menu::begin() {
  currentSelection = 0;
}

void Menu::update(int scrollAmount) {
  static unsigned long lastScrollTime = 0;
  const unsigned long scrollCooldown = 20; // ms

  if (scrollAmount != 0 && millis() - lastScrollTime > scrollCooldown) {
    int prev = currentSelection;

    currentSelection += scrollAmount;
    if (currentSelection < 0) currentSelection = 0;
    if (currentSelection >= NUM_OPTIONS) currentSelection = NUM_OPTIONS - 1;

    if (currentSelection != prev) {
      buzzer.click();  // Click when menu item changes
    }

    lastScrollTime = millis();
  }
}

void Menu::draw(DisplayManager& display) {
  const int lineHeight = 10;
  const int maxVisible = 5;
  int start = currentSelection - 2;

  if (start < 0) start = 0;
  if (start > NUM_OPTIONS - maxVisible) start = NUM_OPTIONS - maxVisible;
  if (start < 0) start = 0;

  for (int i = 0; i < maxVisible; ++i) {
    int index = start + i;
    if (index >= NUM_OPTIONS) break;

    int y = 10 + i * lineHeight;
    if (index == currentSelection) {
      display.drawText("> ", 0, y);
    }
    display.drawText(options[index].c_str(), 12, y);
  }
}

Feature* Menu::selectCurrentFeature() {
  switch (currentSelection) {
    case 0: return &pomodoro;
    case 1: return &stopwatch;
    case 2: return &pong;
    case 3: return &breathing;
    case 4: return &powerNap;
    case 5: return &garden;
    case 6: return &settings;
    default: return nullptr;
  }
}
