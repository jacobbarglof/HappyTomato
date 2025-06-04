#include "features/Breathing.h"
#include "globals.h"


Breathing::Breathing() {
  reset();
}

void Breathing::reset() {
  state = SELECT_METHOD;
  selectedMethod = BOX;
  durationMinutes = 5;
  sessionStart = 0;
  lastPhaseChange = 0;
  phaseIndex = 0;
  inHold = false;
}

void Breathing::update() {
  if (input.doubleClicked()) {
    reset();
    return;
  }

  switch (state) {
    case SELECT_METHOD: {
      int pot = analogRead(39);
      int selection = map(pot, 0, 4095, 0, NUM_METHODS - 1);
      selectedMethod = static_cast<BreathMethod>(selection);
      if (input.singleClicked()) {
        buzzer.click();
        state = SELECT_DURATION;
      }
      break;
    }

    case SELECT_DURATION: {
      int pot = analogRead(39);
      durationMinutes = map(pot, 0, 4095, 1, 20);
      if (input.singleClicked()) {
        buzzer.click();
        state = RUNNING;
        sessionStart = millis();
        lastPhaseChange = millis();
        totalDuration = durationMinutes * 60000UL;
        phaseIndex = 0;
        inHold = false;
      }
      break;
    }

    case RUNNING: {
      unsigned long now = millis();
      if (now - lastPhaseChange > getPhaseLength()) {
        lastPhaseChange = now;
        phaseIndex++;
        buzzer.click();
      }

      if (now - sessionStart > totalDuration) {
        state = COMPLETE;
        buzzer.click();
      }
      break;
    }

    case COMPLETE:
      if (input.singleClicked()) {
        reset();
      }
      break;
  }
}

void Breathing::draw(DisplayManager& display) {
  if (state == COMPLETE) {
    sprite.drawCheer(display, 90, 0);
  } else if (state == RUNNING) {
    sprite.drawWink(display, 90, 0);
  } else {
    sprite.drawIdle(display, 90, 0);
  }

  switch (state) {
    case SELECT_METHOD:
      drawMenu(display);
      break;
    case SELECT_DURATION:
      drawDurationSelector(display);
      break;
    case RUNNING:
      drawSession(display);
      break;
    case COMPLETE:
      display.drawText("Session Complete", 20, 25);
      display.drawText("Click to restart", 20, 45);
      break;
  }
}

void Breathing::drawMenu(DisplayManager& display) {
  display.drawText("Select Method", 30, 0);

  if (selectedMethod > 0)
    display.drawText("<", 0, 30);
  display.drawText(getMethodName(selectedMethod), 40, 30, 1);
  if (selectedMethod < NUM_METHODS - 1)
    display.drawText(">", 110, 30);

  display.drawText("Click to confirm", 20, 55);
}

void Breathing::drawDurationSelector(DisplayManager& display) {
  display.drawText("Set Duration", 30, 0);

  char buf[16];
  sprintf(buf, "%d min", durationMinutes);
  display.drawText(buf, 45, 30, 2);

  display.drawText("Click to start", 20, 55);
}

void Breathing::drawSession(DisplayManager& display) {
  unsigned long elapsed = millis() - sessionStart;
  float progress = (float)elapsed / totalDuration;

  display.drawText(getMethodName(selectedMethod), 0, 0);
  display.drawText(getPhaseName(), 35, 20, 2);
  drawLoadingBar(display, progress);
}

void Breathing::drawLoadingBar(DisplayManager& display, float progress) {
  int barWidth = 100;
  int barHeight = 8;
  int x = 14;
  int y = 50;
  int fill = (int)(barWidth * progress);

  display.fillRect(x, y, fill, barHeight, SSD1306_WHITE);
  display.drawRect(x, y, barWidth, barHeight, SSD1306_WHITE);
}

const char* Breathing::getMethodName(BreathMethod method) {
  switch (method) {
    case BOX: return "Box";
    case FOUR_SEVEN_EIGHT: return "4-7-8";
    case WIMHOF: return "Wim Hof";
    case RESONANT: return "Resonant";
    default: return "Unknown";
  }
}

const char* Breathing::getPhaseName() {
  switch (selectedMethod) {
    case BOX:
      return (phaseIndex % 4 == 0) ? "Inhale" :
             (phaseIndex % 4 == 1) ? "Hold" :
             (phaseIndex % 4 == 2) ? "Exhale" : "Hold";

    case FOUR_SEVEN_EIGHT:
      return (phaseIndex % 3 == 0) ? "Inhale" :
             (phaseIndex % 3 == 1) ? "Hold" : "Exhale";

    case WIMHOF:
      return (phaseIndex < 30) ? "Breathe" : "Hold";

    case RESONANT:
      return (phaseIndex % 2 == 0) ? "Inhale" : "Exhale";

    default: return "";
  }
}

unsigned long Breathing::getPhaseLength() {
  switch (selectedMethod) {
    case BOX: return 4000;
    case FOUR_SEVEN_EIGHT:
      return (phaseIndex % 3 == 0) ? 4000 :
             (phaseIndex % 3 == 1) ? 7000 : 8000;
    case WIMHOF:
      return (phaseIndex < 30) ? 1500 : 30000;
    case RESONANT:
      return 5000;
    default: return 4000;
  }
}
