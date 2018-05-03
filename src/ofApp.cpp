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

    // 'N' key to create new note.
    if (key == 'n' && current_status != TYPING) {
        current_status = NEW_NOTE;

    // Enter to finish typing.
    } else if (current_status == TYPING && key == OF_KEY_RETURN) {
        current_status = THRIVING;
    }
}

void window::mousePressed(int x, int y, int button) {
    if (noteList.mousePressedCheckbox(x, y, 0) != -1) {
        current_status = DELETE_NOTE;
    }
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
    
    // If user is inputting to-do text into box.
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
    
    // Determine if flower should be dying.
    else if (ofGetElapsedTimef() > 10) {//12 hours
        current_status = NEAR_DEATH;
        textList.drawTexts();
        noteList.drawNotes();
        flower.loadModel("dying_flower.obj");
        
    // Determine if flower should be whithering.
    } else if (ofGetElapsedTimef() > 5) { // 8 hours
        current_status = WITHERING;
        textList.drawTexts();
        noteList.drawNotes();
        flower.loadModel("withering_flower.obj");
    }
    
    // If flower is thriving.
    else if (current_status == THRIVING) {
        textList.drawTexts();
        noteList.drawNotes();
        flower.loadModel("flower.obj");
    }
}
