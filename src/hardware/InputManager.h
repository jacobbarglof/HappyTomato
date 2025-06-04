// InputManager.h - Enhanced pot and button input handler

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <Arduino.h>

class InputManager {
public:
  void begin();
  void update();

  int getScrollAmount();       // +1 or -1 based on pot movement
  bool isButtonPressed();      // Instantaneous read of the button state
  bool singleClicked();        // True once on press edge
  bool doubleClicked();        // True if double click detected
  bool longPressed();          // True if button held

private:
  const int potPin = 39;
  const int buttonPin = 5;

  int lastPotValue = 0;
  int scrollAmount = 0;

  bool buttonPressed = false;
  bool lastButtonState = true;
  bool singleClickFlag = false;
  bool doubleClickFlag = false;
  bool longPressFlag = false;
  unsigned long lastClickTime = 0;
  unsigned long pressStartTime = 0;
  const unsigned long longPressDuration = 400; // ms
};

#endif
