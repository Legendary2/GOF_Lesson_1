#include <iostream>
#include <stdint.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <fstream>
#include <string>

#include "ScreenSingleton.h"
#include "MyTools.h"
#include "Colors.h"



Screen& getInternalInstance() {
    static ScreenSingleton theInstance;
    return theInstance;
}
//Task 2:
class FileLoggingSingletonProxy : public Screen {
public:
    virtual void ClrScr() override {
        MyTools::WriteToLog("ClrScr invoke begin");
        getInternalInstance().ClrScr();
        MyTools::WriteToLog("ClrScr invoke end");
    }
    virtual void GotoXY(double x, double y) override {

        MyTools::WriteToLog("GotoXY invoke begin");
        getInternalInstance().GotoXY(x, y);
        MyTools::WriteToLog("GotoXY invoke end");
    }
    virtual uint16_t GetMaxX() override {
        return getInternalInstance().GetMaxX();
    }

    virtual uint16_t GetMaxY() override {
        return getInternalInstance().GetMaxY();
    }
    virtual void SetColor(ConsoleColor color) override {
        return getInternalInstance().SetColor(color);
    }

    static Screen& getInstance() {
        static FileLoggingSingletonProxy theInstance;
        return theInstance;
    }

private:
    FileLoggingSingletonProxy() {
    }

    ~FileLoggingSingletonProxy() {
    }

    FileLoggingSingletonProxy(const FileLoggingSingletonProxy& root) = delete;
    FileLoggingSingletonProxy& operator=(const FileLoggingSingletonProxy&) = delete;
    FileLoggingSingletonProxy(FileLoggingSingletonProxy&& root) = delete;
    FileLoggingSingletonProxy& operator=(FileLoggingSingletonProxy&&) = delete;
};

void ScreenSingleton::ClrScr() {
    system("cls");
}

void ScreenSingleton::GotoXY(double x, double y) {
    const COORD cc = { short(x), short(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cc);
}

uint16_t ScreenSingleton::GetMaxX() {
    HANDLE hWndConsole;
    if (hWndConsole = GetStdHandle(-12)) {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) {
            return consoleInfo.srWindow.Right;
            int height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
        }
    }

    return 0;
}

uint16_t ScreenSingleton::GetMaxY() {
    HANDLE hWndConsole;
    if (hWndConsole = GetStdHandle(-12)) {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo)) {
            return consoleInfo.srWindow.Bottom;
        }
    }

    return 0;
}

void ScreenSingleton::SetColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

Screen& ScreenSingleton::getInstance() {
    return FileLoggingSingletonProxy::getInstance();
}