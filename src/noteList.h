#pragma once
#include "ofMain.h"
#include "note.h"
#include <vector>

using namespace std;

class NoteList  {
private:
    vector<Note*> notes;
    //int mousePressedInside(int x, int y, int button);
public:
  NoteList();
  ~NoteList();
  void addNote();
    void removeNote(int x, int y);
  void drawNotes();
  Note* getNote(int noteNum);
    int mousePressedInside(int x, int y, int button);
    
};
