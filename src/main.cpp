#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    ofAppGLFWWindow win;
    
    win.setMultiDisplayFullscreen(true);

    
    
	ofSetupOpenGL(&win, 5760, 1080, OF_FULLSCREEN);			// <-------- setup the GL context

    ofSetWindowPosition(-1920, 0);
    
    ofBackground(0, 0, 0);
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
