#include "features/Pomodoro.h"
#include "globals.h"
#include "ui/Menu.h"

extern Menu menu;

Pomodoro::Pomodoro() {
  state = SELECTING_WORK;
  workMinutes = 25;
  restMinutes = 5;
  breakMinutes = 5;
}

void Pomodoro::update() {
  int potVal = analogRead(39);
  unsigned long now = millis();

  // Handle post-focus buzzer click
  if (buzzUntilClicked && input.singleClicked()) {
    buzzUntilClicked = false;
    buzzer.click();
    state = SELECTING_BREAK;
  }

  // Handle long press (hold to cancel)
  static unsigned long holdStart = 0;
  if (state == PAUSED && input.isButtonPressed()) {
    if (holdStart == 0) holdStart = now;
    if (now - holdStart > 2000) {
      state = SELECTING_WORK;
      holdStart = 0;
      buzzer.click();
      return;
    }
  } else {
    holdStart = 0;
  }

  switch (state) {
    case SELECTING_WORK:
      workMinutes = map(potVal, 0, 4095, 15, 120);
      if (input.singleClicked()) {
        state = SELECTING_REST;
        buzzer.click();
      }
      break;

    case SELECTING_REST:
      restMinutes = map(potVal, 0, 4095, 5, 30);
      if (input.singleClicked()) {
        workDuration = workMinutes * 60000UL;
        startMillis = now;
        elapsedOffset = 0;
        state = RUNNING_WORK;
        buzzer.click();
      }
      break;

    case RUNNING_WORK:
    case RUNNING_BREAK:
      if (input.singleClicked()) {
        pauseMillis = now;
        state = PAUSED;
        buzzer.click();
        return;
      }
      if (input.doubleClicked()) {
        state = SELECTING_WORK;
        buzzer.click();
        return;
      }

      if ((now - startMillis) >= getCurrentDuration()) {
        if (state == RUNNING_WORK) {
          buzzUntilClicked = true;
          buzzer.click();
        } else {
          state = FINISHED;
          buzzer.click();
          menu.getGarden().addTomato();
        }
      }
      break;

    case PAUSED:
      if (input.singleClicked()) {
        // Resume
        elapsedOffset += (now - pauseMillis);
        startMillis = now - elapsedOffset;
        state = (workDuration > 0 && now - startMillis < workDuration) ? RUNNING_WORK : RUNNING_BREAK;
        buzzer.click();
      }
      if (input.doubleClicked()) {
        state = SELECTING_WORK;
        buzzer.click();
      }
      break;

    case SELECTING_BREAK:
      breakMinutes = map(potVal, 0, 4095, 1, 20);
      if (input.singleClicked()) {
        breakDuration = breakMinutes * 60000UL;
        startMillis = now;
        elapsedOffset = 0;
        state = RUNNING_BREAK;
        buzzer.click();
      }
      break;

    case FINISHED:
      if (input.doubleClicked()) {
        state = SELECTING_WORK;
        buzzer.click();
      }
      break;
  }

  // Continuous buzzer if waiting for click
  static unsigned long lastBuzz = 0;
  if (buzzUntilClicked && millis() - lastBuzz >= 1000) {
    buzzer.click();
    lastBuzz = millis();
  }
}

void Pomodoro::draw(DisplayManager& display) {
  char buf[16];

  // Show companion sprite in top-right corner
  switch (state) {
    case FINISHED:
      sprite.drawCheer(display, 90, 0);
      break;
    case PAUSED:
      sprite.drawSad(display, 90, 0);
      break;
    case RUNNING_BREAK:
      sprite.drawBored(display, 90, 0);
      break;
    default:
      sprite.drawIdle(display, 90, 0);
      break;
  }

  switch (state) {
    case SELECTING_WORK:
      sprintf(buf, "Work: %d min", workMinutes);
      display.drawText("Pomodoro", 30, 0);
      display.drawText(buf, 10, 20, 1);
      display.drawText("Click to set rest", 10, 50);
      break;

    case SELECTING_REST:
      sprintf(buf, "Rest: %d min", restMinutes);
      display.drawText("Pomodoro", 30, 0);
      display.drawText(buf, 10, 20, 1);
      display.drawText("Click to start", 10, 50);
      break;

    case SELECTING_BREAK:
      sprintf(buf, "Break: %d min", breakMinutes);
      display.drawText("Set break time", 10, 10);
      display.drawText(buf, 10, 25, 2);
      display.drawText("Click to start", 10, 50);
      break;

    case RUNNING_WORK:
    case RUNNING_BREAK:
    case PAUSED: {
      unsigned long now = millis();
      unsigned long elapsed = (state == PAUSED) ? (pauseMillis - startMillis) : (now - startMillis);
      unsigned long duration = getCurrentDuration();
      int remaining = (duration - elapsed) / 1000;
      int min = remaining / 60;
      int sec = remaining % 60;

      sprintf(buf, "%02d:%02d", min, sec);
      display.drawText((state == RUNNING_WORK || state == PAUSED) ? "Focus" : "Break", 10, 10);
      display.drawText(buf, 30, 25, 2);

      if (state == PAUSED)
        display.drawText("Paused", 0, 50);

      break;
    }

    case FINISHED:
      display.drawText("All done!", 30, 25);
      display.drawText("Double-click to reset", 0, 50);
      break;
  }

  if (buzzUntilClicked) {
    display.drawText("Click to stop buzzer", 0, 55);
  }
}

unsigned long Pomodoro::getCurrentDuration() {
  return (state == RUNNING_WORK || state == PAUSED) ? workDuration : breakDuration;
}
