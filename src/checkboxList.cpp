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
    
    for (int elem : maxPerRow) {
        cout << elem << ",";
    }
    if (checkboxes.size() < ofGetWindowWidth()/320) {
        placementX = checkboxes.size() * 290 + 10;
        //        placementY = 10;
    }
    else {
        placementX = checkboxes.size() % (ofGetWindowWidth()/320) * 290 + 10;
    }
    
    for (int j = 0; j < maxPerRow.size(); j++) {
        if (checkboxes.size() >= maxPerRow[j] && checkboxes.size() < maxPerRow[j+1]) {
            placementY = j * 170 + 10;
        }
        
    }
    
    cout << placementX << "," << placementY << "\n";
    ofSetLineWidth(4);
    ofSetColor(ofColor::antiqueWhite);
    ofNoFill();
    ofRectangle* newRect = new ofRectangle(placementX, placementY, 10, 10);
    Checkbox *newCheckbox = new Checkbox(newRect, placementX, placementY);
    checkboxes.push_back(newCheckbox);
}

void CheckboxList::drawCheckboxes() {
    for (Checkbox* checkbox : checkboxes) {
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
Checkbox* CheckboxList::getCheckbox(int noteNum) {
    for (int i = 0; i < checkboxes.size(); i++) {
        if (i == noteNum) {
            return checkboxes[i];
        }
    }
}

bool CheckboxList::mouseInside() {
    int mouseX = ofGetMouseX();
    int mouseY = ofGetMouseY();
    for (int i = 0; i < checkboxes.size(); i++) {
        Checkbox* currentCheckbox = getCheckbox(i);
        if (mouseX > currentCheckbox->getCoordX() && mouseX < currentCheckbox->getCoordX() + 300) {
            if (mouseY > currentCheckbox->getCoordY() && mouseY < currentCheckbox->getCoordY() + 180) {
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
            if (x > currentCheckbox->getCoordX() && x < currentCheckbox->getCoordX() + 300) {
                if (y > currentCheckbox->getCoordY() && y < currentCheckbox->getCoordY() + 180) {
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

