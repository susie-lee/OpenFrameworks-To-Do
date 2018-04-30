#pragma once
#include "ofMain.h"
#include "checkbox.h"
#include <vector>

using namespace std;

class CheckboxList  {
private:
    vector<Checkbox*> checkboxes;
    
public:
    CheckboxList();
    ~CheckboxList();
    void addCheckbox();
    void drawCheckboxes();
    Checkbox* getCheckbox(int checkboxNum);
    bool mouseInside();
    bool mousePressedInside(int x, int y, int button);
};
