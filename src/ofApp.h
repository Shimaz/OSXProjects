#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"

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
    
    ofxSyphonServer mainOutputSyphonServer;
    ofxSyphonServer individualTextureSyphonServer;
    ofxSyphonClient mClient;
    
    
    int posX;
    
    int posXX[12];
    
    
    
    ofImage imgTop[38];
    ofImage imgSide[38];
    ofImage imgDID[38];
    
    ofPoint pointTop[38];
    ofPoint pointSide[38];
    ofPoint pointDID[38];
    
    
    ofShader shaderTop;
    ofShader shaderSide;
    ofShader shaderDID;

};
