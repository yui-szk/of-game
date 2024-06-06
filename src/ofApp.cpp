#include "ofApp.h"

int snowX[1000];
int snowY[1000];
double snowSpeed[1000];

float score;
int life = 3;

//--------------------------------------------------------------
void ofApp::setup() {
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

//--------------------------------------------------------------
void ofApp::update() {
  score = ofGetElapsedTimef();

  for (int i = 0; i < 20; i++) {
    balls[i].update();
  }

  for (int i = 0; i < score / 5; i++) {
    if (!balls[i].show) {
      balls[i] =
          Ball(ofRandom(50, ofGetWidth()), ofRandom(30, 100), 3, 3, true);
    }
  }

  for (int i = 0; i < 20; i++) {
    if (balls[i].show == true &&
        sqrt(pow((balls[i].x - shima.x), 2) +
             pow((balls[i].y - (shima.y + shima.scale * 70)), 2)) <
            shima.scale * 160) {
      life--;
      balls[i].show = false;
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofFill();

  // 雪の描画
  ofSetColor(255, 255, 255);
  for (int i = 0; i < 1000; i++) {
    ofDrawCircle(snowX[i], snowY[i], 5);
    snowY[i] += snowSpeed[i];
    if (snowY[i] > ofGetHeight()) snowY[i] = 0;
  }

  for (int i = 0; i < 20; i++) {
    balls[i].draw();
  }
  shima.draw();

  int x = 900, y = 70, side = 40;
  for (int i = 0; i < life; i++) {
    ofDrawRectangle(x - 60 * i, y, side, side);
  }
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) { shima.x = x; }

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollposX, float scrollposY) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}