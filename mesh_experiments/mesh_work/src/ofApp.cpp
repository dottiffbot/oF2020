#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//ofSetFrameRate(60);
cam.setDistance(100);
ofSetVerticalSync(true);
ofSetSphereResolution(128);
ofEnableAlphaBlending();


 gui.setup();
 gui.add(noiseAmount.set("noise amount", 0., 0., 6.));

 for(int r = 0; r < size; r++){
 for(int c= 0; c < size; c++){

mesh.addVertex(ofPoint(r - size/2, c - size /2));

// ofVec3f pos;
// float halfWidth = ofGetWidth() * 0.5;
// float halfHeight = ofGetHeight() * 0.5;

// pos.x = ofMap(r, 0, size-1, -halfWidth, halfWidth);
// pos.y = ofMap(c, 0, size-1, halfHeight, -halfHeight);
// pos.z = 0;

// mesh.addVertex(pos);

// if (r > 0 && c > 0) {
// 	int index = r * size + c;

// 	// triangle 1
// 	mesh.addIndex(index);             // pt. 1 - this pt
// 	mesh.addIndex(index - 1);        // pt. 2  - + col
// 	mesh.addIndex(index - size);    //  pt. 3 - + row

// 	// triangle 2

// 	mesh.addIndex(index);
// 	mesh.addIndex(index - 1 - size);
// 	mesh.addIndex(index - size);


}



	}


for (int r = 0; r < size - 1; r++){
	for (int c = 0; c < size - 1; c++){

		mesh.addIndex(r + c * size); 
		mesh.addIndex((r + 1) + c * size);
		mesh.addIndex(r + (c + 1) * size);
		mesh.addIndex((r + 1) + c * size);
		mesh.addIndex((r + 1) + (c + 1) * size);
		mesh.addIndex(r + (c + 1) * size);


	//offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));



	}
  }

}

//--------------------------------------------------------------
void ofApp::update(){

	int count = 0;
	for (int r = 0; r < size; r++){
	for (int c = 0; c < size; c++){
	ofVec3f pos = mesh.getVertex(count);
	pos.z = ofMap(ofNoise(count, ofGetElapsedTimef()), 0, 1, 0, noiseAmount);
	mesh.setVertex(count, pos);
	count++;

	}

	}




	// int numVerts = mesh.getNumVertices();
	// for (int i = 0; i < numVerts; i++){
	// 	ofVec3f vert = mesh.getVertex(i);

	// 	float time = ofGetElapsedTimef();
	// 	float timeScale = 5.0;
	// 	float displacementScale = 0.75;
		
	// 	ofVec3f timeOffsets = offsets[i];

 //    vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
 //    vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
 //    vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
 //    mesh.setVertex(i, vert);
	// }

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofPushMatrix();
	gui.draw();
	cam.begin();
	ofEnableDepthTest();

// teal
	ofSetColor(30, 191, 148);
	
	mesh.drawWireframe();
	//ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
	ofSetColor(212,122,149);
	ofFill();

	ofSpherePrimitive sphere;
	sphere.setRadius(50);
	sphere.setPosition(100, 100, -50);
	sphere.draw();

	ofDisableDepthTest();

cam.end();
	ofPopMatrix();

	



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