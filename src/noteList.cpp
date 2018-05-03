#include "noteList.h"
#include "ofApp.h"
#include <iostream>
#include <string>

NoteList::NoteList() {
}

// Function to create a new note.
void NoteList::addNote() {
    
    if (notes.size() == number_of_notes) {
        return;
    }
    else {
        int placementX;
        int placementY;
        int rowExpected = ofGetWindowWidth() / 320; //5
        
        // Vector that holds number of notes as rows are added.
        vector<int> maxPerRow; // 0, 5, 10, ...
        for (int i = 0; i < ofGetWindowHeight() / 200; i++) {
            maxPerRow.push_back(rowExpected * i);
        }
        
        maxPerRow.push_back(maxPerRow.back() + rowExpected);
        
        // Determine x coordinate placement of new note.
        placementX = notes.size() % (ofGetWindowWidth()/320) * 310 + 60;
        
        //Determine y coordinate placement of new note.
        for (int j = 0; j < maxPerRow.size(); j++) {
            if (notes.size() >= maxPerRow[j] && notes.size() < maxPerRow[j+1]) {
                placementY = j * 190 + 10;
            }
        }
        
        // Create rectangle for textbox.
        ofRectangle* newPost = new ofRectangle(placementX, placementY, 300, 180);
        
        // Create rectangle for checkbox.
        ofRectangle* newOfCheckbox = new ofRectangle(placementX, placementY, 10, 10);
        
        // Create note with textbox rectangle, checkbox rectangle, and the
        // (x,y) for placement.
        Note *newNote = new Note(newPost, newOfCheckbox,placementX, placementY);
        
        // Add note to vector of notes.
        notes.push_back(newNote);
    }
}

void NoteList::drawNotes() {
    for (Note* note : notes) {
      verdana14.load("ofxbraitsch/fonts/verdana.ttf", 16);
      
      // Draw checkbox.
      ofSetLineWidth(3);
      ofSetColor(ofColor::mediumSpringGreen);
      ofNoFill();
      ofDrawRectangle(*note->getOfCheckbox());
      
      // Draw textbox.
      ofSetColor(ofColor::lemonChiffon);
      ofFill();
      ofDrawRectangle(*note->getOfPost());
  }
}

// Destructor for note of vectors.
NoteList::~NoteList() {
  for (int i = 0; i < notes.size(); i++) {
    delete notes[i];
    notes[i] = NULL;
  }
  notes.resize(0);
}

// Return note at given index.
Note* NoteList::getNote(int noteNum) {
    for (int i = 0; i < notes.size(); i++) {
        if (i == noteNum) {
            return notes[i];
        }
    }
}

// Remove note if checkbox is clicked.
void NoteList::removeNote(int x, int y) {
    int index = mousePressedCheckbox(x, y, 0);
    Note* toDelete = notes[index];
    notes.erase(notes.begin() + index);
}

// Return the index of the note vector if user clicks inside a checkbox.
int NoteList::mousePressedCheckbox(int x, int y, int button) {
    // Check if left button is clicked.
    if (button == 0) {
        for (int i = 0; i < notes.size(); i++) {
            Note* currentNote = getNote(i);
            
            // Check if user clicks within the x bounds of checkbox.
            if (x > currentNote->getCoordX() && x < currentNote->getCoordX() + 20) {
                
                // Check if user clicks within the y bounds of checkbox.
                if (y > currentNote->getCoordY() && y < currentNote->getCoordY() + 20) {
                    return i;
                }
            }
        }
        return -1;
    }
    return -1;
}
