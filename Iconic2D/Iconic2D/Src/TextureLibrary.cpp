#include "TextureLibrary.h"

#include <gl_core_4_4.h>
#include <glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TextureLibrary::TextureLibrary()
{
}


TextureLibrary::~TextureLibrary()
{
	for (std::map<const char*, Texture*>::iterator iter = m_textures.begin(); iter != m_textures.end(); iter++)
	{
		//delete iter->second;
	}
}

Texture* TextureLibrary::LoadTexture(const char* a_dir)
{
	if (m_textures.find(a_dir) != m_textures.end())
	{
		return m_textures[a_dir];
	}

	int imageWidth = 0, imageHeight = 0, imageFormat = 0;
	unsigned char* data = stbi_load(a_dir, &imageWidth, &imageHeight, &imageFormat, STBI_default);

	if (data == nullptr)
		throw(std::string("Failed to load texture"));

	unsigned int texture;

	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	if (imageFormat == 3)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	else if (imageFormat == 4)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);

	Texture* newTexture = new Texture(imageWidth, imageHeight, texture);
	m_textures.insert(std::make_pair(a_dir, newTexture));

	return newTexture;
}