#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main()
{

	// Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW; // can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();
}

// 探索型ゲーム
// player wasd操作
// enemy random
// enemyに当たるとplayerのライフが減少