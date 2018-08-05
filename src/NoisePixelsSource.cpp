#include "NoisePixelsSource.h"

//--------------------------------------------------------------
void NoisePixelsSource::setup(){
	// Give our source a decent name
    name = "Noise Pixels Source";
    rectColor = ofColor(255);
	// Allocate our FBO source, decide how big it should be
    allocate(1024, 768);
    
    triSize = 3;
    noiseScale = 0.05;
    ofSetBackgroundColor(0);
    tm = 0.1;
}

//--------------------------------------------------------------
void NoisePixelsSource::reset(){
    //reset is called optionally. if you leave it empty nothing is happening
    ofClear(0,0,255);
    rectColor = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    startTime = ofGetElapsedTimeMillis();
    
    triSize = 3;
    noiseScale = 0.05;
    ofSetBackgroundColor(0);
    tm = 0.1;
}
//--------------------------------------------------------------
void NoisePixelsSource::setName(string _name){
    name = _name;
}
//--------------------------------------------------------------
void NoisePixelsSource::setColor(ofColor c){
    rectColor = c;
}


//--------------------------------------------------------------
void NoisePixelsSource::update(){
       tm++;
}

//--------------------------------------------------------------
void NoisePixelsSource::draw(){
    ofClear(0); //clear the buffer
    
    ofPushStyle();
    
    for (int x = 0; x < fbo->getWidth() / triSize ; x++)
    {
        for (int y = 0; y < fbo->getWidth() / triSize; y++)
        {
            float noiseValue = ofNoise(x * noiseScale, y * noiseScale, float(tm) * noiseScale);
            ofColor g = ofColor(10, 255, 100);
            ofColor b = ofColor(10, 10, 255);
            ofSetColor(b.getLerped(g, noiseValue));
            float size = ofMap(sin(noiseValue), -1, 1, 10, 50);
            ofDrawCircle(x * triSize, y * triSize, (size / tm) * 2.5);
        }
    }
    
    ofSetColor(10, 255, 100);
    ofNoFill();
    ofSetLineWidth(10);
    ofDrawTriangle(200, 650, 800, 650, 500, 100);
    
    ofPopStyle();
}

