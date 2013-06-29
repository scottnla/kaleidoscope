#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofBackground(0,0,0);
  ofEnableSmoothing();
  ofSetFrameRate(30);

  initColorPalettes();
  initShapeGenerators();
  reset();
}

//--------------------------------------------------------------
void testApp::update(){
  updateTileBuffer();
}

//--------------------------------------------------------------
void testApp::draw(){
  drawAllTiles();
  if(nextReset < 0) {
    reset();
  }
  nextReset--;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
ofxColorPalette testApp::getRandomPalette() {
  //make this a function that accepts a palette list
  ofxColorPalette palette = allPalettes[int(ofRandom(0, sizeof(allPalettes)))];
  palette.reset();
  return palette;
};

//--------------------------------------------------------------
ofxShapeGenerator testApp::getRandomShapeGenerator() {
  //make this a function that accepts a shape generator list
  return allShapeGenerators[int(ofRandom(0, sizeof(allShapeGenerators)))];
};

//--------------------------------------------------------------
void testApp::initColorPalettes() {
  float monochrome[1] = {0};
  float complementary[2] = {0, 255.0/2.0};
  float split_complementary[3] = {0, 255.0/12.0*5, 255/12.0*7};
  float triadic[3] = {0, 255.0/3.0, 255/3.0*2};
  float tetradic[4] = {0, 255.0/4.0, 255.0/2.0, 255.0/4.0*3};
  float four_tone[4] = {0, 255.0/6.0, 255.0/6.0*3, 255.0/6.0*4};
  float five_tone[5] = {0, 255.0/72.0*23, 255.0/72.0*31, 255.0/72.0*41, 255.0/72.0*49};
  float six_tone[6] = {0, 255.0/12.0, 255.0/12.0*4, 255.0/12.0*5, 255.0/12.0*8, 255.0/12.0*9};
  float neutral[6] = {0, 255.0/24.0, 255.0/24.0*2, 255.0/24.0*3, 255.0/24.0*4, 255.0/24.0*5};

  ofxColorPalette* allPalettes[] = {
    new ofxRandomPalette(),
    new ofxRandomBrightPalette(),
    new ofxRandomBrightPalette(),
    new ofxRandomBrightPalette(),
    new ofxColorWheelPalette(monochrome),
    new ofxColorWheelPalette(complementary),
    new ofxColorWheelPalette(split_complementary),
    new ofxColorWheelPalette(triadic),
    new ofxColorWheelPalette(tetradic),
    new ofxColorWheelPalette(four_tone),
    new ofxColorWheelPalette(five_tone),
    new ofxColorWheelPalette(six_tone),
    new ofxColorWheelPalette(neutral)
  };
}

//--------------------------------------------------------------
void testApp::initShapeGenerators() {
  ofxShapeGenerator* allShapeGenerators[] = {
    new ofxShapeGenerator(0.2, 0.8),
    new ofxShapeGenerator(0.5, 0.5),
    new ofxShapeGenerator(0.9, 0.1)
  };
}

//--------------------------------------------------------------
void testApp::reset() {
  shapes.clear();
  palette = getRandomPalette();
  shapeGenerator = getRandomShapeGenerator();
  tileRotationDelta = ofRandom(-MAX_TILE_ROTATION_DELTA, MAX_TILE_ROTATION_DELTA);
  rotationDelta = ofRandom(-MAX_ROTATION_DELTA, MAX_ROTATION_DELTA);
  nextReset = RESET_COUNT;
}

//--------------------------------------------------------------
void testApp::updateTileBuffer() {
  tileBuffer.begin();
  //filter blur
  shapeGenerator.createShapes(shapes, tileBuffer, palette);
  //draw all shapes in buffer
  tileBuffer.end();
}

//--------------------------------------------------------------
void testApp::drawAllTiles() {
  
}
