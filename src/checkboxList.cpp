#include "checkboxList.h"
#include <iostream>
using namespace std;

CheckboxList::CheckboxList() {
}

void CheckboxList::addCheckbox() {
    
    int placementX;
    int placementY;
    //cout<< ofGetWindowWidth() << ofGetWindowHeight();
    int rowExpected = ofGetWindowWidth() / 320; //5
    vector<int> maxPerRow; // 0, 5, 10, ...
    for (int i = 0; i < ofGetWindowHeight() / 200; i++) {
        maxPerRow.push_back(rowExpected * i);
    }
    
    if (checkboxes.size() < ofGetWindowWidth()/320) {
        placementX = checkboxes.size() * 310 + 10;
    }
    else {
        placementX = checkboxes.size() % (ofGetWindowWidth()/320) * 310 + 10;
    }
    
    for (int j = 0; j < maxPerRow.size(); j++) {
        if (checkboxes.size() >= maxPerRow[j] && checkboxes.size() < maxPerRow[j+1]) {
            placementY = j * 190+ 10;
        }
        
    }
    
    cout << placementX << "," << placementY << "\n";
//    ofSetLineWidth(4);
//    ofSetColor(ofColor::purple);
//    ofNoFill();
    ofRectangle* newSquare = new ofRectangle(placementX, placementY, 20,20);
    Checkbox *newCheckbox = new Checkbox(newSquare, placementX, placementY);
    checkboxes.push_back(newCheckbox);
}

void CheckboxList::drawCheckboxes() {
    for (Checkbox* checkbox : checkboxes) {
        ofSetLineWidth(4);
        ofSetColor(ofColor::purple);
        ofNoFill();
        ofDrawRectangle(*checkbox->getOfRectangle());
    }
}

CheckboxList::~CheckboxList() {
    for (int i = 0; i < checkboxes.size(); i++) {
        delete checkboxes[i];
        checkboxes[i] = NULL;
    }
    checkboxes.resize(0);
}

// May be unneccesary.
Checkbox* CheckboxList::getCheckbox(int checkboxNum) {
    for (int i = 0; i < checkboxes.size(); i++) {
        if (i == checkboxNum) {
            return checkboxes[i];
        }
    }
}

bool CheckboxList::mouseInside() {
    int mouseX = ofGetMouseX();
    int mouseY = ofGetMouseY();
    for (int i = 0; i < checkboxes.size(); i++) {
        Checkbox* currentCheckbox = getCheckbox(i);
        if (mouseX > currentCheckbox->getCoordX() && mouseX < currentCheckbox->getCoordX() + 20) {
            if (mouseY > currentCheckbox->getCoordY() && mouseY < currentCheckbox->getCoordY() + 20) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}

bool CheckboxList::mousePressedInside(int x, int y, int button) {
    if (button == 0) {
        for (int i = 0; i < checkboxes.size(); i++) {
            Checkbox* currentCheckbox = getCheckbox(i);
            if (x > currentCheckbox->getCoordX() && x < currentCheckbox->getCoordX() + 20) {
                if (y > currentCheckbox->getCoordY() && y < currentCheckbox->getCoordY() + 20) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
}

