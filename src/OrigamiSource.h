#pragma once

#include "ofMain.h"
#include "FboSource.h"

class OrigamiSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        void setColor(ofColor);
        int speed;
        float sineStep;
        int startTime;
};
