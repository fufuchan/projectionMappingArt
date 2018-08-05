#include "TerrariumSource.h"

//--------------------------------------------------------------
void TerrariumSource::setup(){
    
    name = "Terrarium Source";
    allocate(1024, 768);
    
    ofBackground(0);
    phase = 0;
}
//--------------------------------------------------------------
void TerrariumSource::reset(){
    
    ofClear(0,0,255);
    startTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void TerrariumSource::setName(string _name){
    name = _name;
}


//--------------------------------------------------------------
void TerrariumSource::update(){
    
    phase+= 3;}


//--------------------------------------------------------------
void TerrariumSource::draw(){
    
    ofClear(0); //clear the buffer

    ofPushMatrix();
    ofPushStyle();
    
    // triangle variables
    int numOfTriangles = 20;
    int triangleSpacing = 20;
    float lineWid = 2;
    float cycles = ofMap(ofRandom(10), 0, fbo->getWidth(), 180, 1000);
    float phaseSpacing = cycles / numOfTriangles;
    
    // draw boundary triangle
    ofNoFill();
    ofSetLineWidth(lineWid);
    ofSetColor(42,245, 103);
    ofDrawTriangle(200, 650, 800, 650, 500, 100);
    
    // draw inner triangles
    for (int i = numOfTriangles; i > 0; i--){
        triangle(i * triangleSpacing, phase + phaseSpacing * i);
    }
    ofPopStyle();
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void TerrariumSource::triangle(float r, float p){
    
    // triangle technical help from https://stackoverflow.com/questions/11449856/draw-a-equilateral-triangle-given-the-center
    
    // draw and add triangles over time, lerp colour over time
    float radDiff = ofMap(sin(ofDegToRad(p)), -1, 1, 1, 20);
    
    if (ofGetElapsedTimeMillis() - startTime < 5000){
        ofDrawTriangle(500, 100, 664, 400, r * radDiff / 13.5 + 200, 650);
    }
    
    if (ofGetElapsedTimeMillis() - startTime > 5000){
        ofDrawTriangle(500, 100, 664, 400, r * radDiff / 13.5 + 200, 650);
        ofDrawTriangle(800, 650, r * radDiff / 20 + 280, 500, 500, 100);
    }
    
    if (ofGetElapsedTimeMillis() - startTime > 10 * 1000){
        ofDrawTriangle(200, 650, 800, 650, 554, r * radDiff / 18 + 200);
    }
    
    if (ofGetElapsedTimeMillis() - startTime > 15 * 1000){
        ofDrawTriangle(200, 650, 500, 650, r * radDiff / 25 + 335, 400);
    }
    
    if (ofGetElapsedTimeMillis() - startTime > 20 * 1000){
        ofDrawTriangle(500, 650, 750, 650, r * radDiff / 37 + 390, 300);
    }
    
    if (ofGetElapsedTimeMillis() - startTime > 30 * 1000){
        ofColor g = ofColor(97, 252, 0);
        ofColor b = ofColor(50, 10, 255);
        ofSetColor(g.getLerped(b, p));
    }
    
    if (ofGetElapsedTimeMillis() - startTime > 33 * 1000){
        ofColor pu = ofColor(122, 0, 252);
        ofColor y = ofColor(244, 252, 0);
        ofSetColor(pu.getLerped(y, p));
    }
    
    if (ofGetElapsedTimeMillis() - startTime > 38 * 1000){
        ofColor o = ofColor(222, 147, 0);
        ofColor r = ofColor(252, 0, 177);
        ofSetColor(o.getLerped(r, p));
    }
    
    if (ofGetElapsedTimeMillis() - startTime > 42 * 1000){
        ofColor gg = ofColor(5, 252, 42);
        ofColor bb = ofColor(6, 126, 26);
        ofSetColor(gg.getLerped(bb, p));
    }
    if (ofGetElapsedTimeMillis() - startTime > 61.5 * 1000){
        ofSetColor(42,245, 103);
    }

}
