#pragma once

#include <stdint.h>
#include <string>
#include <fstream>

	enum ConsoleColor
	{
		CC_Black = 0,
		CC_Blue,
		CC_Green,
		CC_Cyan,
		CC_Red,
		CC_Magenta,
		CC_Brown,
		CC_LightGray,
		CC_DarkGray,
		CC_LightBlue,
		CC_LightGreen,
		CC_LightCyan,
		CC_LightRed,
		CC_LightMagenta,
		CC_Yellow,
		CC_White
	};

	class ScreenSingletone
	{
	public:
		static ScreenSingletone& getInstance()
		{
			static ScreenSingletone theInstance;
			return theInstance;
		}
		void ClrScr();
		void GotoXY(double x, double y);
		uint16_t GetMaxX();
		uint16_t GetMaxY();
		void SetColor(ConsoleColor color);

	private:
		ScreenSingletone() { }
		ScreenSingletone(const ScreenSingletone& root) = delete;
		ScreenSingletone& operator=(const ScreenSingletone&) = delete;
	};

	//=============================================================================================
	
	class ILogger
	{
		virtual void OpenLogFile(const std::string& FN) = 0;
		virtual void CloseLogFile() = 0;
		virtual std::string GetCurDateTime() = 0;
		virtual void WriteToLog(const std::string& str) = 0;
		virtual void WriteToLog(const std::string& str, int n) = 0;
		virtual void WriteToLog(const std::string& str, double d) = 0;
	};

	class FileLoggerSingletone : public ILogger
	{
	public:
		static FileLoggerSingletone& getInstance()
		{
			static FileLoggerSingletone theInstance;
			return theInstance;
		}
		void OpenLogFile(const std::string& FN)override;
		void CloseLogFile()override;
		std::string GetCurDateTime()override;
		void WriteToLog(const std::string& str)override;
		void WriteToLog(const std::string& str, int n)override;
		void WriteToLog(const std::string& str, double d)override;

	private:

		std::ofstream logOut;

		FileLoggerSingletone() { }
		FileLoggerSingletone(const FileLoggerSingletone& root) = delete;
		FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;
	};
	
	class ProxyLogger : public ILogger
	{
	public:

		static ProxyLogger& getInstance()
		{
			static ProxyLogger theInstance;
			return theInstance;
		}
		void OpenLogFile(const std::string& FN)override;
		void CloseLogFile()override;
		std::string GetCurDateTime()override;
		void WriteToLog(const std::string& str)override;
		void WriteToLog(const std::string& str, int n)override;
		void WriteToLog(const std::string& str, double d)override;

	private:

		uint32_t ProxyloggerEventNum;

		ProxyLogger() :ProxyloggerEventNum(1) {}
		ProxyLogger(const ProxyLogger& root) = delete;
		const ProxyLogger& operator=(const ProxyLogger&) = delete;

	};