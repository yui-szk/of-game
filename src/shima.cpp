#include "shima.h"

void Shima::update() {
  if (x < 50) {
    x = 50;
  }
  if (x > ofGetWidth() - 50) {
    x = ofGetWidth() - 50;
  }
};

void Shima::draw() {
  // 羽と尾の描画
  ofSetColor(28, 28, 32);
  ofDrawTriangle(x - scale * 155, y + scale * 10, x - scale * 125,
                 y - scale * 10, x - scale * 150, y + scale * 100);
  ofDrawTriangle(x + scale * 125, y - scale * 10, x + scale * 160,
                 y + scale * 10, x + scale * 150, y + scale * 100);
  ofDrawTriangle(x, y + scale * 170, x + scale * 180, y + scale * 230,
                 x + scale * 230, y + scale * 200);

  // 頭と体の描画
  ofSetColor(255);
  ofDrawEllipse(x, y, scale * 250, scale * 200);
  ofDrawEllipse(x, y + scale * 80, scale * 300, scale * 310);

  // 目と嘴の描画
  ofSetColor(0);
  ofDrawCircle(x - scale * 50, y - scale * 30, scale * 15);
  ofDrawCircle(x + scale * 50, y - scale * 30, scale * 15);
  ofDrawTriangle(x - scale * 20, y - scale * 15, x, y - scale * 30,
                 x + scale * 20, y - scale * 15);
};