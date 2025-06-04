// InputManager.cpp - Enhanced pot and button handling with click detection

#include "hardware/InputManager.h"

void InputManager::begin() {
  pinMode(buttonPin, INPUT_PULLUP);
  lastPotValue = analogRead(potPin);
}

void InputManager::update() {
  // --- Potentiometer Scroll Logic ---
  int potValue = analogRead(potPin);
  scrollAmount = 0;

  if (abs(potValue - lastPotValue) > 150) {
    scrollAmount = (potValue > lastPotValue) ? 1 : -1;
    lastPotValue = potValue;
  }

  // --- Button Click Detection ---
  bool currentState = digitalRead(buttonPin) == LOW;
  buttonPressed = currentState;

  singleClickFlag = false;
  doubleClickFlag = false;
  longPressFlag = false;

  unsigned long now = millis();

  if (currentState && !lastButtonState) {
    pressStartTime = now; // button pressed
  }

  if (!currentState && lastButtonState) { // released
    unsigned long duration = now - pressStartTime;
    if (duration >= longPressDuration) {
      longPressFlag = true;
      lastClickTime = 0;
    } else {
      if (now - lastClickTime < 400) {
        doubleClickFlag = true;
        lastClickTime = 0;
      } else {
        singleClickFlag = true;
        lastClickTime = now;
      }
    }
    pressStartTime = 0;
  } else if (currentState && (now - pressStartTime >= longPressDuration)) {
    longPressFlag = true;
    lastClickTime = 0;
  }

  lastButtonState = currentState;
}

int InputManager::getScrollAmount() {
  return scrollAmount;
}

bool InputManager::isButtonPressed() {
  return buttonPressed;
}

bool InputManager::singleClicked() {
  return singleClickFlag;
}

bool InputManager::doubleClicked() {
  return doubleClickFlag;
}

bool InputManager::longPressed() {
  return longPressFlag;
}
