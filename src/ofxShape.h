#pragma once

#include "ofMain.h"

/*
 * Interface class
 */
class ofxShape {
 public:
  virtual bool draw(ofFbo fbo) {
  };
};

/*
 * Point class
 */
class ofxPoint : public ofxShape {
 protected:
  static constexpr float MAX_WEIGHT = 7;
  static constexpr float DELTA_WEIGHT = 0.2;
  float x, y, currentWeight;
  ofColor color;
  
 public:
  ofxPoint(ofFbo fbo, ofxColorPalette palette) {
    x = ofRandom(0, fbo.getWidth());
    y = ofRandom(0, fbo.getHeight());
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

/*
 * Circle class
 */
class ofxCircle : public ofxShape {
 protected:
  static constexpr float MIN_RADIUS = 0.1;
  static constexpr float MAX_RADIUS = 0.4;
  static constexpr float DELTA_RADIUS = 0.05;
  float width, height;
  float x, y, radius, r;
  ofColor color;
  
 public:
  ofxCircle(ofFbo fbo, ofxColorPalette palette) {
    width = fbo.getWidth();
    height = fbo.getHeight();
    radius = ofRandom(width*MIN_RADIUS, width*MAX_RADIUS);
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
    ofCircle(x, y, radius*r, radius*r);
    fbo.end();
    return r < 1;
  };
};

/*
 * Spiral class
 */
class ofxSpiral : public ofxShape {
 protected:
  static constexpr float MIN_RADIUS = 0.3;
  static constexpr float MAX_RADIUS = 0.6;
  static const int WEIGHT = 5;
  static const int STEPS = 10;
  static constexpr float DELTA_RADIUS = 0.003;
  static constexpr float MAX_DELTA_THETA = 0.05;

  float width, height;
  float x, y, radius, r, theta, deltaTheta;
  ofColor color;

 public:
  ofxSpiral(ofFbo fbo, ofxColorPalette palette) {
    width = fbo.getWidth();
    height = fbo.getHeight();
    radius = ofRandom(width*MIN_RADIUS, width*MAX_RADIUS);
    x = ofRandom(width*MIN_RADIUS, width*(1-MIN_RADIUS));
    y = ofRandom(height*MIN_RADIUS, height*(1-MIN_RADIUS));
    color = palette.nextColor();
    r = 0;
    theta = ofRandom(0, TWO_PI);
    deltaTheta = ofRandom(-MAX_DELTA_THETA, MAX_DELTA_THETA);
  }

  virtual bool draw(ofFbo fbo) {
    
    fbo.begin();
    ofSetLineWidth(WEIGHT);
    ofSetColor(color);
    for(int i = 0; i < STEPS; i++) {
      float x0 = x + r*radius*sin(theta);
      float y0 = y + r*radius*cos(theta);
      r += DELTA_RADIUS;
      theta += deltaTheta;
      float x1 = x + r*radius*sin(theta);
      float y1 = y + r*radius*cos(theta);
      ofLine(x0, y0, x1, y1);
      if(r >= 1) {
	return false;
      }
    }
    fbo.end();
    return true;
  };
};

/*
 * Star class

class ofxStar : ofxShape {
 protected:
  static const int MIN_SIDES = 3;
  static const int MAX_SIDES = 40;
  static const float MIN_RADIUS = 0.1;
  static const float MAX_RADIUS = 0.4;
  static const float DELTA_RADIUS = 0.05;

  float width, height;
  int sides;
  float radii[];
  float x, y, r;
  ofColor color;

 public:
  ofxPolygon(ofFbo fbo, ofxColorPalette palette) {
    sides = int(ofRandom(MIN_SIDES, MAX_SIDES));
    radii = new float[sides];
  }
}

class ofxPolygon : ofxShape {
}
*/
