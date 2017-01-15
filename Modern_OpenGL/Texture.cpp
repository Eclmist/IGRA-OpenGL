#include "Texture.h"
#include <cassert>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <gl/glu.h>

// Code change required for non square atlases
Texture::Texture(const std::string & filename, const int rows) : rows(rows)
{
	int width, height, numComponents;

	auto * data = stbi_load(filename.c_str(), &width, &height, &numComponents, 4);

	if (data == nullptr)
		std::cout << "Image data \"" << filename << "\" failed to load" << std::endl;
	else
		std::cout << "Image data \"" << filename << "\" loaded" << std::endl;

	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
	//	width, height, GL_RGB, GL_UNSIGNED_BYTE, data);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);
}

Texture::~Texture()
{
	glDeleteTextures(1, &texture);
}

void Texture::Bind()
{
	//assert(unit >= 0 && unit <= 31);

	//glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, texture);
}

glm::vec2 Texture::getTexCoordOffset(int index)
{
	glm::vec2 coord;

	double column = index % rows;
	coord.x = column / rows;

	double tempRow = floor(index / rows);
	coord.y = tempRow / rows;

	return coord;
}
