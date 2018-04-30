#include "note.h"
#include <vector>

Note::Note(ofRectangle* ofRect, int coordX, int coordY) :
    ofRect(ofRect), coordX(coordX), coordY(coordY){
}

Note::Note() {
    
}

ofRectangle* Note::getOfRectangle() {
    return ofRect;
}

int Note::getCoordX() {
    return coordX;
}

int Note::getCoordY() {
    return coordY;
}
