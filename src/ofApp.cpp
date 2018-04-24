#include "ofApp.h"
#include "ofxAssimpModelLoader.h"

void toDoList::setup() {
  ofSetWindowTitle("Flower Productivity");
  ofBackground(200,200,200);
  flower.loadModel("flower.obj");
  //flower.drawFaces();
}

void toDoList::keyPressed(int key) {
  if (key == OF_KEY_F12) {
    ofToggleFullscreen();
    return;
  }
}

void toDoList::draw() {
  flower.setPosition(ofGetWidth()/2, (float)ofGetHeight() * 0.75 , 0);
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
    
    flower.drawFaces();
}
