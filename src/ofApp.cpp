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
    
    for(int i = 0; i < 38; i++){
        
        
        string str = "top/" + ofToString(i+1) + ".jpg";

        
        imgTop[i].loadImage(str);
        
        
        string str2 = "side/" + ofToString(i + 1) + ".jpg";

        
        imgSide[i].loadImage(str2);
        
        
        string str3 = "did/" + ofToString(i + 1) + ".jpg";
        
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
    
    ofSetColor(162, 146, 179);
    ofRect(0, 376.5f, 1920, 273);
    
    ofSetColor(0, 123, 139);
    ofRect(1920, 252, 1920, 576);
    
    ofSetColor(243, 190, 199);
    ofRect(3840, 0, 1920, 1080);
    
    ofImage img;
    img.loadImage("top/1.jpg");
    img.draw(100, 100);
    
    
//    ofSetColor(255, 255, 255);
//    
//    for(int i = 0; i < 12; i++){
//        
//        ofCircle(posXX[i], 100, 100);
//        ofCircle(posXX[i], 500, 100);
//        ofCircle(posXX[i], 900, 100);
//    }
    
    
    
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
