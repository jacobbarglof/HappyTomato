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

  if (!lastButtonState && currentState) { // Rising edge: button just pressed
    unsigned long now = millis();
    if (now - lastClickTime < 400) {
      doubleClickFlag = true;
      lastClickTime = 0; // reset
    } else {
      singleClickFlag = true;
      lastClickTime = now;
    }
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
