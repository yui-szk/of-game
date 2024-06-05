#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(200, 200, 200);
    ofSetCircleResolution(200);
    std::cout << ofGetFrameRate() << std::endl;
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{

    ofColor colorOne(200, 200, 200);
    ofColor colorTwo(240, 240, 240);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);

    ofFill();

    float r, g, b;
    r = 225, g = 100, b = 0;

    for (float x = 0; x < 900; x += 1)
    {
        r -= x / 800, b += x / 800;
        ofSetColor(r, g, b);
        ofDrawCircle(100 + x, 100 * sin(ofDegToRad((2 * x) / 4)) + 200, 1);
    }

    // for (float x = 0; x < 900; x += 1)
    // {
    //     r -= x / 800, b += x / 800;
    //     ofSetColor(r, g, b);
    //     ofDrawCircle(100 + x, 100 * cos(ofDegToRad((2 * x) / 4)) + 200, 1);
    // }
}

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
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
