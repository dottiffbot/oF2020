#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
ofSetCircleResolution(50);
ofSetBackgroundAuto(false);
ofSetFrameRate(60);
ofBackground(38,193,149);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(38,193,149);

	// stupid sean :(((
	 // int seconds = ofGetFrameNum()%60;
	int seconds =  ofGetFrameNum()/60;
	int fakeSeconds = seconds%7;

	 cout << seconds << endl;

	 if (fakeSeconds < 2){
	 	currentScene = 0;
	 } else if (fakeSeconds < 4){
	 	currentScene = 1;
	 }
     else if (fakeSeconds < 6) {
     	currentScene = 2;
     }
	


	 

	// FACE INSIDE PHONE
	if (currentScene == 0) {
		ofSetColor(255,255,0); 
	ofFill();
	ofDrawEllipse(400,300,100,100); 
	ofDrawEllipse(600,300,100,100);
	ofDrawTriangle(350,150,500,30,650,150);
	ofDrawEllipse(500,600,250,80);
	// nose
	ofPoint p;
	p.set (420,420);
	ofDrawRectRounded(420,420,100,100,10);
	ofSetColor(172,99,198);
	// phone
	ofNoFill();
	ofSetLineWidth(3);
	ofPoint d;
	d.set(300,10);
	ofDrawRectRounded(300,10,450,700,10);

	} else if (currentScene == 1){
			// A COOL DOG DOING A KICKFLIP
	ofSetColor(255,0,255); 
	ofFill();
	ofDrawEllipse(200, 200, 200, 200);

	} else if (currentScene == 2){
		// A PERSON WITH A COOL VAN WITH TINTED WINDOWS
	ofSetColor(0,255,255); 
	ofFill();
	ofDrawRectangle(600, 600, 200, 200);

	}
	





	// mouse makes random squares 
	float randomColor = ofRandom(50,255);
	ofSetColor(randomColor);
	ofFill();
	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
		//ofSetRectMode(OF_RECTMODE_CENTER);
		int numRects = 10;
		for (int r=0; r<numRects; r++){
			ofSetColor(ofRandom(50,255), ofRandom(50,255), ofRandom(50,255));
			float width = ofRandom(5,20);
			float height = ofRandom(5,20);
			float xOffset = ofRandom(-40,40);
			float yOffset = ofRandom(-40,40);
			ofDrawRectangle(ofGetMouseX()+xOffset, ofGetMouseY(),+yOffset, width, height);
		}
	}

	if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
		ofBackground(ofRandom(50,255), ofRandom(50,255), ofRandom(50,255));
	}



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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