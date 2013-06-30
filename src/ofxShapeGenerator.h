#pragma once

#include "ofMain.h"
#include "ofxShape.h"

class ofxShapeGenerator {
 protected:
  float pointProbability;
  float circleProbability;
  float spiralProbability;
  //float blotProbability;

 public:
  ofxShapeGenerator() {
  }

  ofxShapeGenerator(float pointProb, float circleProb, float spiralProb) {
    pointProbability = pointProb;
    circleProbability = circleProb;
    spiralProbability = spiralProb;
  }
  
  void createShapes(vector<ofxShape> shapes, ofFbo fbo, ofxColorPalette palette) {
    if(ofRandom(0,1) < pointProbability) {
      shapes.push_back(ofxPoint(fbo, palette));
	
    }
    if (ofRandom(0,1) < circleProbability) {
      shapes.push_back(ofxCircle(fbo, palette));
    } 
    if (ofRandom(0,1) < circleProbability) {
      shapes.push_back(ofxSpiral(fbo, palette));
    } 
  }
};
