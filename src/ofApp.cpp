#include "ofApp.h"

int snowX[1000];
int snowY[1000];
double snowSpeed[1000];

float score;

//--------------------------------------------------------------
void ofApp::setup()
{

    // 雪の配列
    for (int i = 0; i < 1000; i++)
    {
        snowX[i] = ofRandom(0, 1024);
        snowY[i] = ofRandom(0, 768);
        snowSpeed[i] = ofRandom(1, 3);
    }

    shima = Shima(500, 648, 0.3);
}

//--------------------------------------------------------------
void ofApp::update()
{
    score = ofGetElapsedTimef();

    for (int i = 0; i < 20; i++)
    {
        balls[i].update();
    }

    for (int i = 0; i < score / 5; i++)
    {
        if (!balls[i].show)
        {
            balls[i] =
                Ball(ofRandom(50, ofGetWidth()), ofRandom(30, 100), 3, 3, true);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofFill();
    // 雪の描画
    ofSetColor(255, 255, 255);
    for (int i = 0; i < 1000; i++)
    {
        ofDrawCircle(snowX[i], snowY[i], 5);
        snowY[i] += snowSpeed[i];
        if (snowY[i] > ofGetHeight())
            snowY[i] = 0;
    }

    for (int i = 0; i < 20; i++)
    {
        balls[i].draw();
    }
    shima.draw();
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
    shima.x = x;
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

// #include "ofApp.h"

// // ボールクラス
// class Ball
// {
// public:
//     void setup()
//     {
//         x = ofRandom(ofGetWidth());
//         y = ofRandom(ofGetHeight());
//         vx = ofRandom(2, 5);
//         vy = ofRandom(2, 5);
//         radius = 10;
//     }

//     void update()
//     {
//         x += vx;
//         y += vy;

//         // 壁と床との衝突判定
//         if (x + radius >= ofGetWidth() || x - radius <= 0)
//         {
//             vx *= -1;
//         }
//         if (y + radius >= ofGetHeight())
//         {
//             vy *= -1;
//         }
//     }

//     void draw()
//     {
//         ofDrawCircle(x, y, radius);
//     }

//     float x, y;
//     float vx, vy;
//     float radius;
// };

// // 四角形クラス
// class Player
// {
// public:
//     void setup()
//     {
//         y = ofGetHeight() / 2;
//         width = 50;
//         height = 20;
//     }

//     void update(float mouseX)
//     {
//         x = mouseX - width / 2;
//     }

//     void draw()
//     {
//         ofDrawRectangle(x, y, width, height);
//     }

//     float x, y;
//     float width, height;
// };

// // ゲームの状態
// enum GameState
// {
//     PLAYING,
//     GAME_OVER
// };

// int gameState = PLAYING;

// // ボール
// vector<Ball> balls;

// // プレイヤー
// Player player;

// // スコア
// int score = 0;

// // ライフ
// int life = 3;

// void setup()
// {
//     ofSetupScreen();
//     ofSetFrameRate(60);

//     // ボールを初期化する
//     for (int i = 0; i < 3; i++)
//     {
//         Ball ball;
//         ball.setup();
//         balls.push_back(ball);
//     }

//     // プレイヤーを初期化する
//     player.setup();
// }

// void update()
// {
//     if (gameState == PLAYING)
//     {
//         // プレイヤーを更新する
//         player.update(ofGetMouseX());

//         // ボールを更新する
//         for (int i = 0; i < balls.size(); i++)
//         {
//             balls[i].update();

//             // プレイヤーとボールの衝突判定
//             if ((player.x < balls[i].x && balls[i].x < player.x) && (player.y < balls[i].y && balls[i].y < player.y))
//             {
//                 life--;
//                 if (life <= 0)
//                 {
//                     gameState = GAME_OVER;
//                 }
//             }
//         }

//         // スコアを更新する
//         if (balls[balls.size() - 1].y + balls[balls.size() - 1].radius >= ofGetHeight())
//         {
//             score++;

//             // スコアが5の倍数になったらボールを増やす
//             if (score % 5 == 0)
//             {
//                 Ball ball;
//                 ball.setup();
//                 balls.push_back(ball);
//             }
//         }
//     }
// }

// void draw()
// {
//     ofBackground(200);

//     // プレイヤーを描画する
//     player.draw();

//     // ボールを描画する
//     for (int i = 0; i < balls.size(); i++)
//     {
//         balls[i].draw();
//     }

//     // スコアを描画する
//     ofDrawBitmapString("Score: " + ofToString(score), 20, 2);
// }