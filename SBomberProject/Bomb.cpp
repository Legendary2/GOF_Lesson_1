
#include <iostream>

#include "ScreenSingleton.h"

#include "Bomb.h"
#include "MyTools.h"
#include "Colors.h"


using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "*";
}