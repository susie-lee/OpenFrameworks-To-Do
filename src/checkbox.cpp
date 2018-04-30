#include "checkbox.h"
#include <vector>

Checkbox::Checkbox(ofRectangle* ofRect, int coordX, int coordY) :
ofRect(ofRect), coordX(coordX), coordY(coordY){
}

Checkbox::Checkbox() {
    
}

ofRectangle* Checkbox::getOfRectangle() {
    return ofRect;
}

int Checkbox::getCoordX() {
    return coordX;
}

int Checkbox::getCoordY() {
    return coordY;
}
