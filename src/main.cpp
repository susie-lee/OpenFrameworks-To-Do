#include "ofMain.h"
#include "ofApp.h"
#include "noteList.h"
#include "note.h"
#include "ofxAssimpModelLoader.h"

#include <iostream>

#define DISPLAY_MODE OF_FULLSCREEN

int main() {
  ofSetupOpenGL(640, 480, DISPLAY_MODE);
  ofRunApp(new window());
}
