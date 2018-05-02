#include "textList.h"
#include "ofApp.h"
#include <iostream>
#include <string>

TextList::TextList() {
}

// Function to create a new note.
void TextList::addText() {
    
    if (texts.size() == 25) {
        return;
    }
    else {
        int placementX;
        int placementY;
        int rowExpected = ofGetWindowWidth() / 320; //5
        
        // Vector that holds number of texts as rows are added.
        vector<int> maxPerRow; // 0, 5, 10, ...
        for (int i = 0; i < ofGetWindowHeight() / 200; i++) {
            maxPerRow.push_back(rowExpected * i);
        }
        
        // TODO: dont cover flower;
        maxPerRow.push_back(maxPerRow.back() + rowExpected);
        
        // Determine x coordinate placement of new text.
        placementX = texts.size() % (ofGetWindowWidth()/320) * 310 + 60;
        
        //Determine y coordinate placement of new text.
        for (int j = 0; j < maxPerRow.size(); j++) {
            if (texts.size() >= maxPerRow[j] && texts.size() < maxPerRow[j+1]) {
                placementY = j * 190 + 10;
            }
        }
        
        ofxDatGuiTextInput* textBox = new ofxDatGuiTextInput("input", "to-do...");
        textBox->setPosition(placementX + 10, placementY);
        textBox->setWidth(300, 0);
        
        texts.push_back(textBox);
    }
}

//void NoteList::onTextInputEvent(ofxDatGuiTextInputEvent e) {
//    std::cout << e.text << endl;
//}

void TextList::drawTexts() {
    font.load("ofxbraitsch/fonts/Verdana.ttf", 14);
    for (ofxDatGuiTextInput* text : texts) {
        text->draw();
        ofSetColor(ofColor::white);
        text->update();
        font.drawString(text->getText(), text->getX() + 10, text->getY() + 50);
    }
}

// Destructor for note of vectors.
TextList::~TextList() {
    for (int i = 0; i < texts.size(); i++) {
        delete texts[i];
        texts[i] = NULL;
    }
    texts.resize(0);
}

// Return note at given index.
ofxDatGuiTextInput* TextList::getText(int textNum) {
    for (int i = 0; i < texts.size(); i++) {
        if (i == textNum) {
            return texts[i];
        }
    }
}

// Remove note if checkbox is clicked.
void TextList::removeText(int x, int y) {
    int index = mousePressedCheckbox(x, y, 0);
    ofxDatGuiTextInput* toDelete = texts[index];
    texts.erase(texts.begin() + index);
}
//
//// Return the index of the note vector if user clicks inside a checkbox.
//int TextList::mousePressedCheckbox(int x, int y, int button) {
//    // Check if left button is clicked.
//    if (button == 0) {
//        for (int i = 0; i < texts.size(); i++) {
//            ofxDatGuiTextInput* currentText = getText(i);
//
//            // Check if user clicks within the x bounds of checkbox.
//            if (x > currentText->getX() && x < currentText->getX() + 20) {
//
//                // Check if user clicks within the y bounds of checkbox.
//                if (y > currentText->getY() && y < currentText->getY() + 20) {
//                    return i;
//                }
//            }
//        }
//        return -1;
//    }
//    return -1;
//}
//
//int TextList::mousePressedBox(int x, int y, int button) {
//    if (button == 0) {
//        for (int i = 0; i < notes.size(); i++) {
//            ofxDatGuiTextInput* currentNote = getNote(i);
//
//            // Check if user clicks within the x bounds of checkbox.
//            if (x > currentNote->getX() && x < currentNote->getX() + 300) {
//
//                // Check if user clicks within the y bounds of checkbox.
//                if (y > currentNote->getCoordY() && y < currentNote->getCoordY() + 180) {
//                    return i;
//                }
//            }
//        }
//        return -1;
//    }
//    return -1;
//}
