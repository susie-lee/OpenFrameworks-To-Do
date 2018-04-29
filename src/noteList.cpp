#include "noteList.h"
#include <iostream>

NoteList::NoteList() {
}

void NoteList::addNote(Note *newNote) {
    
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
