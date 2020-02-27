#include "ofApp.h"

//eyes
// neutral 

// happy

ofVec2f happyEye_positionLeft;
ofVec2f happyEye_positionRight;
ofVec2f happyEye_size;

// sad
ofVec2f sadEye_positionLeft;
ofVec2f sadEye_PositionRight;
ofVec2f sadEye_size;

// suprised 
ofVec2f suprisedEye_positionLeft;
ofVec2f suprisedEye_positionRight;
ofVec2f suprisedEye_size;

// angry

ofVec2f angryEye_positionLeft;
ofVec2f angryEye_positionRight;
ofVec2f angryEye_size;

// eyebrows //

// happy

ofPoint p1Happy;
ofPoint p2Happy;

// sad 
ofPoint p1Sad;
ofPoint p2Sad;

// suprised
ofPoint p1Suprised;
ofPoint p2Suprised;

// angry

ofPoint p1Angry;
ofPoint p2Angry;


// mouth //

ofPolyline polyMouth;
ofPoint p1Mouth;
ofPoint p2Mouth;
ofPoint p3Mouth;


// sound
//ofSoundPlayer mySound;



//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(50);
	ofSetBackgroundAuto(false);
	ofSetFrameRate(60);
	// ofBackground(186,255,25);
	ofEnableAlphaBlending();

	// 

	happyEye_positionLeft.set(453,340);
	happyEye_positionRight.set(568,340);
	happyEye_size.set(30,15);

	suprisedEye_positionLeft.set(453,340);
	suprisedEye_positionRight.set(568,340);
	suprisedEye_size.set(20,40);

	angryEye_positionLeft.set(453,340);
	angryEye_positionRight.set(568,340);
	angryEye_size.set(15,10);

	sadEye_positionLeft.set(453,340);
	sadEye_PositionRight.set(568,340);
	sadEye_size.set(15,10);

	p1Happy.set(435,317);
	p2Happy.set(556, 317);

	p1Sad.set(430,317);
	p2Sad.set(545,317);

	p1Suprised.set(435,300);
	p2Suprised.set(556,300);

	p1Angry.set(435,320);
	p2Angry.set(556,320);

    p1Mouth.set(510,405);
    p2Mouth.set(510,455);
    p3Mouth.set(510,430);
  

}

//--------------------------------------------------------------
void ofApp::update(){

	// if ((ofGetFrameNum () % 120) == 0){

	// 	if(!mySound.isPlaying()){
	// 		mySound.play();
	// 	}

	// }

	ofGetFrameNum()% 120 == 0;

		if (currentScene > 2){
			currentScene = 0;
		} else {
			currentScene++;
			currentTime = ofGetFrameNum();
		}


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(186,255,25);


		// head

 	ofVec2f v1;
 	v1.set(ofGetWidth()/2,ofGetHeight()/2);

	ofColor  myAqua = ofColor::aqua;
	ofSetColor(myAqua);

	ofFill();
	ofDrawEllipse(v1, 200, 250);


// bobo nose

	ofColor lilac(225,174,253);
	ofSetColor(lilac);

	ofFill();
	ofDrawCircle(v1,25);
	
// draw happy

if (currentScene == 0) {
// eyes 
	ofColor medBlu = ofColor::mediumBlue;
	ofSetColor(medBlu);

	ofFill();

ofDrawEllipse(happyEye_positionLeft, happyEye_size.x,happyEye_size.y);
ofDrawEllipse(happyEye_positionRight, happyEye_size.x, happyEye_size.y);

// mouth 

   ofColor yellow = ofColor::yellow;
	ofSetColor(yellow);

	ofFill();
	ofSetLineWidth(6);

	polyMouth.arc(p1Mouth,50,50,0,180);
	polyMouth.draw();


// eyebrow
	ofColor lavender(133,103,131);
	ofSetColor(lavender);
	ofFill();
	
  ofDrawRectRounded(p1Happy,30,10,5);
  ofDrawRectRounded(p2Happy,30,10,5);

} else if (currentScene == 1){

	// draw sad

// eye

	ofDrawEllipse(sadEye_positionLeft, sadEye_size.x, sadEye_size.y);
	ofDrawEllipse(sadEye_PositionRight, sadEye_size.x, sadEye_size.y);

// mouth
    ofColor yellow = ofColor::yellow;
	ofSetColor(yellow);

	ofFill();
	ofSetLineWidth(6);

	polyMouth.arc(p2Mouth,-50,-50,0,-180);
	polyMouth.draw();


// eyebrow
	ofColor lavender(133,103,131);
	ofSetColor(lavender);
	ofFill();

	ofDrawRectRounded(p1Sad(45,20,20);
	ofDrawRectRounded(p2Sad(45,20,20);


} else if (currentScene == 2){

	// draw suprised

	// eye
	ofDrawEllipse(suprisedEye_positionLeft, suprisedEye_size.x, suprisedEye_size.y);
	ofDrawEllipse(suprisedEye_positionRight, suprisedEye_size.x, suprisedEye_size.y);

	// mouth
	ofColor yellow = ofColor::yellow;
	ofSetColor(yellow);

	ofFill();
	ofSetLineWidth(6);

	polyMouth.arc(p3Mouth, 50,50,0,360);
	polyMouth.draw();

	// brow
	ofColor lavender(133,103,131);
	ofSetColor(lavender);
	ofFill();

	ofDrawRectRounded(p1Suprised(30,10,5);
	ofDrawRectRounded(p2Suprised(30,10,5);
}







  //a salmon air brush !!


	// int maxRadius = 50;
	// int radiusStepSize = 5;
	// int alpha = 6; // increase to make more opaque
	// int maxOffsetDistance = 100;
	// for (int radius=maxRadius; radius > 0; radius -= radiusStepSize){
	// 	float angle = ofRandom(ofDegToRad(360.0));
	// 	float distance = ofRandom(maxOffsetDistance);
	// 	float xOffset = cos(angle) * distance;
	// 	float yOffset = sin(angle) * distance;
	// 	ofColor mySam = ofColor::salmon;
	// 	ofSetColor(mySam, alpha);
	// 	ofDrawCircle(ofGetMouseX()+xOffset, ofGetMouseY()+yOffset, radius);}
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
