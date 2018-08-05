#include "OrigamiSource.h"

//--------------------------------------------------------------
void OrigamiSource::setup(){
    
    ofPushStyle();
    
    name = "Origami Source";
    
    // global variables
    allocate(1024, 768);
    ofSetBackgroundColor(0);
    speed = 10000;
    sineStep = 0;
    
    ofPopStyle();
}

//--------------------------------------------------------------
void OrigamiSource::reset(){
    
    ofClear(0,0,255);
    startTime = ofGetElapsedTimeMillis();
}
//--------------------------------------------------------------
void OrigamiSource::setName(string _name){
    name = _name;
}

//--------------------------------------------------------------
void OrigamiSource::update(){
    sineStep += 0.1;}


//--------------------------------------------------------------
void OrigamiSource::draw(){
    ofClear(0); //clear the buffer
    
    ofPushMatrix();
    ofPushStyle();
    
    ofTranslate(fbo->getWidth()/2, fbo->getHeight()/4);
    speed = ofMap(sin(sineStep),-1, 1, 5000, 10000);
    
    // draw many origami triangles based on random variables
    for (int i = 0; i < speed * 2; i++) {
        
        // random variables
        float rAng = round(ofRandom(-3, 6)) * PI * 0.45;
        float rLen = ofRandom(32);
        float rStrk = ofRandom(2.5);
        float rScl = ofRandom(0.5, 10);
        
        // draw origami vertex
        if (rStrk < 1) {
            rStrk = 0.1;
        }
        
            // draw green origami triangles
        if (ofGetElapsedTimeMillis() - startTime < 20 * 1000){
            ofSetColor(0, 200, 0);
            ofSetLineWidth(rStrk);
            ofRotate(rAng);
            ofBeginShape();
            ofVertex(rLen, rStrk);
            ofVertex(rLen, 0);
            ofVertex(0, rLen);
            ofVertex(0, 0);
            ofVertex(rStrk, rScl);
            ofVertex(0, rStrk);
            ofVertex(rLen, 0);
            ofEndShape();
        if (rAng < 2.1) {
            ofColor g = ofColor(10, 180, 100);
            ofColor b = ofColor(10, 80, 255);
            ofSetColor(g.getLerped(b, rAng));
            ofSetLineWidth(5);
            ofDrawBezier(rStrk, rScl, 0, 0, rLen, rLen, rScl, rStrk);
            ofTranslate(rLen, rScl);
            }
        }
            // draw rainbow origami triangles
        if (ofGetElapsedTimeMillis() - startTime > 20 * 1000){
            ofColor g = ofColor(10, 255, 100);
            ofColor b = ofColor(0, 0, 255);
            ofSetColor(g.getLerped(b, rAng));
            ofSetLineWidth(rStrk);
            ofRotate(rAng);
            ofBeginShape();
            ofVertex(rLen, rStrk);
            ofVertex(rLen, 0);
            ofVertex(0, rLen);
            ofVertex(0, 0);
            ofVertex(rStrk, rScl);
            ofVertex(0, rStrk);
            ofVertex(rLen, 0);
            ofEndShape();
            
            // fill and add bezier lines (like little triangles inside the origami)
        if (rAng < 2.1) {
            ofColor g = ofColor(10, 180, 100);
            ofColor b = ofColor(10, 80, 255);
            ofSetColor(g.getLerped(b, rAng));
            ofSetLineWidth(5);
            ofDrawBezier(rStrk, rScl, 0, 0, rLen, rLen, rScl, rStrk);
            ofTranslate(rLen, rScl);

            // take away fill of rainbow origami triangles
        if (ofGetElapsedTimeMillis() - startTime > 35 * 1000){
                ofSetLineWidth(20 * rStrk);
                ofNoFill();
                }
            }
        }
    }

    ofPopStyle();
    ofPopMatrix();
}


