#include "ENGINE.h"
#include "ECS\ecs.hh"
#include "LUA\minilua.h"
#include "Sprite.h"

int main()
{
	ENGINE engine;
	if (!engine.Init())
		return -1;
	
	Sprite sprite("../ART/Sprites/mario.png");
	std::string sprite_xml;
	sprite.Save(sprite_xml);

	float desiredFPS = 1.0f / 30;
	float currentTime = engine.Time();


	while (engine.isRunning())
	{
		float elapsedSeconds = engine.Time() - currentTime;
		currentTime = engine.Time();
		float fps = 1.0f / elapsedSeconds;
		engine.Wait(desiredFPS);
		engine.Clear();

		sprite.Draw(engine.getScreen());

		engine.Print(sprite_xml);
		//engine.Print(engine.toString(fps));

		engine.Update();
	}
	engine.Quit();
}