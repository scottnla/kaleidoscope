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
  //drawAllTiles();
  if(nextReset < 0) {
    reset();
  }
  nextReset--;
  tileBuffer.draw(0,0);
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
ofxColorPalette testApp::getRandomPalette(vector<ofxColorPalette> paletteList) {
  //make this a function that accepts a palette list
  int randomNumber = int(ofRandom(0, paletteList.size()));
  ofLog() << "Picked palette number " << randomNumber;
  ofxColorPalette palette = paletteList[randomNumber];
  palette.reset();
  return palette;
};

//--------------------------------------------------------------
ofxShapeGenerator testApp::getRandomShapeGenerator(vector<ofxShapeGenerator> generatorList) {
  //make this a function that accepts a shape generator list
  return generatorList[int(ofRandom(0, generatorList.size()))];
};

//--------------------------------------------------------------
void testApp::initColorPalettes() {
  vector<float> monochrome = {0};
  vector<float> complementary = {0, 255.0/2.0};
  vector<float> split_complementary = {0, 255.0/12.0*5, 255/12.0*7};
  vector<float> triadic = {0, 255.0/3.0, 255/3.0*2};
  vector<float> tetradic = {0, 255.0/4.0, 255.0/2.0, 255.0/4.0*3};
  vector<float> four_tone = {0, 255.0/6.0, 255.0/6.0*3, 255.0/6.0*4};
  vector<float> five_tone = {0, 255.0/72.0*23, 255.0/72.0*31, 255.0/72.0*41, 255.0/72.0*49};
  vector<float> six_tone = {0, 255.0/12.0, 255.0/12.0*4, 255.0/12.0*5, 255.0/12.0*8, 255.0/12.0*9};
  vector<float> neutral = {0, 255.0/24.0, 255.0/24.0*2, 255.0/24.0*3, 255.0/24.0*4, 255.0/24.0*5};

  allPalettes.push_back(ofxRandomPalette());
  allPalettes.push_back(ofxRandomBrightPalette());
  allPalettes.push_back(ofxRandomBrightPalette());
  allPalettes.push_back(ofxRandomBrightPalette());
  allPalettes.push_back(ofxColorWheelPalette(monochrome));
  allPalettes.push_back(ofxColorWheelPalette(complementary));
  allPalettes.push_back(ofxColorWheelPalette(split_complementary));
  allPalettes.push_back(ofxColorWheelPalette(triadic));
  allPalettes.push_back(ofxColorWheelPalette(tetradic));
  allPalettes.push_back(ofxColorWheelPalette(four_tone));
  allPalettes.push_back(ofxColorWheelPalette(five_tone));
  allPalettes.push_back(ofxColorWheelPalette(six_tone));
  allPalettes.push_back(ofxColorWheelPalette(neutral));
}

//--------------------------------------------------------------
void testApp::initShapeGenerators() {
  allShapeGenerators.push_back(ofxShapeGenerator(0.2, 0.6, 0.2));
  allShapeGenerators.push_back(ofxShapeGenerator(0.33, 0.33, 0.33));
  allShapeGenerators.push_back(ofxShapeGenerator(0.6, 0.2, 0.2));
}

//--------------------------------------------------------------
void testApp::reset() {
  shapes.clear();
  palette = getRandomPalette(allPalettes);
  ofLog() << "Generating next palette color";
  ofColor tempColor = palette.nextColor();
  ofLog() << "Selected Palette hue: " << tempColor.getHue();
  ofLog() << "Selected Palette saturation: " << tempColor.getSaturation();
  ofLog() << "Selected Palette brightness: " << tempColor.getBrightness();

  shapeGenerator = getRandomShapeGenerator(allShapeGenerators);
  tileRotationDelta = ofRandom(-MAX_TILE_ROTATION_DELTA, MAX_TILE_ROTATION_DELTA);
  rotationDelta = ofRandom(-MAX_ROTATION_DELTA, MAX_ROTATION_DELTA);
  nextReset = RESET_COUNT;
}

//--------------------------------------------------------------
void testApp::updateTileBuffer() {
  tileBuffer.begin();
  //add blur
  shapeGenerator.createShapes(shapes, tileBuffer, palette);
  for(int i = 0; i < shapes.size(); i++) {
    ofxShape currentShape = shapes[i];
    if(!currentShape.draw(tileBuffer)) {
      shapes.erase(shapes.begin() + i - 1);
    }
  }
  tileBuffer.end();
}

//--------------------------------------------------------------
void testApp::drawAllTiles() {
  
}
