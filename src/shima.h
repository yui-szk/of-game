#pragma once

#include "ofMain.h"

class Shima {
 public:
  Shima() : x(0), y(0), scale(0) {}
  Shima(int _x, int _y, float _scale) : x(_x), y(_y), scale(_scale) {}

  int x, y;
  float scale;
  void update();
  void draw();
};