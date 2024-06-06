#pragma once

#include "ball.h"
#include "ofMain.h"
#include "shima.h"

class ofApp : public ofBaseApp {
 public:
  void setup() override;
  void update() override;
  void draw() override;
  void mouseMoved(int x, int y) override;

  Ball balls[50];
  Shima shima;
};
