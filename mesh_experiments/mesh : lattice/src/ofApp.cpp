#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	image.load("tee.JPG");
	image.resize(200,200);
	mesh.setMode(OF_PRIMITIVE_LINES);
	//mesh.enableColors();
	mesh.enableIndices();



	float intensityThreshold = 100.0;
	// if intensity of the pixel exceeds the threshold, draw a vertice
	int w = image.getWidth();
	int h = image.getHeight();
	for (int x = 0; x < w; x ++){
		for (int y = 0; y < h; y++){
			ofColor c = image.getColor(x,y);
			float intensity = c. getLightness();
			if (intensity >= intensityThreshold){
				float saturation = c.getSaturation();
				float z = ofMap(saturation, 0, 255, -100, 100);
				ofVec3f pos(x*4, y*4, z);
				mesh.addVertex(pos);
				mesh.addColor(c);


				offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));

			}
		}
	}

	float connectionDistance = 30;
	int numVerts = mesh.getNumVertices();
	for (int a = 0; a < numVerts; a++){
		ofVec3f vertA = mesh.getVertex(a);
		for(int b = a+1; b < numVerts; b++){
			ofVec3f vertB = mesh.getVertex(b);
			float distance = vertA.distance(vertB);
			if (distance <= connectionDistance){
				mesh.addIndex(a);
				mesh.addIndex(b);
			}



		}
	}



}

//--------------------------------------------------------------
void ofApp::update(){
	int numVerts = mesh.getNumVertices();
	for (int i = 0; i < numVerts; i++){
		ofVec3f vert = mesh.getVertex(i);

		float time = ofGetElapsedTimef();
		float timeScale = 5.0;
		float displacementScale = 0.75;
		ofVec3f timeOffsets = offsets[i];

    vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
    vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
    vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
    mesh.setVertex(i, vert);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	//image.draw(0,0);
	//ofBackground(0,120,225);

	ofColor centerColor = ofColor(85, 78, 68);
	ofColor edgeColor(0,60,120);
	ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

cam.begin();
ofPushMatrix();
ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
	mesh.draw();
	ofPopMatrix();
	cam.end();


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