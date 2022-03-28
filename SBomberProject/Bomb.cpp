
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;

void Bomb::Draw() const
{
    ScreenSingletone::getInstance().SetColor(CC_LightMagenta);
    ScreenSingletone::getInstance().GotoXY(x, y);
    cout << "*";
}