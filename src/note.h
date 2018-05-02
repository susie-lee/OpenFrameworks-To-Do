#pragma once
#include "ofMain.h"
#include "ofxDatGui.h"
#include <vector>

class Note {
private:
    ofRectangle* ofPost;
    ofRectangle* ofCheckbox;
    int coordX;
    int coordY;

public:
    Note(ofRectangle* noteRect, ofRectangle* ofCheckbox, int coordX, int coordY);
    Note();
    ofRectangle* getOfPost();
    ofRectangle* getOfCheckbox();
    int getCoordX();
    int getCoordY();
    ~Note();
};
