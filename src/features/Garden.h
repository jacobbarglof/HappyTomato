#ifndef GARDEN_H
#define GARDEN_H

#include "features/Feature.h"

class Garden : public Feature {
public:
  Garden();
  void update() override;
  void draw(DisplayManager& display) override;
  void addTomato();

private:
  int tomatoes;
};

#endif
