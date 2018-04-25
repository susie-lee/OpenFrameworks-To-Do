#include "ofApp.h"
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include <iostream>

void window::setup() {
  ofSetWindowTitle("Flower Productivity");
  ofBackground(230,230,230);
  flower.loadModel("flower.obj");

    typeStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz\n0123456789,:&!?";
}

void window::keyPressed(int key) {

    if (key == 'n' && current_status != TYPING) {
      current_status = NEW_NOTE;

    } else if (key == OF_KEY_F12) {
      ofToggleFullscreen();

    } else if (current_status == TYPING) {
      if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
      typeStr = typeStr.substr(0, typeStr.length()-1);

      } else if(key == OF_KEY_RETURN ){
        current_status = THRIVING;

      } else {
        ofAppendUTF8(typeStr,key);
      }
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
    ofRectangle initial(10,10,200,100);
    ofDrawRectangle(initial);
    notes.push_back(initial);

    if (current_status == NEW_NOTE) {
        note.newNote();
        current_status = THRIVING;
    }
    
    else if (current_status == TYPING) {
        
    }
}
