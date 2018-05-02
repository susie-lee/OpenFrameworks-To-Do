#pragma once
#include "ofMain.h"
#include "ofxDatGui.h"
#include <vector>

class Note {
private:
    ofRectangle* ofPost;
    ofRectangle* ofCheckbox;
//    ofxDatGuiTextInput* noteBox;
    int coordX;
    int coordY;

public:
    Note(ofRectangle* noteRect, ofRectangle* ofCheckbox, int coordX, int coordY);
    Note();
    ofRectangle* getOfPost();
    ofRectangle* getOfCheckbox();
//    ofxDatGuiTextInput* getNoteBox();
    int getCoordX();
    int getCoordY();
    ~Note();
};
