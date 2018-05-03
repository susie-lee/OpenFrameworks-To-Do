#include "note.h"

#include <vector>

Note::Note(ofRectangle* ofPost, ofRectangle* ofCheckbox, int coordX, int coordY) :
ofPost(ofPost), ofCheckbox(ofCheckbox), coordX(coordX), coordY(coordY){
}

Note::Note() {
    
}

ofRectangle* Note::getOfPost() {
    return ofPost;
}

ofRectangle* Note::getOfCheckbox() {
    return ofCheckbox;
}

int Note::getCoordX() {
    return coordX;
}

int Note::getCoordY() {
    return coordY;
}

Note::~Note() {
    delete ofPost;
    delete ofCheckbox;
}
