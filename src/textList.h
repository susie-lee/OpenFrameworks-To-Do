#pragma once
#include "ofMain.h"
#include "ofxDatGui.h"

#include <vector>
#include <string>

using namespace std;

class TextList  {
private:
    vector<ofxDatGuiTextInput*> texts;
    vector<ofRectangle*> boxes;
    ofTrueTypeFont font;

public:
    TextList();
    void addText();
    void drawTexts();
    ~TextList();
    ofxDatGuiTextInput* getText(int textNum);
    void removeText(int x, int y);
    void printNotes();
    int mousePressedCheckbox(int x, int y, int button);
};

