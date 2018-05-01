#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "noteList.h"
#include <vector>

enum Status {
  THRIVING = 0,
  WHITHERING,
  NEAR_DEATH,
  NEW_NOTE,
  DELETE_NOTE
};

class window : public ofBaseApp {
public:
  Status current_status;
  void setup();
  void draw();
  void keyPressed(int key);
    void mousePressed(int x, int y, int button);

  ofxAssimpModelLoader flower;
  NoteList noteList;
  string typeStr;

  ofTrueTypeFont verdana14;
};
