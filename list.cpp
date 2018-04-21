#include "MyGUI.h"
#include "MyGUI_OgrePlatform.h"

// Lines 5 - 21 from http://wiki.ogre3d.org/MyGUI+quickstart
// Declaration.
MyGUI::Gui* list_GUI;
MyGUI::OgrePlatform* list_window;

// Initialization.
list_window = new MyGUI::OgrePlatform();
list_window->initialise(mWindow, mSceneManager);
list_GUI = new MyGUI::Gui();
list_GUI->initialise();

// Destruction.
list_GUI->shutdown();
delete list_GUI;
list_GUI = 0;
list_window->shutdown();
delete list_window;
list_window = 0;
