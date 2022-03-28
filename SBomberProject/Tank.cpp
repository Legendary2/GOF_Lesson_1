
#include <iostream>

#include "Tank.h"
#include "MyTools.h"

using namespace std;

bool Tank::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void Tank::Draw() const
{
	ScreenSingletone::getInstance().SetColor(CC_Brown);
	ScreenSingletone::getInstance().GotoXY(x, y - 3);
	cout << "    #####";
	ScreenSingletone::getInstance().GotoXY(x-2, y - 2);
	cout << "#######   #";
	ScreenSingletone::getInstance().GotoXY(x, y - 1);
	cout << "    #####";
	ScreenSingletone::getInstance().GotoXY(x,y);
	cout << " ###########";
}