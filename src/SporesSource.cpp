#include "SporesSource.h"

//--------------------------------------------------------------
void SporesSource::setup(){
    
    name = "Spores Source";
    allocate(1024, 768);
    
    ofPushStyle();
    
    // initial variables
    ofSetBackgroundColor(0);
    ofSetBackgroundAuto(true);
    lineWid = 1;
    lineSpeed = 0.0001;
    
    ofPopStyle();
}

//--------------------------------------------------------------
void SporesSource::reset(){
    
    ofClear(0,0,255);
    startTime = ofGetElapsedTimeMillis();
}
//--------------------------------------------------------------
void SporesSource::setName(string _name){
    name = _name;
}


//--------------------------------------------------------------
void SporesSource::update(){
    lineSpeed += 0.005;
}

//--------------------------------------------------------------
void SporesSource::draw(){
    ofClear(0); //clear the buffer
    
    ofPushStyle();
    ofNoFill();

    // spore colour, location and line width variables
    float time = ofGetElapsedTimef();
    for (int i = 0; i < 400; i++) {
        float ampX = fbo->getWidth();
        float ampY = fbo->getHeight() + 30;
        float speed = 0.1;
        float posX0 = i * 100 + 10;
        float posY0 = i * 50 + 30;
        float x = ampX * ofNoise( time * speed + posX0 / 1.9 );
        float y = ampY * ofNoise(time * speed + posY0 * 1.5);
        lineWid = ofMap(sin(lineSpeed), -1, 1, 3, 8);
        ofSetLineWidth(lineWid);
        ofColor g = ofColor(10,255,124);
        ofColor b = ofColor(10,10,255);
        ofColor r = ofColor(220, 20, 124);
        ofDrawCircle(x, y, 4);
        
        // blue lerped spores that grow and shrink over time
        if (ofGetElapsedTimeMillis() - startTime < 16 * 1000){
            ofSetColor(g.getLerped(b,i));
            
        }
        // rainbow lerped spores that grow and shrink over time
        if (ofGetElapsedTimeMillis() - startTime > 16 * 1000){
            ofSetColor(r.getLerped(b,i));
        }
        // add another set of rainbow spores with a different noise pattern
        if (ofGetElapsedTimeMillis() - startTime > 25 * 1000){
            ofSetColor(r.getLerped(b,i));
            float x = ampX * ofNoise((time * speed * 2.5) + posX0);
            float y = ampY * ofNoise((time * speed * 2.5) + posY0);
            ofDrawCircle(x, y, 4);
        }
    }
    
    // draw boundary triangle
    ofSetLineWidth(6);
    ofSetColor(42,245, 103, 250);
    ofDrawTriangle(200, 650, 800, 650, 500, 100);

    ofPopStyle();
}


