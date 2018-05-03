#pragma once
#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxAssimpModelLoader.h"
#include "noteList.h"
#include "textList.h"
#include <vector>

enum Status {
  THRIVING = 0,
  WITHERING,
  NEAR_DEATH,
  NEW_NOTE,
  TYPING,
  DELETE_NOTE
};

class window : public ofBaseApp {
private:
    Status current_status;
    ofxAssimpModelLoader flower;
    NoteList noteList;
    TextList textList;
    ofTrueTypeFont font;
    
    const int withering_seconds = 28800;
    const int dying_seconds = 43200;
    
public:
    void setup();
    void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void onTextInputEvent(ofxDatGuiTextInputEvent e);
};
