#include "Particle.h"

Particle::Particle(ofVec3f center, float r, ofColor color) {
	this->mycenter = center;
	this->myradius = r;
	this->mycolor = color;
	this->myalp = ofRandom(10, 200);
	this->myweight = ofRandom(1, 3);
	this->phi = ofRandom(TWO_PI) * 0.9;
	this->unitz = ofRandom(-1.0, 1.0) * 0.9;
	float x = this->mycenter.x + this->myradius * sqrt(1 - this->unitz * this->unitz) * cos(this->phi);
	float y = this->mycenter.y + this->myradius * sqrt(1 - this->unitz * this->unitz) * sin(this->phi);
	float z = this->mycenter.z + this->myradius * this->unitz;
	this->location = ofVec3f(x, y, z);
	this->setTarget();
}
void Particle::update() {
	if (ofGetFrameNum() % 120 == 0) {
		this->setTarget();
	}
	this->location.x += (this->target.x - this->location.x) * 0.5;
	this->location.y += (this->target.y - this->location.y) * 0.5;
	this->location.z += (this->target.z - this->location.z) * 0.5;
}
void Particle::draw() {
	ofSetColor(this->mycolor, this->myalp);
	ofPushMatrix();
	ofTranslate(this->location);
	ofDrawSphere(this->myweight);
	ofPopMatrix();
}
void Particle::setTarget() {
	this->phi = ofRandom(TWO_PI) * 0.7;
	this->unitz = ofRandom(-1.0, 1.0) * 0.9;
	float x = this->mycenter.x + this->myradius * sqrt(1 - this->unitz * this->unitz) * cos(this->phi);
	float y = this->mycenter.y + this->myradius * sqrt(1 - this->unitz * this->unitz) * sin(this->phi);
	float z = this->mycenter.z + this->myradius * this->unitz;
	this->target = ofVec3f(x, y, z);
}
ofVec3f Particle::getLocation() {
	return this->location;
}