#pragma once

#include "ofMain.h"
#include "FboSource.h"

class NoisePixelsSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void drawMovingRect(int, int, int, int, float);
        void setName(string _name);
        void setColor(ofColor);
        ofColor rectColor;
        float time;
        int triSize;
        float noiseScale;
        float tm;
        int startTime;
};
