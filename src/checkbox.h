#pragma once
#include "ofMain.h"
//#include "noteList.h"
#include <vector>

class Checkbox {
private:
    ofRectangle* ofRect;
    int coordX;
    int coordY;
    
public:
    Checkbox(ofRectangle* ofRect, int coordX, int coordY);
    Checkbox();
    ofRectangle* getOfRectangle();
    int getCoordX();
    int getCoordY();
};
