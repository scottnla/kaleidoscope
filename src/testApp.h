#pragma once

#include "ofMain.h"
#include "ofxColorWheelPalette.h"
#include "ofxShapeGenerator.h"

class testApp : public ofBaseApp{
 public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

 protected:		
  static const int BUFFER_SIZE = 200;
  static const int SIDE = 150;
  static const float MAX_TILE_ROTATION_DELTA = 0.02;
  static const float MAX_ROTATION_DELTA = 0.008;
  static const int RESET_COUNT = 3000;

  ofFbo tileBuffer;
  vector<ofxShape> shapes;
  ofxColorPalette palette;
  ofxShapeGenerator shapeGenerator;
  float tileRotation;
  float rotation;
  float tileRotationDelta;
  float rotationDelta;
  int nextReset;

  ofxColorPalette* allPalettes;
  ofxColorPalette getRandomPalette();
  ofxShapeGenerator* allShapeGenerators;
  ofxShapeGenerator getRandomShapeGenerator();
  void initColorPalettes();
  void initShapeGenerators();
  void reset();
  void updateTileBuffer();
  void drawAllTiles();
};
