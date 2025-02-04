#include "Sprite.h"

Sprite::Sprite(const std::string& _file)
{
	m_sFile = _file;
	m_Image = tigrLoadImage(m_sFile.c_str());
}

Sprite::~Sprite()
{
	if (m_Image)
	{
		tigrFree(m_Image);
	}
}

bool Sprite::Save(std::string& _out_)
{
	pugi::xml_document doc;
	pugi::xml_node node = doc.append_child("Sprite");
	node.append_attribute("x").set_value(m_Image->cx);
	node.append_attribute("y").set_value(m_Image->cy);
	node.append_attribute("texture_file").set_value(m_sFile.c_str());

	try
	{
		std::stringstream ss;
		doc.save(ss);
		_out_ = ss.str();
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
	return false;
}

bool Sprite::Load(Sprite& _obj_, const std::string& _file)
{
	try
	{
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_string(_file.c_str());
		if (result)
		{
			_obj_ = Sprite(doc.child("sprite").attribute("texture_file").value());
			_obj_.m_Image->cx = atoi(doc.child("sprite").attribute("x").value());
			_obj_.m_Image->cy = atoi(doc.child("sprite").attribute("y").value());
			return true;
		}
	}
	catch (const std::exception&)
	{
		return false;
	}
	return false;

}

void Sprite::Draw(Tigr* _window) const
{
	int dx = 0, dy = 0;
	int sx = 0, sy = 0;
	int tw = m_Image->w, th = m_Image->w;
	tigrBlit(_window, m_Image, dx, dy, sx, sy, tw, th);
}