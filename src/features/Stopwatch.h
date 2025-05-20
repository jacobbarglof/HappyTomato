#ifndef STOPWATCH_H
#define STOPWATCH_H

#include "features/Feature.h"

class Stopwatch : public Feature {
public:
  Stopwatch();
  void update() override;
  void draw(DisplayManager& display) override;

private:
  bool running;
  unsigned long startMillis;
  unsigned long elapsedMillis;
};

#endif
