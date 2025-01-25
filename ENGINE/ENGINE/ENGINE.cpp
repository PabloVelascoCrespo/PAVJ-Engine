#include "ENGINE.h"

int main()
{
	ENGINE engine;
	if (!engine.Init())
		return -1;

	while (engine.isRunning())
	{
		engine.Render();
		engine.Update();
		//engine.Input();
	}
	engine.Quit();
}

bool ENGINE::isRunning()
{
	m_isRunning = !tigrClosed(m_screen);
	return m_isRunning;
}

void ENGINE::Render()
{
	tigrClear(m_screen, tigrRGB(0x80, 0x90, 0xa0));
}

void ENGINE::Update()
{
	tigrUpdate(m_screen);
}

void ENGINE::Log(const char* text)
{
	puts(text);
}

bool ENGINE::Init()
{
	m_screen = tigrWindow(320, 240, "Hello", 0);
	if (m_screen == nullptr) return false;
	m_isRunning = true;
	return true;
}

bool ENGINE::Input()
{
	// TODO
	return false;
}

bool ENGINE::Quit()
{
	tigrFree(m_screen);
	m_screen = nullptr;
	return true;
}
