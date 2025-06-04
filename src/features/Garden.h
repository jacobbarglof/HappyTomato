#ifndef GARDEN_H
#define GARDEN_H

#include "features/Feature.h"

class Garden : public Feature {
public:
  Garden();
  void update() override;
  void draw(DisplayManager& display) override;
  void addTomato();  // Increase plant growth stage

private:
  int stage;
  int cloud1X;
  int cloud2X;
  int swayOffset;
  int swayDir;
  unsigned long lastCloudMove;
  unsigned long lastSway;
};

#endif
