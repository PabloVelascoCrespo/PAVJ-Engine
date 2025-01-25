#pragma once

#include "tigr.h"
#include <iostream>
#include <string>
//#include "framework.h"

class ENGINE
{
private:
	bool m_isRunning = false;
	Tigr* m_screen;

public:
	bool isRunning();
	void Render();
	void Update();

	void Log(const char* text);

	bool Init();
	bool Input();
	bool Quit();
};

