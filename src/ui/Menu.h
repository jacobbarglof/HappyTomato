#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include "hardware/DisplayManager.h"
#include "features/Feature.h"
#include "features/Pomodoro.h"
#include "features/Stopwatch.h"
#include "features/Pong.h"
#include "features/Breathing.h"
#include "features/PowerNap.h"
#include "features/Garden.h"
#include "features/Settings.h"

// Menu handles the feature selection list and returns the selected Feature pointer
class Menu {
public:
  void begin();
  void update(int scrollAmount);
  void draw(DisplayManager& display);
  Feature* selectCurrentFeature();
  Feature* trySelectNow(bool buttonPressed); // NEW: immediately return a feature if button is pressed
  Garden& getGarden();

private:
  static const int NUM_OPTIONS = 7;
  String options[NUM_OPTIONS] = {
    "Pomodoro", "Stopwatch", "Pong", "Breathing", "Power Nap", "Garden", "Settings"
  };

  int currentSelection = 0;

  // Concrete features (stored here and returned by reference)
  Pomodoro pomodoro;
  Stopwatch stopwatch;
  Pong pong;
  Breathing breathing;
  PowerNap powerNap;
  Garden garden;
  Settings settings;
};

#endif
