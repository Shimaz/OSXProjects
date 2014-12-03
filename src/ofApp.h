#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "ofxEasingFunc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
    
    
    void setPostion(int direction);
    void resetPosition();
    void setInitialPosition(int topCount, int sideCount, int didCount);
    
    ofxSyphonServer mainOutputSyphonServer;
    ofxSyphonServer individualTextureSyphonServer;
    ofxSyphonClient mClient;
    
    
    int posX;
    
//    int posXX[12];
    
    bool isInitial;
    
    
    ofImage imgTop[38];
    ofImage imgSide[38];
    ofImage imgDID[38];
    
    
    ofPoint pointTop[38];
    ofPoint pointSide[38];
    ofPoint pointDID[38];
    
    
    ofPoint rawTop[38];
    ofPoint rawSide[38];
    ofPoint rawDID[38];
    
    
    
    ofImage imgg;
    
    string strDebug;
    float dt;
    float nowTime;

    int videoCount = 5;
    ofVideoPlayer vid[5];
    ofPoint pointVideo[5];
    ofPoint pointVideoData[5];


};
