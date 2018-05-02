#pragma once
#include "ofMain.h"
#include "ofxDatGui.h"
#include <vector>
#include <string>

using namespace std;

class TextList  {
private:
    vector<ofxDatGuiTextInput*> texts;
    //int mousePressedInside(int x, int y, int button);
public:
    TextList();
    ~TextList();
    void addText();
    void removeText(int x, int y);
    void drawTexts();
    void printNotes();
    ofxDatGuiTextInput* getText(int textNum);
    int mousePressedCheckbox(int x, int y, int button);
    int mousePressedBox(int x, int y, int button);
    
    ofTrueTypeFont font;
    
};

