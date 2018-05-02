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
    //int mousePressedInside(int x, int y, int button);
public:
  NoteList();
  ~NoteList();
  void addNote();
    void removeNote(int x, int y);
  void drawNotes();
    void printNotes();
  Note* getNote(int noteNum);
    int mousePressedCheckbox(int x, int y, int button);
    int mousePressedBox(int x, int y, int button);
    string typeStr;
    ofTrueTypeFont verdana14;
    
};
