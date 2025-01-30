#include "ENGINE.h"
#include "ecs.hh"
#include "pugixml.hpp"

int main()
{
	ENGINE engine;
	if (!engine.Init())
		return -1;
	float desiredFPS = 1.0 / 30;
	float currentTime = engine.Time();
	while (engine.isRunning())
	{
		float elapsedSeconds = engine.Time() - currentTime;
		currentTime = engine.Time();
		float fps = 1.0 / elapsedSeconds;
		engine.Wait(desiredFPS);
		engine.Clear();
		engine.Print(engine.toString(fps));
		engine.Update();
	}
	engine.Quit();
}