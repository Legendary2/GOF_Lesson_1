
#include <iostream>

#include "Plane.h"
#include "MyTools.h"

using namespace std;

void Plane::Draw() const
{
    ScreenSingletone::getInstance().SetColor(CC_LightBlue);
    ScreenSingletone::getInstance().GotoXY(x, y);
    cout << "=========>";
    ScreenSingletone::getInstance().GotoXY(x - 2, y - 1);
    cout << "===";
    ScreenSingletone::getInstance().GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    ScreenSingletone::getInstance().GotoXY(x + 3, y + 1);
    cout << "////";
}
