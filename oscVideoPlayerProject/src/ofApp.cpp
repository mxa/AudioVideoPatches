#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("oscVideoPlayer");
	ofBackground(0,0,0);
    ofSetFrameRate(50); // run at 50 fps
	ofSetVerticalSync(true);

	// Uncomment this to show movies with alpha channels
	// moviePayload.setPixelFormat(OF_PIXELS_RGBA);

	moviePayload.load("../bass2.mov");
	// moviePayload.setLoopState(OF_LOOP_NORMAL);
    moviePayload.setPaused(true);

    // listen on the given port
	ofLog() << "listening for osc messages on port " << PORT;
	receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){

    // check for waiting messages
	while(receiver.hasWaitingMessages()){

		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);

		if(m.getAddress() == "/frame"){
			framef = m.getArgAsFloat(0);
		}
	}
    moviePayload.update();
    if (prevframef != framef){
        moviePayload.setFrame(framef);
        prevframef = framef;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetHexColor(0xFFFFFF);

    moviePayload.draw(10,50);
    ofSetHexColor(0x000000);
    ofPixels & pixels = moviePayload.getPixels();

    int vidWidth = pixels.getWidth();
    int vidHeight = pixels.getHeight();
    int nChannels = pixels.getNumChannels();

    ofSetHexColor(0x000000);
    string buf = "listening for OSC messages on port " + ofToString(PORT);
	ofDrawBitmapStringHighlight(buf, 10, 20);
	string frame = "displaying frame # " + ofToString(framef) + " of " + ofToString(moviePayload.getTotalNumFrames());
	ofDrawBitmapStringHighlight(frame, 10, 35);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    switch(key){
        case '0':
            moviePayload.firstFrame();
        break;
        case '1':
            moviePayload.setFrame(100);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
