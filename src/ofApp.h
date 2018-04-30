#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "noteList.h"
#include "checkboxList.h"
#include <vector>

enum Status {
  THRIVING = 0,
  WHITHERING,
  NEAR_DEATH,
  NEW_NOTE,
  TYPING
};

class window : public ofBaseApp {
public:
  Status current_status = THRIVING;
  void setup();
  void draw();
  void keyPressed(int key);

  ofxAssimpModelLoader flower;
  NoteList noteList;
    CheckboxList checkboxList;
  string typeStr;

  ofTrueTypeFont verdana14;
};
