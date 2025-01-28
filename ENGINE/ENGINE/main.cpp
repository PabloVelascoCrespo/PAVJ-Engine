#include "ENGINE.h"

int main()
{
	ENGINE engine;
	if (!engine.Init())
		return -1;
	float desiredFPS = 1.0 / 30;

	while (engine.isRunning())
	{
		float elapsedSeconds = engine.Wait(desiredFPS);
		float fps = 1.0 / elapsedSeconds;

		engine.Clear();
		engine.Print(engine.toString(fps));
		engine.Update();
	}
	engine.Quit();
}