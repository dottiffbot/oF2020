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
ofColor pukegreen(186,255,25);

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

ofPolyline polyline;

// step value for bear movement
float step = -12;
float mouthSizeInterpolate = 0.0;
float eyeSizeInterpolate = 0.0;
float browPosInterpolate =0.0;

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
	ofSetCircleResolution(100);
	ofBackground(orange);
	ofEnableSmoothing();
	ofSetRectMode(OF_RECTMODE_CENTER);

	soundPlayer.load("sleepwalk.mp3");
	soundPlayer.play();

	cloud.load("cloud.jpeg");
	fire.load("fire.jpeg");
	honey.load("honey.png");
	music.load("musicnote.png");
	flip.load("flip.png");
	flame.load("flame.png");
	mush.load("mushhouse.jpeg");

	blocus.load("blocuswebfont.ttf", 42);
	

	// head / body

	headPos.set(500,375);
	headSize.set(250,200);

	torsoPos.set(500, 575);
	torsoSize.set(200,250);


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

	p1Mouth.set(nose.x, nose.y + 55);
    p2Mouth.set(p1Mouth.x,p1Mouth.y + 50);
    p3Mouth.set(p1Mouth.x,p1Mouth.y + 25);


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
int fakeSeconds = seconds%16;

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

mush.draw(ofGetHeight()/2, ofGetWidth()/2);

   headPos.y = 375;
   mouthSizeInterpolate = 0.0;
   eyeSizeInterpolate  = 0.0;
   float mouthSize1 = 7;

	ofPushStyle();

	drawBearbody();

	ofPopStyle();

	ofPushStyle();

	drawBearhead();

	ofPopStyle();

	SetRelativePositions();

	ofPushStyle();

    ofColor yellow = ofColor::yellow;
	ofSetColor(yellow);
	ofFill();
	ofDrawEllipse(neutralMouth.x, neutralMouth.y, mouthSize1, mouthSize1);
	
	ofPopStyle();


	ofPushStyle();

	ofFill();
	ofSetColor(cyan);
	ofFill();
	blocus.drawString("hello, this is bear...", 400, 200);

	ofPopStyle();
	ofNoFill();


}

//--------------------------------------------------------------
void ofApp:: drawScene2(){

	// reset our mouth size interpolation,
	// for the next time we play our scene

	mouthSizeInterpolate = 0.0;
	 eyeSizeInterpolate  = 0.0;

	headPos.y = 375;


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

	headPos.y = headPos.y + 1 * step;
	//cout << "headposition " << headPos.y << endl;
	if (headPos.y < 0) {
		step = 12;
	} else if (headPos.y > (y + 1)) {
		step = -12;
	}

	SetRelativePositions();
	drawBearhead();
	boomFace();

	ofPopMatrix();

	ofPopStyle();


	}

//--------------------------------------------------------------
void ofApp:: drawBearhead(){

   int eyeSize = 10;
   int earSize = 40;
   float widthBrow = 30;
   float heightBrow = 10;
   float radiusBrow = 5;

    ofSetColor(violet);
    ofFill();

	ofDrawCircle(leftEarPos, earSize);
	ofDrawCircle(rightEarPos,earSize);
	
	ofDrawEllipse(headPos,headSize.x,headSize.y);

	ofSetColor(gold);
	ofDrawEllipse(nose,noseSize.x,noseSize.y);

	ofSetColor(lavender);
	ofFill();
	ofDrawRectRounded(p1brow, widthBrow,heightBrow,radiusBrow);
    ofDrawRectRounded(p2brow,widthBrow,heightBrow,radiusBrow);

	ofSetColor(teal);
	ofDrawCircle(leftEyePos,eyeSize);
	ofDrawCircle(rightEyePos,eyeSize);
}


//--------------------------------------------------------------
void ofApp:: drawBearbody(){

	int footSize = 45;

	ofPushStyle();

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

	ofPopStyle();

	// ofPushMatrix();


 //  ofRotateX(rX);
 //  ofRotateY(rY);

	//  ofTranslate(leftArmPos.x, leftArmPos.y, 0);
	
	//  music.draw(0,0,armSize.x, armSize.y);
	//  ofPopMatrix();


	//  ofPopMatrix();

  ofPushMatrix();

  ofTranslate(rightArmPos.x, rightArmPos.y, 0);

  ofRotateX(rX);
  ofRotate(rZ);

  flip.draw(0,0,armSize.x, armSize.y);

  ofPopMatrix();

  ofPushMatrix();

  ofTranslate(rightArmPos.x, rightArmPos.y, 0);
  ofRotateX(rX);
  ofRotateY(rY);
  music.draw(0,0, armSize.x, armSize.y);

  ofPopMatrix();



}
//--------------------------------------------------------------
void ofApp:: happy (){

   float widthBrow = 45;
   float heightBrow = 20;
   float radiusBrow = 20;

   ofPushStyle();

   ofColor yellow = ofColor::yellow;
   ofSetColor(yellow);

	ofFill();
	ofSetLineWidth(6);

	polyMouth.arc(p1Mouth,50,50,0,180);
	polyMouth.draw();

	ofPopStyle();

	ofPushStyle();

	ofSetColor(lavender);

	ofFill();

ofDrawRectRounded(p1brow -5, widthBrow,heightBrow,radiusBrow);
ofDrawRectRounded(p2brow,widthBrow,heightBrow,radiusBrow);

ofPopStyle();

}

void ofApp:: boomFace(){

  mouthSizeInterpolate += 0.0044;
  mouthSizeInterpolate = mouthSizeInterpolate < 1.0 ? mouthSizeInterpolate : 1.0;
   float mouthSize = ofLerp(0.0, 60.0, mouthSizeInterpolate);

   eyeSizeInterpolate +=0.05;
   eyeSizeInterpolate = eyeSizeInterpolate < 1.0 ? eyeSizeInterpolate : 1.0;
   float eyeSize = ofLerp(0.0, 20.0, eyeSizeInterpolate);
  
   float widthBrow = 45;
   float heightBrow = 20;
   float radiusBrow = 20;

// browPosInterpolate += 0.0044;
// browPosInterpolate = heightBrow
//    float browPos = ofLerp(0.0, 5.0, browPosInterpolate);


 ofPushStyle();

 ofColor yellow = ofColor::yellow;
  ofSetColor(yellow);
   ofFill();

	// ofSetLineWidth(6);
	// polyMouth.arc(p1Mouth,-50,-50,0,-180);
	// polyMouth.draw();

	ofDrawEllipse(neutralMouth.x, neutralMouth.y, mouthSize, mouthSize);

	ofPopStyle();


	ofPushStyle();
	ofSetColor(lavender);
	ofFill();


ofDrawRectRounded(p1brow,widthBrow,heightBrow + 5,radiusBrow);
ofDrawRectRounded(p2brow,widthBrow,heightBrow + 5,radiusBrow);
	ofPopStyle();

	ofPushStyle();

    ofSetColor(teal);
	ofDrawCircle(leftEyePos,eyeSize);
	ofDrawCircle(rightEyePos,eyeSize);
   
    ofPopStyle();


ofPopStyle();
ofPushMatrix(); 

   ofRotateX(rX);

ofTranslate(leftArmPos.x, leftArmPos.y, 0);
flame.draw(0,0,armSize.x, armSize.y);

 ofPopMatrix();



 ofPushMatrix();

   ofRotateX(rX);
 ofRotateY(rY);
 ofTranslate(rightArmPos.x, rightArmPos.y, 0);
 ofScale(0.2,0.2,0.2);
 flame.draw(0,0,0);

 ofPopMatrix();

   ofNoFill();
ofPopStyle();



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