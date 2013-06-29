#pragma once

#include "ofMain.h"
#include "ofxShape.h"

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
  
  void createShapes(vector<ofxShape> shapes, ofFbo fbo, ofxColorPalette palette) {
    if(ofRandom(0,1) < pointProbability) {
      shapes.push_back(new ofxPoint(fbo, palette));
    }
    if (ofRandom(0,1) < circleProbability) {
      shapes.push_back(new ofxCircle(fbo, palette));
    } 
  }
};
