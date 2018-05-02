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
        
        // Create text input gui.
        ofxDatGuiTextInput* textBox = new ofxDatGuiTextInput("input", "to-do...");
        textBox->setPosition(placementX + 12, placementY);
        textBox->setWidth(285, 0);
        textBox->setOpacity(1);
        
        texts.push_back(textBox);
        
        ofRectangle* newBox = new ofRectangle(placementX + 250, placementY + 5, 10, 10);
        boxes.push_back(newBox);
    }
}

void TextList::drawTexts() {
    font.load("ofxbraitsch/fonts/Verdana.ttf", 14);
    for (int i = 0; i < texts.size(); i++) {
        ofSetColor(ofColor::navajoWhite);
        ofDrawRectangle(*boxes[i]);
        
        ofSetColor(ofColor::salmon);
        texts[i]->setBackgroundColor(ofColor::lemonChiffon);
        texts[i]->draw();
        texts[i]->update();
        font.drawString(texts[i]->getText(), texts[i]->getX() + 10, texts[i]->getY() + 50);
    }
}

// Destructor for note of vectors.
TextList::~TextList() {
    for (int i = 0; i < texts.size(); i++) {
        delete texts[i];
        delete boxes[i];
        texts[i] = NULL;
        boxes[i] = NULL;
    }
    texts.resize(0);
    boxes.resize(0);
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
    
    ofRectangle* boxToDelete = boxes[index];
    boxes.erase(boxes.begin() + index);
}

// Return the index of the note vector if user clicks inside a checkbox.
int TextList::mousePressedCheckbox(int x, int y, int button) {
     //Check if left button is clicked.
    if (button == 0) {
        for (int i = 0; i < texts.size(); i++) {
            ofxDatGuiTextInput* currentText = getText(i);

            // Check if user clicks within the x bounds of checkbox.
            if (x > currentText->getX() - 12 && x < currentText->getX() + 8) {

                // Check if user clicks within the y bounds of checkbox.
                if (y > currentText->getY() && y < currentText->getY() + 20) {
                    return i;
                }
            }
        }
        return -1;
    }
    return -1;
}
