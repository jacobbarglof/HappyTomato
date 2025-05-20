// Feature.h - Abstract base class for all HappyTomato features

#ifndef FEATURE_H
#define FEATURE_H

#include "hardware/DisplayManager.h"

class Feature {
public:
  virtual void update() = 0;
  virtual void draw(DisplayManager& display) = 0;
};

#endif
