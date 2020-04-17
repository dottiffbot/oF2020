#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();


		void SetRelativePositions();
		void drawBearhead();
		void drawBearbody();
		void happy();
		void boomFace();
		void drawScene1();
		void drawScene2();
		void drawScene3();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofSoundPlayer soundPlayer;
		ofxFloatSlider soundVolume;
		ofTrueTypeFont blocus;
		ofImage cloud;
		ofImage fire;
		ofImage honey;
		ofImage music;
		ofImage flip;
		ofImage flame;
		ofImage mush;

		ofxPanel gui;
};
