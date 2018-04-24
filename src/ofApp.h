#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class toDoList : public ofBaseApp {
public:
  void setup();
  void draw();
  void keyPressed(int key);
ofxAssimpModelLoader flower;
    ofLight pointLight;
    ofLight pointLight2;
    ofLight pointLight3;
};
