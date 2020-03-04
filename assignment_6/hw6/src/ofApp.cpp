#include "ofApp.h"

int x;
int y;

ofVec2f outerFrame; // position
ofVec2f rectSize1;
ofVec2f rectSize2;
ofVec2f outerLeft;
ofVec2f rectSize3;
ofVec2f outerRight;
ofVec2f rectSize4;
ofVec2f middleLeft;
ofVec2f rectSize5;
ofVec2f middleLeftmiddle;
ofVec2f rectSize6;
ofVec2f topRight;
ofVec2f rectSize7;
ofVec2f bottomRight;
ofVec2f rectSize8;
ofVec2f ellipsePos;
ofVec2f ellipseSize;

ofPoint myMouse;
ofImage imgMush;

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	ofSetCircleResolution(50);

	outerFrame.set(50,50);
	rectSize1.set(920, 620);
	rectSize2.set(250,400);
	outerLeft.set(50,450);
	rectSize3.set(350,220);
	outerRight.set(870,50);
	rectSize4.set(100,100);
	middleLeft.set(300,50);
	rectSize5.set(300,250);
	middleLeftmiddle.set(300,300);
	rectSize6.set(300,150);
	topRight.set(600,50);
	rectSize7.set(270,300);
	bottomRight.set(600,350);
	rectSize8.set(370,320);

	ellipsePos.set(870,590);
	ellipseSize.set(100,100);

}

//--------------------------------------------------------------
void ofApp::update(){

	// ofImage imgMush("http//www.icons.iconarchive.com/icons/troyboydesign/smurf-houses/128/Smurf-House-Smurfette-icon.png");

 //    imgMush.loadImage("http//www.icons.iconarchive.com/icons/troyboydesign/smurf-houses/128/Smurf-House-Smurfette-icon.png");


}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(ofColor::papayaWhip);
	ofSetColor(ofColor::powderBlue);
	ofNoFill();
	ofSetLineWidth(6);



	ofDrawRectangle(outerFrame,rectSize1.x,rectSize1.y);
	ofDrawRectangle(outerFrame,rectSize2.x,rectSize2.y);
	ofDrawRectangle(outerLeft,rectSize3.x,rectSize3.y);
	ofDrawRectangle(middleLeft,rectSize5.x,rectSize5.y);
	ofDrawRectangle(outerRight,rectSize4.x,rectSize4.y);
	ofDrawRectangle(middleLeftmiddle,rectSize6.x,rectSize6.y);
	ofDrawRectangle(topRight, rectSize7.x,rectSize7.y);
	ofDrawRectangle(bottomRight,rectSize8.x,rectSize8.y);


    ofSetColor(ofColor::darkSalmon);
	ofFill();
	ofDrawEllipse(ellipsePos,ellipseSize.x,ellipseSize.y);


    ofFill()
	ofCircle(myMouse,40);  

	//ofImage imgMush(myMouse,40);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	int step = 10;  
	if(key == 'w') myMouse.y = myMouse.y - step;  
	if(key == 's') myMouse.y = myMouse.y + step;  
	if(key == 'a') myMouse.x = myMouse.x - step;  
	if(key == 'd') myMouse.x = myMouse.x + step;  
	  

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

	myMouse.x = x;  
	myMouse.y = y;

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