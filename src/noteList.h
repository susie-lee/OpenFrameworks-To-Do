#pragma once
#include "ofMain.h"
#include "note.h"
#include <vector>

class NoteList  {
public:
    static vector<Note*> notes;

  NoteList();
  ~NoteList();
  static void addNote(Note *note);
  void drawNotes();
};
