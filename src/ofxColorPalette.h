#pragma once

#include "ofMain.h"

class ofxColorPalette {
 public:
  virtual void reset() {
  };
  virtual ofColor nextColor() {
  };
};

class ofxRandomPalette : public ofxColorPalette {
 public:
  virtual ofColor nextColor() {
    ofColor color;
    color = ofColor::fromHsb(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
    return color;
  };
  
  virtual void reset() {
  };
};

class ofxRandomBrightPalette : public ofxColorPalette {
 public:
  virtual ofColor nextColor() {
    ofColor color;
    color.setHsb(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
    return color;
  };
  
  virtual void reset() {
  };
};
