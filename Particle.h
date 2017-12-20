#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle(ofVec3f center, float r, ofColor color);
	~Particle() {};
	void update();
	void draw();
	void setTarget();
	ofVec3f getLocation();
private:
	ofVec3f location;
	ofVec3f target;
	ofVec3f mycenter;
	float myradius;
	float myweight;
	ofColor mycolor;
	int myalp;
	float phi;
	float unitz;
	int linealp;
};