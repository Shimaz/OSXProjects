#include "ofApp.h"

#define FORWARD 1
#define BACKWARD 0


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
        
    
        // Load Images
        string str = "top/" + ofToString(i+1) + ".jpg";
        imgTop[i].loadImage(str);
        
        
        string str2 = "side/" + ofToString(i + 1) + ".jpg";
        imgSide[i].loadImage(str2);
        
        
        string str3 = "did/" + ofToString(i + 1) + ".jpg";
        imgDID[i].loadImage(str3);
                            
    
        
        // Set Initial Positions
        
        pointDID[i].set(3840 + (i * 1920), 0);
        pointTop[i].set(i * 520, 400);
        pointSide[i].set(1920 + (i * 400), 325);
    
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
    

    
    
//    ofSetColor(255, 255, 255);
//    
//    for(int i = 0; i < 12; i++){
//        
//        ofCircle(posXX[i], 100, 100);
//        ofCircle(posXX[i], 500, 100);
//        ofCircle(posXX[i], 900, 100);
//    }
    
    
    for(int i = 0; i < 38; i++){
    
        imgTop[i].draw(pointTop[i]);
        imgSide[i].draw(pointSide[i]);
        imgDID[i].draw(pointDID[i]);
        
    
    }
    
    
    
    mClient.draw(50, 50);
    mainOutputSyphonServer.publishScreen();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case 'o':
            
            setPostion(BACKWARD);
            
            break;
            
        case 'p':
            
            setPostion(FORWARD);
            
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



//--------------------------------------------------------------
void ofApp::setPostion(int direction){
    
    switch (direction) {
        case FORWARD:
            
            for (int i = 0; i < 38; i++){
            
                pointTop[i].x = pointTop[i].x + 5;
                pointSide[i].x = pointSide[i].x + 5;
                pointDID[i].x = pointDID[i].x + 5;
            }
            
            break;
            
        case BACKWARD:
            
            for (int i = 0; i < 38; i++){
                pointTop[i].x = pointTop[i].x - 5;
                pointSide[i].x = pointSide[i].x - 5;
                pointDID[i].x = pointDID[i].x - 5;
                
            }
            
            break;
            
        default:
            break;
    }

}