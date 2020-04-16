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
ofColor orange(255,94,0);
ofColor redish(255, 90, 60);

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

int slideNumber = 0;
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

	cloud.load("cloud.jpeg");
	fire.load("fire.jpeg");
	honey.load("honey.png");
	blocus.load("blocuswebfont.ttf", 42);

	// head / body

	headPos.set(500,375);
	headSize.set(250,200);


	torsoPos.set(500, 575);
	torsoSize.set(200,250);


	// brows will happen possibly


	gui.setup();
	gui.add(soundVolume.setup("volume", 0.2f, 0.0f,1.0f));

}

float rX = 0;
float rY = 0;
float rZ = 0;

//--------------------------------------------------------------
void ofApp::SetRelativePositions(){

	nose.set(headPos.x, headPos.y + 15);
	noseSize.set(100,50);

	leftEyePos.set(headPos.x - 50, headPos.y - 35);
	rightEyePos.set(headPos.x + 43, headPos.y - 35);

	leftEarPos.set(headPos.x - 70, headPos.y - 98);
	rightEarPos.set(leftEarPos.x + 145, leftEarPos.y);

	neutralMouth.set(nose.x + 10, nose.y + 55);

	bellyPos.set(torsoPos.x,torsoPos.y);
	bellySize.set(torsoSize.x -100, torsoSize.y - 100);

	leftArmPos.set(torsoPos.x - 110, torsoPos.y - 45);
	rightArmPos.set(torsoPos.x + 110, torsoPos.y - 45);

	armSize.set(60,100);

	leftFootPos.set(torsoPos.x - 80, torsoPos.y + 75);
	rightFootPos.set(torsoPos.x + 70, torsoPos.y + 75);

	p1brow.set(headPos.x - 65 , headPos.y - 58);
	p2brow.set(headPos.x + 56, headPos.y - 58);

	//happy

	p1Mouth.set(nose.x, nose.y + 55);
    p2Mouth.set(510,455);
    p3Mouth.set(510,430);


 }
//--------------------------------------------------------------
void ofApp::update(){

	ofEnableAlphaBlending();

		  rX++;
  if (ofGetFrameNum() % 3 == 0)
    rY++;
  if (ofGetFrameNum() % 7 == 0)
    rZ++;



}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSoundSetVolume(soundVolume);

int seconds = ofGetFrameNum()/60;
int fakeSeconds = seconds%7;

if(fakeSeconds < 4){
	slideNumber = 0;
} else if (fakeSeconds < 6){
	slideNumber = 1;
}
else if (fakeSeconds < 16){
	slideNumber = 2;
}



	if(slideNumber == 0){
		drawScene1();
	} if (slideNumber == 1){
		drawScene2();
	} if (slideNumber == 2){
		drawScene3();
	} else {
		slideNumber++;
	}

	
	gui.draw();

}

//--------------------------------------------------------------
void ofApp:: drawScene1(){

   int mouthSize = 7;
   float mouthYValue = ofLerp(7, 35, 0.5);

	ofPushStyle();
	drawBearbody();
	ofPopStyle();

	ofPushStyle();
	drawBearhead();
	ofPopStyle();

	SetRelativePositions();

	ofPushStyle();
	ofSetColor(blue);
	ofFill();
	// lerp mouth from neutral to, uh wider? 
	ofDrawEllipse(neutralMouth.x, neutralMouth.y, mouthSize, mouthYValue);
	ofPopStyle();

	ofPushStyle();
	ofFill();
	ofSetColor(cyan);
	ofFill();
	
	blocus.drawString("hello, this is bear", 400, 200);
	ofPopStyle();
	ofNoFill();


}

//--------------------------------------------------------------
void ofApp:: drawScene2(){

    cloud.draw(ofGetWidth()/2, ofGetHeight()/2);


    ofPushStyle();
	drawBearbody();
	ofPopStyle();

	ofPushStyle();
	drawBearhead();
	ofPopStyle();

	ofPushStyle();
	happy();
	ofPopStyle();

ofPushMatrix();

  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  ofScale(0.3, 0.3, 0.3);  
  ofRotateX(rX);
  ofRotateY(rY);
  ofRotateZ(rZ);
  honey.draw(0 - honey.getWidth()/2, 0 - honey.getHeight()/2);

  ofPopMatrix();
 

	
	ofPushStyle();
	ofSetColor(ofColor(redish));
	ofFill();
    blocus.drawString("give bear honey!", 400, 200);
    ofPopStyle();

}
//--------------------------------------------------------------
void ofApp:: drawScene3(){

 float step = -5;
 int y = 376;


	fire.draw(ofGetWidth()/2, ofGetHeight()/2);
    ofPushStyle();
	ofSetColor(ofColor(orange));
	ofFill();
	blocus.drawString("bear go boom, bye!", 390, 200);
	ofPopStyle();


    ofPushStyle();
	drawBearbody();
	ofPopStyle();

	ofPushStyle();

ofPushMatrix();

   //  if(headPos.y > ofGetHeight()){
   // 	headPos.y += step * 0 + 1;
   // } else if (headPos.y < ofGetHeight()){
   // 	headPos.y -= step;

headPos.y = headPos.y + 1 * step;

cout << "headposition " << headPos.y << endl;
 if (headPos.y < 0) {
   step = 5;
}
	


	SetRelativePositions();
	drawBearhead();

	ofPopMatrix();

	ofPopStyle();


	}

//--------------------------------------------------------------
void ofApp:: drawBearhead(){

   int eyeSize = 10;
   int earSize = 40;

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





	// to transition from one thing to another
	// neutral mouth
	// ofDrawEllipse(100, 100, 40, 50);
	// excited mouth
	// ofDrawEllipse(100, 100, 40, 250);

	// float mouthYValue = ofLerp(50, 250, 0.5);
	// ofDrawEllipse(neutralMouth.x, neutralMouth.y, mouthSize, mouthYValue);
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

	// ofPushMatrix();
	//  ofTranslate(leftArmPos.x, leftArmPos.y, 0);
	//  ofRotateZ(22.49);
	//  ofDrawEllipse(0,0,armSize.x, armSize.y);
	//  ofPopMatrix();

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