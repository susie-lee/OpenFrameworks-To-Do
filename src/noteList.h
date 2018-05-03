#pragma once
#include "ofMain.h"
#include "note.h"
#include "ofxDatGui.h"

#include <vector>
#include <string>

using namespace std;

class NoteList  {
private:
    vector<Note*> notes;
    ofTrueTypeFont verdana14;
    
    int const number_of_notes = 25;
    
public:
  NoteList();
    void addNote();
    void drawNotes();
  ~NoteList();
    Note* getNote(int noteNum);
    void removeNote(int x, int y);
    void printNotes();
    int mousePressedCheckbox(int x, int y, int button);
    
};
