#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	for (float param = 1; param < 20; param += 0.5) {

		int deg_start = ofRandom(360) + ofGetFrameNum() * ofRandom(0.5, 5);
		ofBeginShape();
		for (int deg = deg_start; deg < deg_start + 120; deg += 1) {

			ofVertex(this->make_heart_point(param, deg));
		}
		ofEndShape();
	}
}

//--------------------------------------------------------------
ofPoint ofApp::make_heart_point(float param, int deg, int z) {

	float x = param * (16 * sin(deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD));
	float y = param * (13 * cos(deg * DEG_TO_RAD) - 5 * cos(2 * deg * DEG_TO_RAD) - 2 * cos(3 * deg * DEG_TO_RAD) - cos(4 * deg * DEG_TO_RAD));
	return ofPoint(x, -y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}