#include "ofApp.h"

#define FORWARD 1
#define BACKWARD 0

#define IMG_TOP_WIDTH 520
#define IMG_TOP_HEIGHT 280

#define IMG_SIDE_WIDTH 400
#define IMG_SIDE_HEIGHT 430

#define IMG_DID_WIDTH 1920
#define IMG_DID_HEIGHT 1080


#define SIDE_START_POSITION 1920
#define SIDE_END_POSITION 3840


#define DID_START_POSITION 3840
#define DID_END_POSITION 5760




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
    
//    
//    for(int i = 0; i < 12; i++){
//
//        
//        posXX[i] = i * 400;
//    
//    }
    
    for(int i = 0; i < 38; i++){
        
    
        // Load Images
        string str = "top/" + ofToString(i+1) + ".jpg";
        imgTop[i].loadImage(str);
        
        
        string str2 = "side/" + ofToString(i + 1) + ".jpg";
        imgSide[i].loadImage(str2);
        
        
        string str3 = "did/" + ofToString(i + 1) + ".jpg";
        imgDID[i].loadImage(str3);
                            
    
        
        // Set Initial Positions
        
        if (i == 37) {
            pointDID[i].set(DID_START_POSITION - IMG_DID_WIDTH, 0);
            rawDID[i].set(DID_START_POSITION - IMG_DID_WIDTH, 0);
        
            pointTop[i].set(0 - IMG_TOP_WIDTH, 400);
            rawTop[i].set(0 - IMG_TOP_WIDTH, 400);
            
            pointSide[i].set(SIDE_START_POSITION - IMG_SIDE_WIDTH, 325);
            rawSide[i].set(SIDE_START_POSITION - IMG_SIDE_WIDTH, 325);
            
        }else{
            pointDID[i].set(DID_START_POSITION + (i * IMG_DID_WIDTH), 0);
            rawDID[i].set(DID_START_POSITION + (i * IMG_DID_WIDTH), 0);
            
            pointTop[i].set(i * IMG_TOP_WIDTH, 400);
            rawTop[i].set(i * IMG_TOP_WIDTH, 400);
            
            pointSide[i].set(SIDE_START_POSITION + (i * IMG_SIDE_WIDTH), 325);
            rawSide[i].set(SIDE_START_POSITION + (i * IMG_SIDE_WIDTH), 325);
            
        }
        
        pointDID[i].z = 10;
        rawDID[i].z = 10;
        
        pointTop[i].z = 0;
        rawTop[i].z = 0;
        
        pointSide[i].z = 20;
        rawSide[i].z = 20;
        
        
        
        
        
        
    }
    
    
    
    
//    vid[1].set
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    if(posX >= 5760) posX = 0;
//    
//    for(int i = 0; i < 12; i++){
//        
//        if(posXX[i] >= 5760) posXX[i] = 0;
//        
//        posXX[i] += 8;
//        
//    }
//
//    float t = ofClamp(ofGetElapsedTimef() / 1pppppppp0, 0, 1);
    
    
    dt = ofClamp((ofGetElapsedTimef() - nowTime) / 1, 0, 1);
    
    
    float v = ofxEasingFunc::Cubic::easeOut(dt);
    
    for (int i = 0; i < 38; i++) {
    
        pointTop[i].x =  pointTop[i].x + (v * (rawTop[i].x - pointTop[i].x));
        pointSide[i].x = pointSide[i].x + (v * (rawSide[i].x - pointSide[i].x));
        pointDID[i].x = pointDID[i].x + (v * (rawDID[i].x - pointDID[i].x));

        
//        pointTop[i] = rawTop[i];
//        pointSide[i] = rawSide[i];
//        pointDID[i] = rawDID[i];
        
    }

    strDebug = ofToString(v) + " " + ofToString(ofGetElapsedTimef() - nowTime) + " " + ofToString(nowTime) + " " + ofToString(ofGetElapsedTimef());
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    ofSetColor(162, 146, 179);
    ofRect(0, 376.5f, 1920, 273);
    
    ofSetColor(0, 123, 139);
    ofRect(1920, 252, 1920, 576);
    
    ofSetColor(243, 190, 199);
    ofRect(3840, 0, 1920, 1080);

    
    // draw top images with subsection
    
    for(int i = 0; i < 38; i++){
        if(pointTop[i].x >= -IMG_TOP_WIDTH && pointTop[i].x <= 1920 - IMG_TOP_WIDTH){
        
            
            imgTop[i].draw(pointTop[i]);
        }
        else if (pointTop[i].x <= 1920 && pointTop[i].x > 1920 - IMG_TOP_WIDTH){
            
            imgTop[i].drawSubsection(pointTop[i].x, pointTop[i].y, 1920 - pointTop[i].x, IMG_TOP_HEIGHT, 0, 0);
            
        }
        
    }
    
    
    
    // draw side images width subsection
    
    for (int i = 0; i < 38; i++){
     
        if(pointSide[i].x >= SIDE_START_POSITION - IMG_SIDE_WIDTH && pointSide[i].x < SIDE_START_POSITION){ // cliping left side
        
            imgSide[i].drawSubsection(SIDE_START_POSITION, pointSide[i].y,
                                      IMG_SIDE_WIDTH - (SIDE_START_POSITION - pointSide[i].x), IMG_SIDE_HEIGHT,
                                      (SIDE_START_POSITION - pointSide[i].x), 0);
            
        }else if(pointSide[i].x >= SIDE_START_POSITION && pointSide[i].x <= SIDE_END_POSITION - IMG_SIDE_WIDTH){
        
            imgSide[i].draw(pointSide[i]);
        
        }
        else if(pointSide[i].x <= SIDE_END_POSITION && pointSide[i].x > SIDE_END_POSITION - IMG_SIDE_WIDTH){ // cliping right side
            
            imgSide[i].drawSubsection(pointSide[i].x, pointSide[i].y, SIDE_END_POSITION - pointSide[i].x, IMG_SIDE_HEIGHT, 0, 0);
            
        }
     
    }
    
    
    // draw did images widh subsection
    for (int i = 0; i < 38; i++){
        if(pointDID[i].x >= DID_START_POSITION - IMG_DID_WIDTH && pointDID[i].x < DID_START_POSITION){
            
            imgDID[i].drawSubsection(DID_START_POSITION, pointDID[i].y,
                                     IMG_DID_WIDTH - (DID_START_POSITION - pointDID[i].x), IMG_DID_HEIGHT,
                                     (DID_START_POSITION - pointDID[i].x), 0);
            
        }else if(pointDID[i].x >= DID_START_POSITION && pointDID[i].x <= DID_END_POSITION){
        
            imgDID[i].draw(pointDID[i]);
        }
     
        
    }
    
    
    
    ofSetColor(255, 0, 0);
    ofDrawBitmapString(strDebug, 100, 100);
    
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
    
    dt = 0;
    nowTime = ofGetElapsedTimef();
    
    switch (direction) {
        case FORWARD:
            
            for (int i = 0; i < 38; i++){
            
                
                if (rawTop[i].x >= IMG_TOP_WIDTH * 36) {
                    rawTop[i].x = -(IMG_TOP_WIDTH * 2);
                }
                rawTop[i].x = rawTop[i].x + 20;
                
                
                if(rawSide[i].x >= SIDE_START_POSITION + (IMG_SIDE_WIDTH * 36)){
                    rawSide[i].x = SIDE_START_POSITION - (IMG_SIDE_WIDTH * 2);
                    
                }
                rawSide[i].x = rawSide[i].x + 20;
                
                
                if(rawDID[i].x >= DID_START_POSITION + (IMG_DID_WIDTH * 36)){
                    rawDID[i].x = DID_START_POSITION - (IMG_DID_WIDTH * 2);
                }
                rawDID[i].x = rawDID[i].x + 20;
            }
            
            break;
            
        case BACKWARD:
            
            for (int i = 0; i < 38; i++){
                if(rawTop[i].x <= -(2 * IMG_TOP_WIDTH)){
                    rawTop[i].x = IMG_TOP_WIDTH * 36;
                }
                rawTop[i].x = rawTop[i].x - 20;
                
                
                if (rawSide[i].x <= SIDE_START_POSITION - (2 * IMG_SIDE_WIDTH)) {
                    rawSide[i].x = SIDE_START_POSITION + (IMG_SIDE_WIDTH * 36);
                }
                rawSide[i].x = rawSide[i].x - 20;
                
                
                if(rawDID[i].x <= DID_START_POSITION - (2 * IMG_DID_WIDTH)){
                    rawDID[i].x = DID_START_POSITION + (IMG_DID_WIDTH * 36);
                }
                rawDID[i].x = rawDID[i].x - 20;
                
            }
            
            break;
            
        default:
            break;
    }
    
//    if (pointTop[0].x == 0) {
//        resetPosition();
//    }

}

void ofApp::resetPosition(){
    
    for(int i = 0; i < 38; i++){
        
        pointDID[i].set(3840 + (i * 1920), 0);
        pointDID[i].z = 10;
        pointTop[i].set(i * 520, 400);
        pointTop[i].z = 0;
        pointSide[i].set(1920 + (i * 400), 325);
        pointSide[i].z = 20;
        
    }
}