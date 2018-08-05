#pragma once

#include "ofMain.h"
#include "FboSource.h"

class TerrariumSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        void setColor(ofColor);
        void triangle(float r, float p);
        float phase;
        int startTime;
};
