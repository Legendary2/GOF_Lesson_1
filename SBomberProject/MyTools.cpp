
#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <time.h> 

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>


#include "MyTools.h"

using namespace std;

    //=============================================================================================
    //реализация singletone из лекции
    void ScreenSingletone::ClrScr()
    {
        system("cls");
    }

    void __fastcall ScreenSingletone::GotoXY(double x, double y)
    {
        const COORD cc = { short(x), short(y) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cc);
    }

    uint16_t ScreenSingletone::GetMaxX()
    {
        HANDLE hWndConsole;
        if (hWndConsole = GetStdHandle(-12))
        {
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
            {
                return consoleInfo.srWindow.Right;
                int height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
            }
        }

        return 0;
    }

    uint16_t ScreenSingletone::GetMaxY()
    {
        HANDLE hWndConsole;
        if (hWndConsole = GetStdHandle(-12))
        {
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
            {
                return consoleInfo.srWindow.Bottom;
            }
        }

        return 0;
    }

    void ScreenSingletone::SetColor(ConsoleColor color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color); // color =  (WORD)((BackgroundColor << 4) | TextColor))
    }

    //реализация Task 1: singletone
    void FileLoggerSingletone::OpenLogFile(const string& FN)
    {
        logOut.open(FN, ios_base::out);
    }

    void FileLoggerSingletone::CloseLogFile()
    {
        if (logOut.is_open())
        {
            logOut.close();
        }
    }

    string FileLoggerSingletone::GetCurDateTime()
    {
        auto cur = std::chrono::system_clock::now();
        time_t time = std::chrono::system_clock::to_time_t(cur);
        char buf[64] = { 0 };
        ctime_s(buf, 64, &time);
        buf[strlen(buf) - 1] = '\0';
        return string(buf);
    }

    void  FileLoggerSingletone::WriteToLog(const string& str)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << endl;
        }
    }

    void FileLoggerSingletone::WriteToLog(const string& str, int n)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << n << endl;
        }
    }

    void FileLoggerSingletone::WriteToLog(const string& str, double d)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << d << endl;
        }
    }
    
    //реализация Task 2*:proxy

    void ProxyLogger::OpenLogFile(const string& FN)
    {
        FileLoggerSingletone::getInstance().OpenLogFile(FN);
    }

    void ProxyLogger::CloseLogFile()
    {
        FileLoggerSingletone::getInstance().CloseLogFile();
    }

    string ProxyLogger::GetCurDateTime()
    {
        FileLoggerSingletone::getInstance().GetCurDateTime();
    }

    void ProxyLogger::WriteToLog(const string& str)
    {
        FileLoggerSingletone::getInstance().WriteToLog(to_string(ProxyloggerEventNum++) + ' ' + str);
    }
    void ProxyLogger::WriteToLog(const string& str, int n)
    {
        FileLoggerSingletone::getInstance().WriteToLog(to_string(ProxyloggerEventNum++) + ' ' + str, n);
    }

    void ProxyLogger::WriteToLog(const string& str, double d)
    {
        FileLoggerSingletone::getInstance().WriteToLog(to_string(ProxyloggerEventNum++) + ' ' + str, d);
    }
    //=============================================================================================