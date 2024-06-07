#include "ofApp.h"

int snowX[1000];
int snowY[1000];
double snowSpeed[1000];

float score;
int life = 3;
int numBall = 50;

ofSoundPlayer backMusic;

void ofApp::setup() {
  // BGMをループ再生
  backMusic.load("snow.mp3");
  backMusic.setLoop(true);
  backMusic.play();

  ofSetCircleResolution(60);
  ofBackground(200);

  // 雪の配列
  for (int i = 0; i < 1000; i++) {
    snowX[i] = ofRandom(0, 1024);
    snowY[i] = ofRandom(0, 768);
    snowSpeed[i] = ofRandom(1, 3);
  }

  shima = Shima(500, 648, 0.3);
}

void ofApp::update() {
  if (life > 0) {
    score = ofGetElapsedTimef();
  }

  for (int i = 0; i < numBall; i++) {
    balls[i].update();
  }

  for (int i = 0; i < score / 5; i++) {
    if (!balls[i].show) {
      balls[i] =
          Ball(ofRandom(50, ofGetWidth()), ofRandom(30, 100), 4, 4, true);
    }
  }

  shima.update();

  // シマエナガとボールの当たり判定
  for (int i = 0; i < numBall; i++) {
    if (balls[i].show == true &&
        sqrt(pow((balls[i].x - shima.x), 2) +
             pow((balls[i].y - (shima.y + shima.scale * 70)), 2)) <
            shima.scale * 160) {
      life--;
      balls[i].show = false;
    }
  }
}

void ofApp::draw() {
  ofFill();

  // 雪の描画
  ofSetColor(255);
  for (int i = 0; i < 1000; i++) {
    ofDrawCircle(snowX[i], snowY[i], 5);
    snowY[i] += snowSpeed[i];
    if (snowY[i] > ofGetHeight()) snowY[i] = 0;
  }

  // ボールの描画
  for (int i = 0; i < numBall; i++) {
    balls[i].draw();
  }

  // ライフの描画
  int x = 900, y = 70, side = 40;
  for (int i = 0; i < life; i++) {
    ofDrawRectangle(x - 60 * i, y, side, side);
  }

  // スコアの描画
  ofDrawBitmapString("score:" + ofToString((int)score), 100, 100);

  // ゲームオーバー時の描画
  if (life <= 0) {
    for (int i = 0; i < numBall; i++) {
      balls[i].show = false;
      ofSetColor(90);
      ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
      ofSetColor(255);
      ofDrawBitmapString("final score:" + ofToString((int)score),
                         ofGetWidth() / 2 - 40, ofGetHeight() / 2);
    }
  }

  // 地面の描画
  ofSetColor(255);
  ofDrawRectangle(0, ofGetHeight() - 50, ofGetWidth(), 50);

  // シマエナガの描画
  shima.draw();
}

void ofApp::mouseMoved(int x, int y) { shima.x = x; }

void ofApp::keyPressed(int key) {
  if (key == 's') {
    life = 3;
    ofResetElapsedTimeCounter();
  }
}