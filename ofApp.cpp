#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetBackgroundColor(cs.getColor("Bk"));
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	for (int i = 0; i < 1000; i++) {
		this->particles.push_back(shared_ptr<Particle>(new Particle(ofVec3f(0, 0, 0), ofGetWidth()*0.4, cs.getColor("W"))));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();
	ofRotateY(ofGetFrameNum());
	for (int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->draw();
		for (int j = i + 1; j < this->particles.size(); j++) {
			float dist = this->particles[i]->getLocation().distance(this->particles[j]->getLocation());
			if (dist < 100) {
				float ma = ofMap(dist, 0, 99, 200, 10);
				ofSetColor(cs.getColor("W"), ma);
				ofSetLineWidth(1);
				ofDrawLine(this->particles[i]->getLocation(), this->particles[j]->getLocation());
			}
		}
	}
	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'x') {
		string now = ofGetTimestampString("%Y%m%d%H%M%S");
		this->img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		this->img.saveImage("of" + now + ".jpg");
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
