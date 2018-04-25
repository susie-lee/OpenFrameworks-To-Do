#include "noteList.h"
#include <iostream>

NoteList::NoteList() {
}

void NoteList::addNote() {
    int placementX = 0;
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
    if (notes.size() < ofGetWindowWidth()/320) {
        placementX = notes.size() * 310 + 10;
//        placementY = 10;
    }
    else {
        placementX = notes.size() % (ofGetWindowWidth()/320) * 310 + 10;
//        for (int j = 0; j < maxPerRow.size(); j++) {
//            if (maxPerRow[j] == notes.size()) {
//                placementY = j * 190 + 10;
//            }
//        }
    }
    
    //for (int element : maxPerRow) {
        //if (notes.size() == element) {
            for (int j = 0; j < maxPerRow.size(); j++) {
                if (notes.size() >= maxPerRow[j] && notes.size() < maxPerRow[j+1]) {
                    placementY = j * 190 + 10;
                }
            }
        //}
    //}
    
    cout << placementX << "," << placementY << "\n";

  ofSetColor(ofColor::lemonChiffon);
  ofRectangle* newNote = new ofRectangle(placementX, placementY, 300, 180);
  notes.push_back(newNote);
}

void NoteList::drawNotes() {
  for (ofRectangle* rect : notes) {
    ofDrawRectangle(*rect);
  }
}

NoteList::~NoteList() {
  for (int i = 0; i < notes.size(); i++) {
    delete notes[i];
    notes[i] = NULL;
  }
  notes.resize(0);
}
