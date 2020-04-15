#include "ofApp.h"


//colors 

ofColor violet(184,141,199);
ofColor gold(199,170,76);
ofColor teal(62,199,185);
ofColor rose(251,212,255);
ofColor darkPurple(127,64,255);
ofColor blue(111,130,227);
ofColor lime(186,255,25);
ofColor cyan(28,187,255);
ofColor lavender(133,103,131);

ofVec2f headPos, headSize;
ofVec2f nose, noseSize;
ofVec2f leftEyePos, rightEyePos;
ofVec2f leftEarPos, rightEarPos;
ofVec2f torsoPos, torsoSize;
ofVec2f bellyPos, bellySize;
ofVec2f leftArmPos, rightArmPos, armSize;
ofVec2f leftFootPos, rightFootPos;

ofVec2f neutralMouth;

ofVec2f p1brow, p2brow;

ofPolyline polyMouth;
ofPoint p1Mouth, p2Mouth, p3Mouth;

// int slideNumber = 0;
// float currentTime = 0;

ofPolyline polyline;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
	ofSetCircleResolution(100);
	ofBackground(186,255,25);
	ofEnableSmoothing();
	ofSetRectMode(OF_RECTMODE_CENTER);

	soundPlayer.load("picture.mp3");
	soundPlayer.play();

	image.load("mushhouse_2.jpeg");
	blocus.load("blocuswebfont.ttf", 42);

	// head / body / face

	headPos.set(500,375);
	headSize.set(250,200);

	nose.set(headPos.x, headPos.y + 15);
	noseSize.set(100,50);

	leftEyePos.set(headPos.x - 50, headPos.y - 35);
	rightEyePos.set(headPos.x + 43, headPos.y - 35);

	leftEarPos.set(headPos.x - 70, headPos.y - 98);
	rightEarPos.set(leftEarPos.x + 145, leftEarPos.y);

	torsoPos.set(headPos.x, headPos.y + 200);
	torsoSize.set(200,250);

	bellyPos.set(torsoPos.x,torsoPos.y);
	bellySize.set(torsoSize.x -100, torsoSize.y - 100);

	leftArmPos.set(torsoPos.x - 110, torsoPos.y - 45);
	rightArmPos.set(torsoPos.x + 110, torsoPos.y - 45);

	armSize.set(60,100);

	leftFootPos.set(torsoPos.x - 80, torsoPos.y + 75);
	rightFootPos.set(torsoPos.x + 70, torsoPos.y + 75);


	neutralMouth.set(nose.x + 10, nose.y + 55);

	//happy

	p1Mouth.set(nose.x, nose.y + 55);
    p2Mouth.set(510,455);
    p3Mouth.set(510,430);


	// brows will happen possibly

	p1brow.set(435,317);
	p2brow.set(556, 317);


	gui.setup();
	gui.add(soundVolume.setup("volume", 0.2f, 0.0f,1.0f));

}

//--------------------------------------------------------------
void ofApp::update(){
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::draw(){

	image.draw(ofGetWidth()/2, ofGetHeight()/2);
	ofSoundSetVolume(soundVolume);
	gui.draw();
	drawBearhead();
	drawBearbody();

	headPos.y--;
	leftEarPos.y--;
	rightEarPos.y--;
	leftEyePos.y--;
	rightEyePos.y--;
	nose.y--;
	neutralMouth.y--;
	p1brow.y--;
	p2brow.y--;



	//if(headPos.y > ofGetHeight(), headPos.y++);


	ofSetColor(cyan);
	ofFill();
	blocus.drawString("this is bear", 410, 200);

}
//--------------------------------------------------------------
void ofApp:: drawBearhead(){

   int eyeSize = 10;
   int earSize = 40;
   int mouthSize = 7;

    ofSetColor(violet);
    ofFill();

	ofDrawCircle(leftEarPos, earSize);
	ofDrawCircle(rightEarPos,earSize);
	
	ofDrawEllipse(headPos,headSize.x,headSize.y);

	ofSetColor(gold);
	ofDrawEllipse(nose,noseSize.x,noseSize.y);

	ofSetColor(lavender);
	ofFill();
	ofDrawRectRounded(p1brow,30,10,5);
    ofDrawRectRounded(p2brow,30,10,5);

	ofSetColor(teal);
	ofDrawCircle(leftEyePos,eyeSize);
	ofDrawCircle(rightEyePos,eyeSize);

	ofSetColor(blue);
	ofDrawCircle(neutralMouth,mouthSize);


   

}

//--------------------------------------------------------------
void ofApp:: drawBearbody(){

	int footSize = 45;

	ofSetColor(violet);
	ofFill();
	ofDrawEllipse(torsoPos, torsoSize.x, torsoSize.y);

	ofSetColor(rose);
	ofFill();
	ofDrawEllipse(bellyPos, bellySize.x, bellySize.y);

	ofSetColor(darkPurple);
	ofFill();
	ofDrawEllipse(leftArmPos, armSize.x, armSize.y);
	ofDrawEllipse(rightArmPos, armSize.x, armSize.y);

	ofDrawCircle(leftFootPos,footSize);
	ofDrawCircle(rightFootPos,footSize);


}
//--------------------------------------------------------------
void ofApp:: happy (){

	ofColor yellow = ofColor::yellow;
	ofSetColor(yellow);

	ofFill();
	ofSetLineWidth(6);

	polyMouth.arc(p1Mouth,50,50,0,180);
	polyMouth.draw();

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