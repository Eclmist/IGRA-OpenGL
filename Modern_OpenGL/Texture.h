#pragma once
#include <string>
#include <Windows.h>
#include <gl/gl.h>
#include <detail/type_vec2.hpp>

class Texture
{
public:
	Texture(const std::string&, const int rows = 1);
	virtual ~Texture();

	void Bind();

	glm::vec2 getTexCoordOffset(int index);
	int rows;

private:
	GLuint texture;
};

