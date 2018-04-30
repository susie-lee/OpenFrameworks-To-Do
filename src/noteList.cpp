#include "noteList.h"
#include <iostream>
using namespace std;

NoteList::NoteList() {
}

void NoteList::addNote() {
    
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
    if (notes.size() < ofGetWindowWidth()/320) {
        placementX = notes.size() * 310 + 10;
        //        placementY = 10;
    }
    else {
        placementX = notes.size() % (ofGetWindowWidth()/320) * 310 + 10;
    }
    
    for (int j = 0; j < maxPerRow.size(); j++) {
        if (notes.size() >= maxPerRow[j] && notes.size() < maxPerRow[j+1]) {
            placementY = j * 190 + 10;
        }
        
    }
    
    cout << placementX << "," << placementY << "\n";
    
    ofSetColor(ofColor::lemonChiffon);
    ofRectangle* newRect = new ofRectangle(placementX, placementY, 300, 180);
    Note *newNote = new Note(newRect, placementX, placementY);
    notes.push_back(newNote);
}

void NoteList::drawNotes() {
  for (Note* note : notes) {
      ofDrawRectangle(*note->getOfRectangle());
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

bool NoteList::mouseInside() {
    int mouseX = ofGetMouseX();
    int mouseY = ofGetMouseY();
    for (int i = 0; i < notes.size(); i++) {
        Note* currentNote = getNote(i);
        if (mouseX > currentNote->getCoordX() && mouseX < currentNote->getCoordX() + 300) {
            if (mouseY > currentNote->getCoordY() && mouseY < currentNote->getCoordY() + 180) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}

bool NoteList::mousePressedInside(int x, int y, int button) {
    if (button == 0) {
        for (int i = 0; i < notes.size(); i++) {
            Note* currentNote = getNote(i);
            if (x > currentNote->getCoordX() && x < currentNote->getCoordX() + 300) {
                if (y > currentNote->getCoordY() && y < currentNote->getCoordY() + 180) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
}
