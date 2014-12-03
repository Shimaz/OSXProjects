#include "ofApp.h"

#define FORWARD 1
#define BACKWARD 0

#define IMG_TOP_WIDTH 520
#define IMG_TOP_HEIGHT 280

#define IMG_SIDE_WIDTH 556
#define IMG_SIDE_HEIGHT 648

#define IMG_DID_WIDTH 1920
#define IMG_DID_HEIGHT 1080


#define SIDE_START_POSITION 1920
#define SIDE_END_POSITION 3840


#define DID_START_POSITION 3840
#define DID_END_POSITION 5760

#define INITIAL_SPEED 20

#define SCREEN_SAVER_SPEED 0.5f
#define SCREEN_SAVER_ON_TIME 10


//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetBackgroundColor(0, 255, 0);
    
    ofSetFrameRate(60);
    
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    ofSetCircleResolution(64);
    
    
    mainOutputSyphonServer.setName("Screen Outputh");
    mClient.setup();
    mClient.setApplicationName("Simple Serverh");
    mClient.setServerName("");
    posX = 0;
    
    SPEED = INITIAL_SPEED;
//    
//    for(int i = 0; i < 12; i++){
//
//        
//        posXX[i] = i * 400;
//    
//    }
    
    
    for(int i = 0; i < 38; i++){
        
    
        // Load Images
        string str = "top/" + ofToString(i+1) + ".png";
        
        imgTop[i].loadImage(str);
        
        
        string str2 = "side/" + ofToString(i + 1) + ".png";
        imgSide[i].loadImage(str2);
        
        
        string str3 = "did/DID_eng_" + ofToString(i + 1) + ".png";
        imgDID[i].loadImage(str3);
                            
    
        
        // Set Initial Positions
        
        if (i == 37) {
            pointDID[i].set(DID_START_POSITION - IMG_DID_WIDTH, 0);
            rawDID[i].set(DID_START_POSITION - IMG_DID_WIDTH, 0);
        
            pointTop[i].set(0 - IMG_TOP_WIDTH, (ofGetHeight() - IMG_TOP_HEIGHT)/2);
            rawTop[i].set(0 - IMG_TOP_WIDTH, (ofGetHeight() - IMG_TOP_HEIGHT)/2);
            
            pointSide[i].set(SIDE_START_POSITION - IMG_SIDE_WIDTH, (ofGetHeight() - IMG_SIDE_HEIGHT)/2);
            rawSide[i].set(SIDE_START_POSITION - IMG_SIDE_WIDTH, (ofGetHeight() - IMG_SIDE_HEIGHT)/2);
            
        }else{
            pointDID[i].set(DID_START_POSITION + (i * IMG_DID_WIDTH), 0);
            rawDID[i].set(DID_START_POSITION + (i * IMG_DID_WIDTH), 0);
            
            pointTop[i].set(i * IMG_TOP_WIDTH, (ofGetHeight() - IMG_TOP_HEIGHT)/2);
            rawTop[i].set(i * IMG_TOP_WIDTH, (ofGetHeight() - IMG_TOP_HEIGHT)/2);
            
            pointSide[i].set(SIDE_START_POSITION + (i * IMG_SIDE_WIDTH), (ofGetHeight() - IMG_SIDE_HEIGHT)/2);
            rawSide[i].set(SIDE_START_POSITION + (i * IMG_SIDE_WIDTH), (ofGetHeight() - IMG_SIDE_HEIGHT)/2);
            
        }
        
        pointDID[i].z = 10;
        rawDID[i].z = 10;
        
        pointTop[i].z = 0;
        rawTop[i].z = 0;
        
        pointSide[i].z = 20;
        rawSide[i].z = 20;
        
        
        
        
       
    }
    
    
    // set video poistion
    // x, y : position in 1920 1080 screen
    // z : sequence number (use for multiplying x position)
    pointVideoData[0].x = 100;
    pointVideoData[0].y = 100;
    pointVideoData[0].z = 9;
    
    pointVideoData[1].x = 100;
    pointVideoData[1].y = 100;
    pointVideoData[1].z = 12;
    
    
    pointVideoData[2].x = 100;
    pointVideoData[2].y = 100;
    pointVideoData[2].z = 13;
    
    
    pointVideoData[3].x = 100;
    pointVideoData[3].y = 100;
    pointVideoData[3].z = 15;
    
    
    pointVideoData[4].x = 100;
    pointVideoData[4].y = 100;
    pointVideoData[4].z = 17;
    
    
    vid[0].loadMovie("video/199401.mp4");
    vid[1].loadMovie("video/201309.mp4");
    vid[2].loadMovie("video/201303.mp4");
    vid[3].loadMovie("video/199401.mp4");
    vid[4].loadMovie("video/201309.mp4");
    
    
    
    
    
    
    
    /*
     
     set initial position of images
     
     */
    isInitial = true;
    if(isInitial) setInitialPosition(0, 26 * 3 + 18, 26 * 7 + 4);
    
    for(int i =0; i < videoCount; i++){
        
        pointVideo[i].x = pointDID[(int)pointVideoData[i].z].x + pointVideoData[i].x;
        pointVideo[i].y = pointVideoData[i].y;
        
    }
    
    nowTime = ofGetElapsedTimef();
    
    
    rdeg = rx = ry = rz = 0;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
 
    if(!isInitial){
        
        dt = ofClamp((ofGetElapsedTimef() - nowTime) / 1, 0, 1);
        
        
        float v = ofxEasingFunc::Linear::easeOut(dt);
        
        
        for (int i = 0; i < 38; i++) {
            
            //        pointTop[i].x =  pointTop[i].x + (v * (rawTop[i].x - pointTop[i].x));
            //        pointSide[i].x = pointSide[i].x + (v * (rawSide[i].x - pointSide[i].x));
            //        pointDID[i].x = pointDID[i].x + (v * (rawDID[i].x - pointDID[i].x));
            
            
            pointTop[i] = rawTop[i];
            pointSide[i] = rawSide[i];
            pointDID[i] = rawDID[i];
            
        }
        
//        strDebug = ofToString(v) + " " + ofToString(ofGetElapsedTimef() - nowTime) + " " + ofToString(nowTime) + " " + ofToString(ofGetElapsedTimef());
        
//        strDebug = ofToString(pointVideo[0].x) + " " + ofToString(pointDID[9].x);
    }
    
//    if(!vid[1].isPlaying()){
//        vid[1].play();
//    }
//    
//    vid[1].update();
//
    
    
    for(int i = 0; i < videoCount; i++){
        
        if(pointVideo[i].x >= DID_START_POSITION && pointVideo[i].x <= DID_END_POSITION){
            
            if (!vid[i].isPlaying()) {
                vid[i].play();
            }
            vid[i].update();
            
            
        }else{
            
            if (vid[i].isPlaying()) {
                vid[i].stop();
                vid[i].firstFrame();
            }
            
        }
        

        
    }
    
    dTime = (int)(ofGetElapsedTimef() - nowTime);
    
    
    
    if (dTime > SCREEN_SAVER_ON_TIME) {
        updatePositionScreenSaver();
        isScreenSaverOn = true;
        pastFrameCount++;
//        SPEED = pastFrameCount % 20;
        SPEED = INITIAL_SPEED;
    }else{
        isScreenSaverOn = false;
        SPEED = INITIAL_SPEED;
    }
    
    
    strDebug = "dTime:" + ofToString(dTime) + " nowTime:" + ofToString(nowTime) + " SPEED:" + ofToString(SPEED);
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    

    ofSetColor(1, 36, 156);
    ofRect(0, (float)(1080 - IMG_TOP_HEIGHT) / 2., 1920, IMG_TOP_HEIGHT);
    ofRect(1920, (float)(1080 - IMG_SIDE_HEIGHT) / 2., 1920, IMG_SIDE_HEIGHT);
    ofRect(3840, 0, 1920, 1080);


    
    ofSetColor(255, 255, 255);
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
    
    
    
    
    for(int i = 0; i < videoCount; i++){
        
        if(pointVideo[i].x >= DID_START_POSITION && pointVideo[i].x <= DID_END_POSITION){
           
            
            

            
            vid[i].draw(pointVideo[i].x, pointVideo[i].y);
            
            
            
        }
        
        
    }
    
    
    
    
    
    
//    float t = ofClamp(ofGetElapsedTimef() / 20., 0, 1);
//    float v = ofxEasingFunc::Cubic::easeOut(t);
//    ofCircle(t * ofGetWidth(), v * ofGetHeight(), 10);
    
    
//    vid[1].draw(100, 100);
    
    
    
    
//    ofSetColor(255, 0, 0);
    ofDrawBitmapString(strDebug, 100, 100);
    
    mClient.draw(50, 50);
    mainOutputSyphonServer.publishScreen();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case 'O':
        case 'o':
            
            setPostion(BACKWARD);
            
            break;
            
        case 'P':
        case 'p':
            
            setPostion(FORWARD);
            
            break;
            
            
        case 'F':
        case 'f':
            
            resetPosition();
            
           
            
            break;
            
            
        case 'a':
            rdeg = rdeg - 5;
            break;
            
            
        case 's':
            rdeg = rdeg + 5;
            break;
            
            
        case 'z':
            rx = rx - 0.5f;
            break;
            
        case 'x':
            rx = rx + 0.5f;
            break;
            
            
        case 'c':
            ry = ry - 0.5f;
            break;
            
        case 'v':
            ry = ry + 0.5f;
            break;
            
            
        case 'q':
            rz = rz - 0.5f;
            break;
            
            
        case 'w':
            rz = rz + 0.5f;
            
            
            
        default:
            break;
    }
    
    nowTime = ofGetElapsedTimef();
//    strDebug = "deg: " + ofToString(rdeg) + " x:" + ofToString(rx) + " y:" + ofToString(ry) + " z:" + ofToString(rz);
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
                rawTop[i].x = rawTop[i].x + SPEED;
                
                
                if(rawSide[i].x >= SIDE_START_POSITION + (IMG_SIDE_WIDTH * 36)){
                    rawSide[i].x = SIDE_START_POSITION - (IMG_SIDE_WIDTH * 2);
                    
                }
                rawSide[i].x = rawSide[i].x + ((float)SPEED * ((float)IMG_SIDE_WIDTH / (float)IMG_TOP_WIDTH));
                
                
                if(rawDID[i].x >= DID_START_POSITION + (IMG_DID_WIDTH * 36)){
                    rawDID[i].x = DID_START_POSITION - (IMG_DID_WIDTH * 2);
                }
                rawDID[i].x = rawDID[i].x + ((float)SPEED * ((float)IMG_DID_WIDTH / (float)IMG_TOP_WIDTH));
                

            }
            
            for (int i = 0; i < videoCount; i++){
            
                pointVideo[i].x = rawDID[(int)pointVideoData[i].z].x + pointVideoData[i].x;
            }
            
            break;
            
        case BACKWARD:
            
            for (int i = 0; i < 38; i++){
                if(rawTop[i].x <= -(2 * IMG_TOP_WIDTH)){
                    rawTop[i].x = IMG_TOP_WIDTH * 36;
                }
                rawTop[i].x = rawTop[i].x - SPEED;
                
                
                if (rawSide[i].x <= SIDE_START_POSITION - (2 * IMG_SIDE_WIDTH)) {
                    rawSide[i].x = SIDE_START_POSITION + (IMG_SIDE_WIDTH * 36);
                }
                rawSide[i].x = rawSide[i].x - ((float)SPEED * ((float)IMG_SIDE_WIDTH / (float)IMG_TOP_WIDTH));
                
                
                if(rawDID[i].x <= DID_START_POSITION - (2 * IMG_DID_WIDTH)){
                    rawDID[i].x = DID_START_POSITION + (IMG_DID_WIDTH * 36);
                }
                rawDID[i].x = rawDID[i].x - ((float)SPEED * ((float)IMG_DID_WIDTH / (float)IMG_TOP_WIDTH));
                
            }
            
            
            for (int i = 0; i < videoCount; i++) {

                pointVideo[i].x = rawDID[(int)pointVideoData[i].z].x + pointVideoData[i].x;
            }
            
            break;
            
        default:
            break;
    }
    
//    if (pointTop[0].x == 0) {
//        resetPosition();
//    }

}



void ofApp::updatePositionScreenSaver(){
    for (int i = 0; i < 38; i++){
        if(rawTop[i].x <= -(2 * IMG_TOP_WIDTH)){
            rawTop[i].x = IMG_TOP_WIDTH * 36;
        }
        rawTop[i].x = rawTop[i].x - SCREEN_SAVER_SPEED;
        
        
        if (rawSide[i].x <= SIDE_START_POSITION - (2 * IMG_SIDE_WIDTH)) {
            rawSide[i].x = SIDE_START_POSITION + (IMG_SIDE_WIDTH * 36);
        }
        rawSide[i].x = rawSide[i].x - ((float)SCREEN_SAVER_SPEED * ((float)IMG_SIDE_WIDTH / (float)IMG_TOP_WIDTH));
        
        
        if(rawDID[i].x <= DID_START_POSITION - (2 * IMG_DID_WIDTH)){
            rawDID[i].x = DID_START_POSITION + (IMG_DID_WIDTH * 36);
        }
        rawDID[i].x = rawDID[i].x - ((float)SCREEN_SAVER_SPEED * ((float)IMG_DID_WIDTH / (float)IMG_TOP_WIDTH));
        
    }
    
    
    for (int i = 0; i < videoCount; i++) {
        
        pointVideo[i].x = rawDID[(int)pointVideoData[i].z].x + pointVideoData[i].x;
    }

}


void ofApp::setInitialPosition(int topCount, int sideCount, int didCount){
    
    for (int j = 0; j < topCount; j++) {
        for (int i = 0; i < 38; i++){
            if(rawTop[i].x <= -(2 * IMG_TOP_WIDTH)){
                rawTop[i].x = IMG_TOP_WIDTH * 36;
            }
            rawTop[i].x = rawTop[i].x - SPEED;
            
            pointTop[i] = rawDID[i];
            
        }
        
    }
    
    for (int j = 0; j < sideCount; j++) {
        for (int i = 0; i < 38; i++){
            
            if (rawSide[i].x <= SIDE_START_POSITION - (2 * IMG_SIDE_WIDTH)) {
                rawSide[i].x = SIDE_START_POSITION + (IMG_SIDE_WIDTH * 36);
            }
            rawSide[i].x = rawSide[i].x - ((float)SPEED * ((float)IMG_SIDE_WIDTH / (float)IMG_TOP_WIDTH));
            
            pointSide[i] = rawSide[i];
            
            
        }
    }
    
    
    
    for (int j = 0; j < didCount; j++) {
        for (int i = 0; i < 38; i++){
            
            
            if(rawDID[i].x <= DID_START_POSITION - (2 * IMG_DID_WIDTH)){
                rawDID[i].x = DID_START_POSITION + (IMG_DID_WIDTH * 36);
            }
            rawDID[i].x = rawDID[i].x - ((float)SPEED * ((float)IMG_DID_WIDTH / (float)IMG_TOP_WIDTH));
            
            
            pointDID[i] = rawDID[i];
        }
    }
    

    isInitial = false;
}

void ofApp::resetPosition(){
    
    // OUT OF DATE
    // DO NOT USE
    
    for(int i = 0; i < 38; i++){
        
        if (i == 37) {
            pointDID[i].set(DID_START_POSITION - IMG_DID_WIDTH, 0);
            rawDID[i].set(DID_START_POSITION - IMG_DID_WIDTH, 0);
            
            pointTop[i].set(0 - IMG_TOP_WIDTH, (ofGetHeight() - IMG_TOP_HEIGHT)/2);
            rawTop[i].set(0 - IMG_TOP_WIDTH, (ofGetHeight() - IMG_TOP_HEIGHT)/2);
            
            pointSide[i].set(SIDE_START_POSITION - IMG_SIDE_WIDTH, (ofGetHeight() - IMG_SIDE_HEIGHT)/2);
            rawSide[i].set(SIDE_START_POSITION - IMG_SIDE_WIDTH, (ofGetHeight() - IMG_SIDE_HEIGHT)/2);
            
        }else{
            pointDID[i].set(DID_START_POSITION + (i * IMG_DID_WIDTH), 0);
            rawDID[i].set(DID_START_POSITION + (i * IMG_DID_WIDTH), 0);
            
            pointTop[i].set(i * IMG_TOP_WIDTH, (ofGetHeight() - IMG_TOP_HEIGHT)/2);
            rawTop[i].set(i * IMG_TOP_WIDTH, (ofGetHeight() - IMG_TOP_HEIGHT)/2);
            
            pointSide[i].set(SIDE_START_POSITION + (i * IMG_SIDE_WIDTH), (ofGetHeight() - IMG_SIDE_HEIGHT)/2);
            rawSide[i].set(SIDE_START_POSITION + (i * IMG_SIDE_WIDTH), (ofGetHeight() - IMG_SIDE_HEIGHT)/2);
            
        }
        
        pointDID[i].z = 10;
        rawDID[i].z = 10;
        
        pointTop[i].z = 0;
        rawTop[i].z = 0;
        
        pointSide[i].z = 20;
        rawSide[i].z = 20;
        
        
    }
}