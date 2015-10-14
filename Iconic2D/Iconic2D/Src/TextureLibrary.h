#pragma once
#include <map>

class Texture;

class TextureLibrary
{
private:
	std::map<const char*, Texture*> m_textures;

public:
	
	TextureLibrary();
	~TextureLibrary();

	Texture* LoadTexture(const char* a_dir);
};

class Texture
{
private:
	unsigned int m_width, m_height, m_ID;

public:
	Texture(unsigned int a_width, unsigned int a_height, unsigned int a_ID) : m_width(a_width), m_height(a_height), m_ID(a_ID) {}
	~Texture();

	unsigned int GetWidth()		{ return m_width; }
	unsigned int GetHeight()	{ return m_height; }
	unsigned int GetID()		{ return m_ID; }
};

struct Material
{
	unsigned int program;
	Texture* texture;
};