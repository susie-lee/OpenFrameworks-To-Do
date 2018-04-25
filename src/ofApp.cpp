#include "ofApp.h"
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include <iostream>

void window::setup() {
  ofSetWindowTitle("Flower Productivity");
  ofBackground(230,230,230);
  flower.loadModel("flower.obj");
}

void window::keyPressed(int key) {

    switch(key) {
        case 'n':
            current_status = NEW_NOTE;
            break;
        case OF_KEY_F12:
            ofToggleFullscreen();
            break;
    }
}

void window::draw() {
  flower.setPosition(ofGetWidth()*3/4, (float)ofGetHeight() * 0.75 , 0);
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

    ofSetColor(ofColor::lemonChiffon);
    ofDrawRectangle(10,10,200,100);
    
    if (current_status == NEW_NOTE) {
        note.newNote();
    }
}
