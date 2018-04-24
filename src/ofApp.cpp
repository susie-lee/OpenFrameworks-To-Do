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
////    ofEnableDepthTest();
////    ofEnableLighting();
//    glDisable(GL_COLOR_MATERIAL);
////    ofSetColor(250,250,250);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_NORMALIZE);
//    glEnable(GL_LIGHT7);
//    glDisable(GL_COLOR_MATERIAL);
//
//    ofPushMatrix();
//
//    flower.enableMaterials();
//  flower.drawFaces();
//
//    ofPopMatrix();
//    glDisable(GL_LIGHT0);
//    glDisable(GL_NORMALIZE);
//    glDisable(GL_LIGHTING);
    
    
//    pointLight.enable();
//    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
//
//    pointLight2.enable();
////    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
////
//    pointLight3.enable();
//    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    flower.drawFaces();
}
