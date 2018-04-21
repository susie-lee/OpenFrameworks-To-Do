#include "MyGUI.h" //path to MyGUI
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

// To move completed tasks to flower/tree.
class CREATE_LIST : public OIS::MouseListener, public OIS::KeyListener

bool CREATE_LIST::mouseMoved(const OIS::MouseEvent &arg) {
  MyGUI::InputManager::getInstance().injectMouseMove(arg.state.X.abs,
  arg.state.Y.abs, arg.state.Z.abs);

  return true;
}

bool CREATE_LIST::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id) {
  MyGUI::InputManager::getInstance().injectMousePress(arg.state.X.abs,
  arg.state.Y.abs, MyGUI::MouseButton::Enum(id));

  return true;
}

bool CREATE_LIST::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id) {
  MyGUI::InputManager::getInstance().injectMouseRelease(arg.state.X.abs,
  arg.state.Y.abs, MyGUI::MouseButton::Enum(id));

  return true;
}
