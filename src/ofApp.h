#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "note.h"

enum Status {
    IDLE = 0,
    NEW_NOTE,
    THRIVING,
    DYING
};

class window : public ofBaseApp {
public:
    Status current_status = IDLE;
  void setup();
  void draw();
  void keyPressed(int key);
ofxAssimpModelLoader flower;
    Note note;
};
