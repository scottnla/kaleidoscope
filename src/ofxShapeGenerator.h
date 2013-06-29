#pragma once

#include "ofMain.h"
#include "ofxShapes.h"

class ofxShapeGenerator {
 protected:
  float pointProbability;
  float circleProbability;
  //float spiralProbability;
  //float blotProbability;

 public:
  ofxShapeGenerator(float pointProb, float circleProb) {
    pointProbability = pointProb;
    circleProbability = circleProb;
  }
  
  void createShapes(ofxShape shapes[], ofFbo fbo, ofxColorPalette palette) {
    if(ofRandom(0,1) < pointProbability) {
      shapes.add(new ofxPoint(fbo, palette));
    }
    if (ofRandom(0,1) < circleProbability) {
      shapes.add(new ofxCircle(fbo, palette));
    } 
  }
};
