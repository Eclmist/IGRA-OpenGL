#include "Cube.h"

float Cube::radius = 1;

Cube::Cube()
{

}

Cube::Cube(vec3 position)
{
	transform.setLocalPosition(position);
	setupMeshInformation();
}


Cube::~Cube()
{
}

#define r radius

void Cube::setupMeshInformation()
{
	Vertex verts[] =
	{
		// TOP
		Vertex(vec3(r,r,-r), vec2(1,1), vec3(0,1,0)),
		Vertex(vec3(-r,r,-r), vec2(0,1), vec3(0,1,0)),
		Vertex(vec3(-r,r,r), vec2(0,0), vec3(0,1,0)),
		Vertex(vec3(r,r,r), vec2(1,0), vec3(0,1,0)),

		// BOTTOM
		Vertex(vec3(r,-r,-r), vec2(1,1), vec3(0,-1,0)),
		Vertex(vec3(r,-r,r), vec2(0,1), vec3(0,-1,0)),
		Vertex(vec3(-r,-r,r), vec2(0,0), vec3(0,-1,0)),
		Vertex(vec3(-r,-r,-r), vec2(1,0), vec3(0,-1,0)),

		// BACK
		Vertex(vec3(r,r,-r), vec2(1,1), vec3(0,0,1)),
		Vertex(vec3(r,-r,-r), vec2(0,1), vec3(0,0,1)),
		Vertex(vec3(-r,-r,-r), vec2(0,0), vec3(0,0,1)),
		Vertex(vec3(-r,r,-r), vec2(1,0), vec3(0,0,1)),

		// FRONT
		Vertex(vec3(r,r, r), vec2(1,1), vec3(0,0,1)),
		Vertex(vec3(-r,r,r), vec2(0,1), vec3(0,0,1)),
		Vertex(vec3(-r,-r,r), vec2(0,0), vec3(0,0,1)),
		Vertex(vec3(r,-r,r), vec2(1,0), vec3(0,0,1)),

		// RIGHT
		Vertex(vec3(r,r, -r), vec2(1,1), vec3(1,0,0)),
		Vertex(vec3(r,r,r), vec2(0,1), vec3(1,0,0)),
		Vertex(vec3(r,-r,r), vec2(0,0), vec3(1,0,0)),
		Vertex(vec3(r,-r,-r), vec2(1,0), vec3(1,0,0)),

		// RIGHT
		Vertex(vec3(-r,r, r), vec2(1,1), vec3(-1,0,0)),
		Vertex(vec3(-r,r,-r), vec2(0,1), vec3(-1,0,0)),
		Vertex(vec3(-r,-r,-r), vec2(0,0), vec3(-1,0,0)),
		Vertex(vec3(-r,-r,r), vec2(1,0), vec3(-1,0,0)),

	};

	vertexArr = new Vertex[sizeof(verts) / sizeof(Vertex)];

	memcpy(vertexArr, verts, sizeof(verts));

	numVertices = sizeof(verts) / sizeof(vertexArr[0]);

	mesh = new Mesh(vertexArr, numVertices, QUADS);

}

void Cube::draw()
{
	mesh->Draw(transform);
}
