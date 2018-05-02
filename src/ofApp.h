#pragma once
#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxAssimpModelLoader.h"
#include "noteList.h"
#include <vector>

enum Status {
  THRIVING = 0,
  WHITHERING,
  NEAR_DEATH,
  NEW_NOTE,
  TYPING,
  DELETE_NOTE
};

class window : public ofBaseApp {
public:
  Status current_status;
  void setup();
    void update();
  void draw();
  void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void onTextInputEvent(ofxDatGuiTextInputEvent e);

  ofxAssimpModelLoader flower;
  NoteList noteList;
//  string* typeStr;
    
    ofxDatGuiTextInput* noteInput;

  ofTrueTypeFont font;
};
