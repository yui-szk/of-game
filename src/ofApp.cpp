#include "ofApp.h"

int mainX;
int mainY;

int posX1;
int posY1;

int posX2;
int posY2;

float scale;

int height;

int snowX[800];
int snowY[800];
double snowSpeed[800];

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(200, 200, 200);
    ofSetCircleResolution(200);
    std::cout << ofGetFrameRate() << std::endl;

    mainX = 250;
    mainY = 190;

    posX1 = mainX;
    posY1 = mainY;
    scale = 0.3;

    height = ofGetHeight();

    for (int i = 0; i < 800; i++)
    {
        snowX[i] = ofRandom(-800, 1300);
        snowY[i] = ofRandom(0, 380);
        snowSpeed[i] = ofRandom(1, 3);
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofFill();

    // 雪の描画
    ofSetColor(255, 255, 255);
    for (int i = 0; i < 800; i++)
    {
        ofDrawCircle(snowX[i], snowY[i], 5);
        snowY[i] += snowSpeed[i];
        if (snowY[i] > height)
            snowY[i] = 0;
    }

    // 羽と尾の描画
    ofSetColor(28, 28, 32);
    ofDrawTriangle(posX1 - scale * 155, posY1 + scale * 10, posX1 - scale * 125, posY1 - scale * 10, posX1 - scale * 150, posY1 + scale * 100);
    ofDrawTriangle(posX1 + scale * 125, posY1 - scale * 10, posX1 + scale * 160, posY1 + scale * 10, posX1 + scale * 150, posY1 + scale * 100);
    ofDrawTriangle(posX1, posY1 + scale * 170, posX1 + scale * 180, posY1 + scale * 230, posX1 + scale * 230, posY1 + scale * 200);

    // 頭と体の描画
    ofSetColor(255, 255, 255);
    ofDrawEllipse(posX1, posY1, scale * 250, scale * 200);
    ofDrawEllipse(posX1, posY1 + scale * 80, scale * 300, scale * 310);

    // 目と嘴の描画
    ofSetColor(0, 0, 0);
    ofDrawCircle(posX1 - scale * 50, posY1 - scale * 30, scale * 15);
    ofDrawCircle(posX1 + scale * 50, posY1 - scale * 30, scale * 15);
    ofDrawTriangle(posX1 - scale * 20, posY1 - scale * 15, posX1, posY1 - scale * 30, posX1 + scale * 20, posY1 - scale * 15);
}

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'w')
    {
        for (int i = 0; i < 800; i++)
        {
            snowY[i] += 7;
        }
    }
    if (key == 's')
    {
        for (int i = 0; i < 800; i++)
        {
            snowY[i] -= 7;
        }
    }
    if (key == 'a')
    {
        for (int i = 0; i < 800; i++)
        {
            snowX[i] += 7;
        }
    }
    if (key == 'd')
    {
        for (int i = 0; i < 800; i++)
        {
            snowX[i] -= 7;
        }
    }
    if (key == '+')
        scale += 0.5;
    if (key == '-')
        scale -= 0.5;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollposX, float scrollposY)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
