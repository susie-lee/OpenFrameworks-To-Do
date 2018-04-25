#pragma once
#include "ofMain.h"
#include <vector>

class NoteList {
public:
  vector<ofRectangle*> notes;

  NoteList();
  ~NoteList();
  void addNote();
  void drawNotes();
};
