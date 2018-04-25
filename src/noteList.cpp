#include "noteList.h"

NoteList::NoteList() {
}

void NoteList::addNote() {
  int placement = notes.size() * 210 + 10;
  ofSetColor(ofColor::lemonChiffon);
  ofRectangle* newNote = new ofRectangle(placement, 10, 200, 100);
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
