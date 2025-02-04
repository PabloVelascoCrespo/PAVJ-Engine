#pragma once

#include "tigr.h"
#include <iostream>
#include <string>
#include <sstream>
#include "framework.h"

class ENGINE
{
private:
	bool m_isRunning = false;
	Tigr* m_Screen = nullptr;

public:

	Tigr* getScreen() const;

	/**
	* Transforms any type to a String
	*/
	template <typename T>
	std::string toString(const T& value)
	{
		std::stringstream ss;
		ss << value;
		return ss.str();
	}

	/**
	 * @brief Ask how much time the Engine has been running
	 * @return the number of seconds the Engine has been running
	*/
	float Time() const;

	/**
	* Checks if the Engine is still running
	* Returns TRUE if it is still running
	* Returns FALSE if it is NOT still running
	*/
	bool isRunning();

	/**
	* Clears bitmap to a color
	*/
	void Clear();

	/**
	* Displays window content on the screen
	*/
	void Update();

	/**
	* Prints a message to the console
	*/
	void Log(std::string _text);

	/**
	* Prints a message to the screen
	*/
	void Print(std::string _text);

	/**
	* Waits the amount of seconds given
	* Returns the amount of seconds waited
	*/
	void Wait(float _s);

	/**
	* Initializes the engine
	*/
	bool Init();
	
	/**
	* TODO
	*/
	bool Input();

	/**
	* Quits the Engine
	*/
	bool Quit();
};
