#include "ofxColorWheelPalette.h"

ofxColorWheelPalette::ofxColorWheelPalette(float hues[]) {
  numHues = sizeof(hues);
  hueOffsets = new float[numHues];
  hueOffsets = hues;
}

ofColor ofxColorWheelPalette::nextColor() {
  float h = hueValue;
  float s, b;
  ofColor color;
  float coinFlip = ofRandom(0,1);
  if(coinFlip < blackProbability) {
    s = 0;
    b = 0;
  }
  else if(coinFlip < blackProbability + whiteProbability) {
    s = 0;
    b = 1;
  }
  else if(coinFlip < blackProbability + whiteProbability + saturatedProbability) {
    s = 1;
    b = 1;
  }
  else {
    if(ofRandom(0,1) < 0.5) {
      s = ofRandom(0,1);
      b = 1;
    }
    else {
      s = 1;
      b = ofRandom(0,1);
    }
  }
  color.setHsb(h, s, b);
  return color;
}
  
void ofxColorWheelPalette::reset() {
  hueValue = ofRandom(0, 255);
  blackProbability = 0;
  whiteProbability = 0;
  saturatedProbability = 0;
  float coinFlip = ofRandom(0,1);
  if(coinFlip < 0.3) {
    saturatedProbability = 1;
  }
  else if (ofRandom(0,1) < 0.4) {
    blackProbability = 1.0/(1 + numHues);
    saturatedProbability = 1.0 - blackProbability;
  }
  else if (ofRandom(0,1) < 0.5) {
    whiteProbability = 1.0/(1 + numHues);
    saturatedProbability = 1 - whiteProbability;
  }
  else if (ofRandom(0,1) < 0.6) {
    blackProbability = 1.0/(2 + numHues);
    whiteProbability = 1.0/(2 + numHues);
    saturatedProbability = 1 - blackProbability - whiteProbability;
  }
  else {
  }
};
