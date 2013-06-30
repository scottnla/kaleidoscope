#include "ofxColorWheelPalette.h"

ofxColorWheelPalette::ofxColorWheelPalette(vector<float> hues) {
  ofLog() << "Processing new color palette!";
  ofLog() << "Number of hues: " << hues.size();
  hueOffsets = hues;
  numHues = hues.size();
}

ofColor ofxColorWheelPalette::nextColor() {
  ofLog() << "Processing NEXT COLOR";
  float h = fmod(hueValue + hueOffsets[int(ofRandom(0,hueOffsets.size()))], TWO_PI);
  ofLog() << "next hue: " << h;
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
  ofLog() << h << s << b;
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
  ofLog() << "Resetting color wheel . . . ";
};
