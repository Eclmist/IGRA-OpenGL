#pragma once
#include <Windows.h>
#include <glm.hpp>
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "SamLoader.h"
class Transform;

struct Vertex
{
public:
	Vertex();
	Vertex(glm::vec3 pos, glm::vec2 tex, glm::vec3 n);
	~Vertex();

	glm::vec3 position;
	glm::vec2 texCoord;
	glm::vec3 normal;
};

enum RenderMode
{
	TRIANGLES,
	QUADS
};

class Mesh
{
public:
	Mesh();
	Mesh(Vertex* vertices, unsigned long numVertices, RenderMode renderMode);
	virtual ~Mesh();

	void Draw(Transform transform);

private: 
	Vertex* vertices;
	unsigned long numVertices;

	RenderMode renderMode;
};

