#pragma once

#include <cstdint>
#include "Colors.h"

//код из лекции:

class Screen {
public:
	virtual ~Screen() = default;
	virtual void ClrScr() = 0;
	virtual void GotoXY(double x, double y) = 0;
	virtual uint16_t GetMaxX() = 0;
	virtual uint16_t GetMaxY() = 0;
	virtual void SetColor(ConsoleColor color) = 0;
};

class ScreenSingleton : public Screen {
public:
	static Screen& getInstance();

	virtual void ClrScr() override;
	virtual void GotoXY(double x, double y) override;
	virtual uint16_t GetMaxX() override;
	virtual uint16_t GetMaxY() override;
	virtual void SetColor(ConsoleColor color) override;

private:
	friend Screen& getInternalInstance();

	ScreenSingleton() = default;
	~ScreenSingleton() = default;
	ScreenSingleton(const ScreenSingleton& root) = delete;
	ScreenSingleton& operator=(const ScreenSingleton&) = delete;
	ScreenSingleton(ScreenSingleton&& root) = delete;
	ScreenSingleton& operator=(ScreenSingleton&&) = delete;
};