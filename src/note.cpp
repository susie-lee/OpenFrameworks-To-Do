#pragma once
#include "note.h"
#include "noteList.h"
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

void Note::setUpNote() {
    int placementX;
    int placementY;
    //cout<< ofGetWindowWidth() << ofGetWindowHeight();
    int rowExpected = ofGetWindowWidth() / 320; //5
    vector<int> maxPerRow; // 0, 5, 10, ...
    for (int i = 0; i < ofGetWindowHeight() / 200; i++) {
        maxPerRow.push_back(rowExpected * i);
    }
    
    for (int elem : maxPerRow) {
        cout << elem << ",";
    }
    if (noteList.size() < ofGetWindowWidth()/320) {
        placementX = noteList.size() * 310 + 10;
        //        placementY = 10;
    }
    else {
        placementX = noteList.size() % (ofGetWindowWidth()/320) * 310 + 10;
    }
    
    for (int j = 0; j < maxPerRow.size(); j++) {
        if (noteList.size() >= maxPerRow[j] && noteList.size() < maxPerRow[j+1]) {
            placementY = j * 190 + 10;
        }
        
    }
    
    cout << placementX << "," << placementY << "\n";
    
    ofSetColor(ofColor::lemonChiffon);
    ofRectangle* newRect = new ofRectangle(placementX, placementY, 300, 180);
    Note *newNote = new Note(newRect, placementX, placementY);
    noteList.addNote(*newNote);
}
