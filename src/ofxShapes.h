#pragma once

#include "ofMain.h"

class ofxShapes {
 public:
  virtual bool draw(ofFbo fbo) {
  };
};


class ofxPoint : public ofxShapes {
 protected:
  static const float MAX_WEIGHT = 7;
  static const float DELTA_WEIGHT = 0.2;
  float x, y, currentWeight;
  ofColor color;
  
 public:
  ofxPoint(ofFbo fbo, ofxColorPalette palette) {
    x = ofRandom(0, fbo.getWidth());
    y = ofRandom(o, fbo.getHeight());
    color = palette.nextColor();
    currentWeight = 0;
  }

  virtual bool draw(ofFbo fbo) {
    currentWeight += DELTA_WEIGHT;
    fbo.begin();
    ofSetLineWidth(currentWeight);
    ofSetColor(color);
    ofPoint(x,y);
    fbo.end();
    return currentWeight < MAX_WEIGHT;
  };

};

class ofxCircle : public ofxShapes {
 protected:
  static const float MIN_RADIUS = 0.1;
  static const float MAX_RADIUS = 0.4;
  static const float DELTA_RADIUS = 0.05;
  float width, height;
  float x, y, currentRadius, r;
  ofColor color;
  
 public:
  ofxCircle(ofFbo fbo, ofxColorPalette palette) {
    width = fbo.getWidth();
    height = fbo.getHeight();
    currentRadius = ofRandom(width*MIN_RADIUS, width*MAX_RADIUS);
    x = ofRandom(width*MIN_RADIUS, width*(1-MIN_RADIUS));
    y = ofRandom(height*MIN_RADIUS, height*(1-MIN_RADIUS));
    color = palette.nextColor();
    r = 0;
  }

  virtual bool draw(ofFbo fbo) {
    r += DELTA_RADIUS;
    fbo.begin();
    ofSetColor(color);
    ofSetLineWidth(1.0);
    ofCircle(x, y, currentRadius*r, currentRadius*r);
    fbo.end();
    reteurn r < 1;
  };
};
