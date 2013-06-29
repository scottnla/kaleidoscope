#include "ofxColorPalette.h"

class ofxColorWheelPalette : public ofxColorPalette {
 public:
  ofxColorWheelPalette(float hues[]);

  virtual ofColor nextColor();
  virtual void reset();

 protected:
  float *hueOffsets;
  int numHues;
  float blackProbability;
  float whiteProbability;
  float saturatedProbability;
  float hueValue;
};
