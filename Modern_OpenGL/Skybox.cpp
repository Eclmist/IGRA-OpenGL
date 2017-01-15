#include "Skybox.h"



Skybox::Skybox()
{
	texture = new Texture("resources/skybox-DEBUG.png", 4);
	transform.setLocalPosition(vec3(0,0,0));
	setupMeshInformation();
}


Skybox::~Skybox()
{
	delete mesh;
	delete[] vertexArr;
	delete texture;

}

void Skybox::Update(vec3 cameraPos)
{
	transform.setLocalPosition(cameraPos);
}

#define r 100
#define textureIndex_top 1
#define textureIndex_bottom 9
#define textureIndex_left 4
#define textureIndex_right 6
#define textureIndex_front 5
#define textureIndex_back 7

void Skybox::setupMeshInformation()
{
	Vertex verts[] =
	{
		// TOP
		Vertex(vec3(r,r,r), vec2(0.25, 0) + vec2(0.25, 0.25), vec3(0,1,0)),
		Vertex(vec3(-r,r,r), vec2(0.25, 0) + vec2(0.0, 0.25), vec3(0,1,0)),
		Vertex(vec3(-r,r,-r), vec2(0.25, 0) + vec2(0.0, 0.0), vec3(0,1,0)),
		Vertex(vec3(r,r,-r), vec2(0.25, 0) + vec2(0.25, 0.0), vec3(0,1,0)),

		// BOTTOM
		Vertex(vec3(r,-r,-r), texture->getTexCoordOffset(textureIndex_bottom) + vec2(1.0 / texture->rows, 0.0 / texture->rows), vec3(0,-1,0)),
		Vertex(vec3(r,-r,r), texture->getTexCoordOffset(textureIndex_bottom) + vec2(1.0 / texture->rows, 1.0 / texture->rows), vec3(0,-1,0)),
		Vertex(vec3(-r,-r,r), texture->getTexCoordOffset(textureIndex_bottom) + vec2(0.0 / texture->rows, 1.0 / texture->rows), vec3(0,-1,0)),
		Vertex(vec3(-r,-r,-r), texture->getTexCoordOffset(textureIndex_bottom) + vec2(0.0 / texture->rows, 0.0 / texture->rows), vec3(0,-1,0)),

		// BACK
		Vertex(vec3(r,r,-r), texture->getTexCoordOffset(textureIndex_back) + vec2(0.0 / texture->rows, 0.0 / texture->rows), vec3(0,0,1)),
		Vertex(vec3(r,-r,-r), texture->getTexCoordOffset(textureIndex_back) + vec2(0.0 / texture->rows, 1.0 / texture->rows), vec3(0,0,1)),
		Vertex(vec3(-r,-r,-r), texture->getTexCoordOffset(textureIndex_back) + vec2(1.0 / texture->rows, 1.0 / texture->rows), vec3(0,0,1)),
		Vertex(vec3(-r,r,-r), texture->getTexCoordOffset(textureIndex_back) + vec2(1.0 / texture->rows, 0.0 / texture->rows), vec3(0,0,1)),

		// FRONT
		Vertex(vec3(r,r, r), texture->getTexCoordOffset(textureIndex_front) + vec2(1.0 / texture->rows, 0.0 / texture->rows), vec3(0,0,-1)),
		Vertex(vec3(-r,r,r), texture->getTexCoordOffset(textureIndex_front) + vec2(0.0 / texture->rows, 0.0 / texture->rows), vec3(0,0,-1)),
		Vertex(vec3(-r,-r,r), texture->getTexCoordOffset(textureIndex_front) + vec2(0.0 / texture->rows, 1.0 / texture->rows), vec3(0,0,-1)),
		Vertex(vec3(r,-r,r), texture->getTexCoordOffset(textureIndex_front) + vec2(1.0 / texture->rows, 1.0 / texture->rows), vec3(0,0,-1)),

		// RIGHT
		Vertex(vec3(r,r, -r), texture->getTexCoordOffset(textureIndex_right) + vec2(1.0 / texture->rows, 0.0 / texture->rows), vec3(1,0,0)),
		Vertex(vec3(r,r,r), texture->getTexCoordOffset(textureIndex_right) + vec2(0.0 / texture->rows, 0.0 / texture->rows), vec3(1,0,0)),
		Vertex(vec3(r,-r,r), texture->getTexCoordOffset(textureIndex_right) + vec2(0.0 / texture->rows, 1.0 / texture->rows), vec3(1,0,0)),
		Vertex(vec3(r,-r,-r), texture->getTexCoordOffset(textureIndex_right) + vec2(1.0 / texture->rows, 1.0 / texture->rows), vec3(1,0,0)),

		// RIGHT
		Vertex(vec3(-r,r, r), texture->getTexCoordOffset(textureIndex_left) + vec2(1.0 / texture->rows, 0.0 / texture->rows), vec3(-1,0,0)),
		Vertex(vec3(-r,r,-r), texture->getTexCoordOffset(textureIndex_left) + vec2(0.0 / texture->rows, 0.0 / texture->rows), vec3(-1,0,0)),
		Vertex(vec3(-r,-r,-r), texture->getTexCoordOffset(textureIndex_left) + vec2(0.0 / texture->rows, 1.0 / texture->rows), vec3(-1,0,0)),
		Vertex(vec3(-r,-r,r), texture->getTexCoordOffset(textureIndex_left) + vec2(1.0 / texture->rows, 1.0 / texture->rows), vec3(-1,0,0)),
	};

	vertexArr = new Vertex[sizeof(verts) / sizeof(Vertex)];

	memcpy(vertexArr, verts, sizeof(verts));

	numVertices = sizeof(verts) / sizeof(vertexArr[0]);

	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);

}

void Skybox::draw()
{
	if (texture != nullptr)
		texture->Bind();

	glEnable(GL_TEXTURE_2D);
	mesh->Draw(transform);
	glDisable(GL_TEXTURE_2D);
}
