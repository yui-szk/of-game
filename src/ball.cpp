#include "ball.h"

void Ball::update() {
  x += dx;
  y += dy;

  if (y > ofGetHeight() - 54 || y < 0) {
    dy *= -1;
  }
  if (x > ofGetWidth() || x < 0) {
    dx *= -1;
  }
};

void Ball::draw() {
  if (show) {
    ofSetColor(0, 0, 0);
    ofDrawCircle(x, y, 8);
  }
};