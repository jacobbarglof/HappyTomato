#ifndef POMODORO_H
#define POMODORO_H

#include "features/Feature.h"

class Pomodoro : public Feature {
public:
  Pomodoro();
  void update() override;
  void draw(DisplayManager& display) override;

private:
  enum State {
    SELECTING_WORK,
    SELECTING_REST,
    RUNNING_WORK,
    SELECTING_BREAK,
    RUNNING_BREAK,
    PAUSED,
    FINISHED
  };
  State state;

  int workMinutes;
  int restMinutes;
  int breakMinutes;

  unsigned long startMillis;
  unsigned long pauseMillis;
  unsigned long elapsedOffset = 0;

  unsigned long workDuration;
  unsigned long restDuration;
  unsigned long breakDuration;
  unsigned long getCurrentDuration();

  bool buzzUntilClicked = false;
};

#endif
