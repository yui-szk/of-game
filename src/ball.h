#pragma once

#include "ofMain.h"

class Ball {
 public:
  Ball() : x(0), y(0), dx(0), dy(0), show(false) {}
  Ball(int _x, int _y, int _dx, int _dy, bool _show)
      : x(_x), y(_y), dx(_dx), dy(_dy), show(_show) {}

  int x, y, dx, dy;
  bool show;
  void update();
  void draw();
};