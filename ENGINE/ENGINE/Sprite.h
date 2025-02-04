#pragma once
#include <string>
#include <sstream>
#include "tigr.h"
#include "pugixml.hpp"

class Sprite
{
private:
	Tigr* m_Image = nullptr;
	std::string m_sFile;
public:
	/**
	 * @brief Constructor
	*/
	Sprite();

	/**
	 * @brief Constructor
	 * @param _file File of the new Sprite
	*/
	Sprite(const std::string& _file);

	/**
	 * @brief Destructor
	*/
	~Sprite();

	/**
	 * @brief Saves the Sprite into a File
	 * @return The route in which the Sprite has been saved
	*/
	bool Save(std::string& _out_);

	/**
	 * @brief Loads a new Sprite from a File
	 * @param _file Rute of the File
	 * @return The loaded Sprite
	*/
	static bool Load(Sprite& _obj_, const std::string& _file);

	/**
	 * @brief Draws the Sprite in the Screen
	 * @param _x Position in the horizontal axis
	 * @param _y Position in the vertical axis
	*/
	void Draw(Tigr *_window) const ;
};

