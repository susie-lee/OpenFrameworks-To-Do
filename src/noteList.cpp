#include "noteList.h"
#include <iostream>

NoteList::NoteList() {
}

void NoteList::addNote() {
    int placementX;
    int placementY;
    int rowExpected = ofGetWindowWidth() / 320; //5
    vector<int> maxPerRow; // 0, 5, 10, ...
    for (int i = 0; i < ofGetWindowHeight() / 200; i++) {
        maxPerRow.push_back(rowExpected * i);
    }
    
    if (notes.size() < ofGetWindowWidth()/320) {
        placementX = notes.size() * 310 + 10;
    }
    else {
        placementX = notes.size() % (ofGetWindowWidth()/320) * 310 + 10;
    }
    
    for (int j = 0; j < maxPerRow.size(); j++) {
        if (notes.size() >= maxPerRow[j] && notes.size() < maxPerRow[j+1]) {
            placementY = j * 190 + 10;
        }
    }
    ofRectangle* newPost = new ofRectangle(placementX, placementY, 300, 180);
    ofRectangle* newOfCheckbox = new ofRectangle(placementX, placementY, 10, 10);
    Note *newNote = new Note(newPost, newOfCheckbox, placementX, placementY);
    notes.push_back(newNote);
}

void NoteList::drawNotes() {
  for (Note* note : notes) {
//      ofSetColor(ofColor::lemonChiffon);
//      ofFill();
//      ofDrawRectangle(*note->getOfPost());
      
      ofSetLineWidth(4);
      ofSetColor(ofColor::mediumSpringGreen);
      ofNoFill();
      ofDrawRectangle(*note->getOfCheckbox());
      
      ofSetColor(ofColor::lemonChiffon);
      ofFill();
      ofDrawRectangle(*note->getOfPost());
  }
}

NoteList::~NoteList() {
  for (int i = 0; i < notes.size(); i++) {
    delete notes[i];
    notes[i] = NULL;
  }
  notes.resize(0);
}

// May be unneccesary.
Note* NoteList::getNote(int noteNum) {
    for (int i = 0; i < notes.size(); i++) {
        if (i == noteNum) {
            return notes[i];
        }
    }
}
void NoteList::removeNote(int x, int y) {
    int index = mousePressedInside(x, y, 0);
    Note* toDelete = notes[index];
    notes.erase(notes.begin() + index);
    
}
int NoteList::mousePressedInside(int x, int y, int button) {
    if (button == 0) {
        for (int i = 0; i < notes.size(); i++) {
            Note* currentNote = getNote(i);
            if (x > currentNote->getCoordX() && x < currentNote->getCoordX() + 20) {
                if (y > currentNote->getCoordY() && y < currentNote->getCoordY() + 20) {
                    //std::cout << "TRUE" << "\n";
                    return i;
                }
            }
        }
        return -1;
    }
    return -1;
}

