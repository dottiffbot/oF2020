#include "ofApp.h"



// all the the moving parts of the face in vectors

// eyes 
// sad

glm::vec2 sad_eye_postion_left;
glm::vec2 sad_eye_position_right;
glm::vec2 sad_eyes_size;

// happy

ofVec2f happyEye_positionLeft;
ofVec2f happyEye_positionRight;
ofVec2f happyEye_size;

// suprised 
ofVec2f suprisedEye_positionLeft;
ofVec2f suprisedEye_positionRight;
ofVec2f suprisedEye_size;

// angry

ofVec2f angryEye_positionLeft;
ofVec2f angryEye_positionRight;
ofVec2f angryEye_size;


// mouth
//sad 

glm::vec2 sadMouth_position;
glm::vec2 sadMouth_size;


// happy 
ofVec2f happyMouth_postion;
ofVec2f happyMouth_size;

// suprised
ofVec2f suprisedMouth_postion;
ofVec2f suprisedMouth_size;


// angry
ofVec2f angryMouth_postion;
ofVec2f angryMouth_size;

// brows

//sad

glm::vec2 sad_brows_position_left;
glm::vec2 sad_brows_position_right;
glm::vec2 sad_brows_size;

// happy

ofVec2f happyBrows_positionLeft;
ofVec2f happyBrows_positionRight;
ofVec2f happyBrows_size;

// suprised 

ofVec2f suprisedBrows_positionLeft;
ofVec2f suprisedBrows_positionRight;
ofVec2f suprisedBrows_size;

// angry
ofVec2f angryBrows_postionLeft;
ofVec2f angryBrows_postionRight;
ofVec2f angryBrows_size;


// movement for all the vectors

glm::vec2 sad_eye_left_start;
glm::vec2 sad_eye_left_current;
glm::vec2 sad_eye_left_end;

ofVec2f happyEye_positionLeft_start;
ofVec2f happyEye_positionLeft_current;
ofVec2f happyEye_positionLeft_end;

float counter;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(50);
	ofSetLineResoulution(50);
	ofSetBackgroundAuto(false);
	ofSetFrameRate(60);
	ofBackground(186,255,25);
	// ofEnableAntialiasing();
	// ofBackground(0);
	ofEnableAlphaBlending();
	// ofDisableAlphaBlending();

	// values to position and size variables

	sad_eye_postion_left = glm::vec2(453,340);
	sad_eye_position_right = glm::vec2(568,340);
	sad_eyes_size = glm::vec2(40,40);

	sad_eye_left_start = glm::vec2(0);
	sad_eye_left_current = glm::vec2(0);
	sad_eye_left_end = glm::vec2(453,340);

	happyEye_positionLeft.set(453,340);
	happyEye_positionRight.set(568,340);
	happyEye_size = (30,15);

	suprisedEye_positionLeft = (453,340);
	suprisedEye_positionRight = (568,340);
	suprisedEye_size = (20,40);

	angryEye_positionLeft = (453,340);
	angryEye_positionRight = (568,340);
	angryEye_size = (15,10);




counter = 0.0;


}

//--------------------------------------------------------------
void ofApp::update(){

	

	sad_eye_left_current.x = ofLerp(sad_eye_left_start.x,sad_eye_left_end.x, percent);
	sad_eye_left_current.y = ofLerp(sad_eye_left_start.y,sad_eye_left_end.y, percent);



} 



//--------------------------------------------------------------
void ofApp::draw(){


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

// eyes

	// left eye, right eye

	ofColor medBlu = ofColor::mediumBlue;
	ofSetColor(medBlu);

	ofFill();

	// happy eyes 
	// ofDrawEllipse(453,340,30,15);
	// ofDrawEllipse(568,340,30,15);


	// sad eyes
	ofDrawEllipse(sad_eye_left_current,sad_eyes_size.x,sad_eyes_size.y);
	ofDrawEllipse(sad_eye_position_right,sad_eyes_size.x,sad_eyes_size.y);

	// suprised eyes
	// ofDrawEllipse(453,340,20,40);
	// ofDrawEllipse(568,340,20,40);


    //angry eyes
	// ofDrawEllipse(453,340,15,10);
	// ofDrawEllipse(568,340,15,10);

	// // mouth // //

	ofColor yellow = ofColor::yellow;
	ofSetColor(yellow);

	ofFill();
	ofSetLineWidth(6);

	// happy mouth //

	// ofPolyline polyline1;
	// ofPoint p3(510,405);
	// polyline1.arc(p3,50,50,0,180);
	// polyline1.draw();

	// sad mouth //

	 ofPolyline polyline1;
	 ofPoint p4(510,455);
	 polyline1.arc(p4,-50,-50,0,-180);
	 polyline1.draw();


	// suprised mouth //

	//ofDrawCircle(510,430,30);

	// angry mouth //

	// ofDrawLine(455,420,565,420);




	// eybrow left //

	ofColor lavender(133,103,131);
	ofSetColor(lavender);
	ofFill();
	ofPoint p1;

	// eyebrow right // 

	ofSetColor(lavender);
	ofFill();
	ofPoint p2;

	// happy //

	// p1.set (435,317);
	// ofDrawRectRounded(p1,30,10,5);

	// p2.set (556, 317);
	// ofDrawRectRounded(p2,30,10,5);

    // sad //


	p1.set (430,317);
	ofDrawRectRounded(p1,45,20,20);

	p2.set (545, 317);
	ofDrawRectRounded(p2,45,20,20);



	// suprised eyebrows //

	// p1.set (435,300);
	// ofDrawRectRounded(p1,30,10,5);

	// p2.set(556,300);
	// ofDrawRectRounded(p2,30,10,5);

	// angry brows //

	// p1.set (435,320);
	// ofDrawRectRounded(p1,30,10,5);
	// p2.set(556,320);
	// ofDrawRectRounded(p2,30,10,5);

	// ofDrawLine(440,320,465,330);
	// ofDrawLine(550,330,575,320);










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
	// 	ofDrawCircle(ofGetMouseX()+xOffset, ofGetMouseY()+yOffset, radius);

	



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