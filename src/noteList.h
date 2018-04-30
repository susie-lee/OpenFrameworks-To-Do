#pragma once
#include "ofMain.h"
#include "note.h"
#include <vector>

using namespace std;

class NoteList  {
private:
    vector<Note*> notes;
    
public:
  NoteList();
  ~NoteList();
  void addNote();
  void drawNotes();
    
};
