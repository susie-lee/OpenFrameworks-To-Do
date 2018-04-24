#include "ofMain.h"
#include "ofApp.h"
#include "ofxAssimpModelLoader.h"

#define DISPLAY_MODE OF_WINDOW

int main() {
  ofSetupOpenGL(640, 480, DISPLAY_MODE);
  ofRunApp(new toDoList());
}
