#include <Arduino.h>
#include "hardware/DisplayManager.h"
#include "hardware/InputManager.h"
#include "hardware/Buzzer.h"
#include "ui/Menu.h"
#include "features/Pomodoro.h"
#include "globals.h"
#include "ui/TomatoSprite.h"

// Global instances
DisplayManager display;
InputManager input;
Buzzer buzzer;
Menu menu;
TomatoSprite sprite;

// Active feature (nullptr if in menu)
Feature* activeFeature = nullptr;
void setup() {
  Serial.begin(115200);
  display.begin();
  input.begin();
  buzzer.begin();

  display.clear();
  display.drawText("HappyTomato V1.0", 0, 5, 1);
  display.drawText("Made with love <3", 0, 40, 1);
  delay(1500);
  display.update();
  delay(1000);

  menu.begin();
}


void loop() {
  input.update();

  if (activeFeature) {
    //  Run the active feature's logic
    activeFeature->update();

    display.clear();
    activeFeature->draw(display);
    display.update();

    //  Allow returning to menu
    if (input.doubleClicked()) {
      activeFeature = nullptr;
      buzzer.click();
    }

  } else {
    // Menu mode
    menu.update(input.getScrollAmount());
    display.clear();
    menu.draw(display);
    display.update();

    if (input.singleClicked()) {
      Feature* f = menu.selectCurrentFeature();
      if (f != nullptr) {
        activeFeature = f;
        buzzer.click();
      }
    }
  }

  delay(10);
}
