#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetBackgroundColor(0, 255, 0);
    
    ofSetFrameRate(60);
    
    ofSetCircleResolution(64);
    
    mainOutputSyphonServer.setName("Screen Outputh");
    mClient.setup();
    mClient.setApplicationName("Simple Serverh");
    mClient.setServerName("");
    posX = 0;
    
    
    for(int i = 0; i < 12; i++){

        
        posXX[i] = i * 400;
    
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(posX >= 5760) posX = 0;
    
    for(int i = 0; i < 12; i++){
        
        if(posXX[i] >= 5760) posXX[i] = 0;
        
        posXX[i] += 8;
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    ofSetColor(255, 255, 255);
    
    for(int i = 0; i < 12; i++){
        
        ofCircle(posXX[i], 100, 100);
        ofCircle(posXX[i], 500, 100);
        ofCircle(posXX[i], 900, 100);
    }
    
    
    
    mClient.draw(50, 50);
    mainOutputSyphonServer.publishScreen();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case 'o':
            
            posX--;
            
            break;
            
        case 'p':
            
            posX++;
            
            break;
            
            
            
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
