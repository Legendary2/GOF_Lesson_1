
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"
#include <chrono>
#include <thread>

using namespace std;

//========================================================================================================================

int main(void)
{
    std::this_thread::sleep_for(500ms);
    ProxyLogger::getInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

       ScreenSingletone::getInstance().ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    ProxyLogger::getInstance().CloseLogFile();

    return 0;
}