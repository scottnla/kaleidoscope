#include "ofxColorPalette.h"

class ofxColorWheelPalette : public ofxColorPalette {
 public:
  ofxColorWheelPalette(vector<float> hues);

  virtual ofColor nextColor();
  virtual void reset();

 protected:
  vector<float> hueOffsets;
  int numHues;
  float blackProbability;
  float whiteProbability;
  float saturatedProbability;
  float hueValue;
};
