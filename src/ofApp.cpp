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
    
    noteInput = new ofxDatGuiTextInput("input", "to-do...");
    //noteInput->onTextInputEvent(this, &window::onTextInputEvent);
    //noteInput->setWidth(800, 0.2);
    noteInput->setPosition(300, 300);
    font.load("ofxbraitsch/fonts/Verdana.ttf", 14);
}

void window::keyPressed(int key) {

    if (key == 'n' && current_status != TYPING) {
        current_status = NEW_NOTE;
//        while (key != OF_KEY_RETURN) {
//            if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
//                typeStr->substr(0, typeStr->length()-1);
//            }
//            typeStr->append(to_string(key));
//        }
        
        //call some function here

    } else if (current_status == TYPING && key == OF_KEY_RETURN) {
        current_status = THRIVING;
    }//else if (key == OF_KEY_F12) {
//      ofToggleFullscreen();
//
//    } else if (current_status == NEW_NOTE) {
//      if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
//      typeStr = typeStr.substr(0, typeStr.length()-1);
//
//      } else if(key == OF_KEY_RETURN ){
//        current_status = THRIVING;
//
//     else {
////         while (key != OF_KEY_RETURN) {
////             if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
////                 typeStr->substr(0, typeStr->length()-1);
////             }
////             typeStr->append(to_string(key));
////         }
////         //call some function here
//      }
}

void window::onTextInputEvent(ofxDatGuiTextInputEvent e) {
    cout << e.text << endl;
}

void window::mousePressed(int x, int y, int button) {
    //cout << noteList.mousePressedInside(x, y, 0);
    if (noteList.mousePressedCheckbox(x, y, 0) != -1) {
        current_status = DELETE_NOTE;
    }
//    } else if (noteList.mousePressedBox(x, y, 0) != -1) {
//        
//    }
}

void window::update() {
//    if (ofGetElapsedTimef() > 43200) {//8 hours
//        current_status = NEAR_DEATH;
//    } else if (ofGetElapsedTimef() > 28800) {
//        current_status = WHITHERING;
//    } else {
//        current_status = THRIVING;
//    }
//    noteInput->update();
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
    
    // Draw rectangles for textbox and checkbox.
    noteList.drawNotes();
    //noteList.printNotes();

    // Add new note.
    if (current_status == NEW_NOTE) {
        cout << "lets try";
        noteList.addNote();
        cout << "hm okay";
        current_status = TYPING;
    }
    if (current_status == TYPING) {
//        noteInput->draw();
//        ofSetColor(ofColor::white);
//        noteInput->update();
//        font.drawString(noteInput->getText(), 300, 300);
////        current_status = THRIVING;
        noteList.printNotes();
    }
    
    // Delete a note.
    else if (current_status == DELETE_NOTE) {
        noteList.removeNote(mouseX, mouseY);
        current_status = THRIVING;
        ofResetElapsedTimeCounter();
    }
}
