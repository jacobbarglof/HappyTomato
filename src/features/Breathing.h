#ifndef BREATHING_H
#define BREATHING_H

#include "features/Feature.h"

class Breathing : public Feature {
public:
  Breathing();
  void update() override;
  void draw(DisplayManager& display) override;

private:
  enum State {
    SELECT_METHOD,
    SELECT_DURATION,
    RUNNING,
    COMPLETE
  };

  enum BreathMethod {
    BOX,
    FOUR_SEVEN_EIGHT,
    WIMHOF,
    RESONANT,
    NUM_METHODS
  };

  State state;
  BreathMethod selectedMethod;
  int durationMinutes;

  unsigned long sessionStart;
  unsigned long lastPhaseChange;
  int phaseIndex;
  bool inHold;
  unsigned long totalDuration;

  void reset();
  void drawMenu(DisplayManager& display);
  void drawDurationSelector(DisplayManager& display);
  void drawSession(DisplayManager& display);
  void drawLoadingBar(DisplayManager& display, float progress);
  const char* getMethodName(BreathMethod method);
  const char* getPhaseName();
  unsigned long getPhaseLength();
};

#endif
