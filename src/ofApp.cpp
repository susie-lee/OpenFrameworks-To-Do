#include "ofApp.h"
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

#include <iostream>

void window::setup() {
  ofSetWindowTitle("Flower Productivity");
  ofBackground(230,230,230);
  flower.loadModel("flower.obj");
    current_status = THRIVING;
    ofResetElapsedTimeCounter();
}

void window::keyPressed(int key) {

    if (key == 'n' && current_status != TYPING) {
        current_status = NEW_NOTE;

    } else if (current_status == TYPING && key == OF_KEY_RETURN) {
        current_status = THRIVING;
    }
}

void window::onTextInputEvent(ofxDatGuiTextInputEvent e) {
    cout << e.text << endl;
}

void window::mousePressed(int x, int y, int button) {
    if (noteList.mousePressedCheckbox(x, y, 0) != -1) {
        current_status = DELETE_NOTE;
    }
}

void window::update() {

}

void window::draw() {
  flower.setPosition(ofGetWidth()*3/4, (float)ofGetHeight() * 0.75 , 0);
    // Set lighting on flower.
    ofEnableDepthTest();
    ofEnableLighting();
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
    glDisable(GL_COLOR_MATERIAL);

    ofPushMatrix();

    flower.enableMaterials();
    flower.drawFaces();

    ofPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_NORMALIZE);
    glDisable(GL_LIGHTING);
    
    // Add new note.
    if (current_status == NEW_NOTE) {
        textList.addText();
        noteList.addNote();
        current_status = TYPING;
    }
    if (current_status == TYPING) {
        textList.drawTexts();
        noteList.drawNotes();
    }
    
    // Delete a note.
    else if (current_status == DELETE_NOTE) {
        noteList.removeNote(mouseX, mouseY);
        textList.removeText(mouseX, mouseY);
        current_status = THRIVING;
        ofResetElapsedTimeCounter();
    }
    
    else if (ofGetElapsedTimef() > 10) {//12 hours
        current_status = NEAR_DEATH;
        textList.drawTexts();
        noteList.drawNotes();
        flower.loadModel("dying_flower.obj");
        cout <<"here";
    } else if (ofGetElapsedTimef() > 5) { // 8 hours
        current_status = WHITHERING;
        textList.drawTexts();
        noteList.drawNotes();
        flower.loadModel("whithering_flower.obj");
        cout <<"no here";
    }
    
    else if (current_status == THRIVING) {
        textList.drawTexts();
        noteList.drawNotes();
        flower.loadModel("flower.obj");
    }
}
