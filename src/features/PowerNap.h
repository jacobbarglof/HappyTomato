#ifndef POWERNAP_H
#define POWERNAP_H

#include "features/Feature.h"

class PowerNap : public Feature {
public:
  PowerNap();
  void update() override;
  void draw(DisplayManager& display) override;

private:
  enum State { SELECTING, NAPPING, DONE };
  State state;

  int napMinutes;
  unsigned long startMillis;
  unsigned long napDuration;

  void startNap();
  void endNap();
};

#endif
