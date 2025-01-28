// PABLO VELASCO CRESPO
// - https://github.com/PabloVelascoCrespo 
// - public domain

#include "ENGINE.h"

float ENGINE::GetElapsedSeconds() const
{
	return tigrTime();
}

bool ENGINE::isRunning()
{
	m_isRunning = !tigrClosed(m_Screen);
	return m_isRunning;
}

void ENGINE::Clear()
{
	tigrClear(m_Screen, tigrRGB(0x80, 0x90, 0xa0));
}

void ENGINE::Update()
{
	tigrUpdate(m_Screen);
}

void ENGINE::Log(std::string _text)
{
	puts(_text.c_str());
}

void ENGINE::Print(std::string _text)
{
	tigrPrint(m_Screen, tfont, 0,0,tigrRGB(0,0,0), _text.c_str());
}

float ENGINE::Wait(float _s)
{
	float waitedTime = 0.0f;
	while (waitedTime <= _s)
	{
		waitedTime += GetElapsedSeconds();
	}
	return waitedTime;
}

bool ENGINE::Init()
{
	m_Screen = tigrWindow(320, 240, "Hello", 0);
	if (m_Screen == nullptr) return false;
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
	tigrFree(m_Screen);
	m_Screen = nullptr;
	return true;
}
