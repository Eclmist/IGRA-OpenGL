#include "Mesh.h"
#include "Transform.h"
Vertex::Vertex()
{
	position = glm::vec3(0, 0, 0);
	texCoord = glm::vec2(0, 0);
	normal = glm::vec3(0, 0, 0);
}

Vertex::Vertex(glm::vec3 pos, glm::vec2 tex, glm::vec3 n)
{
	position = pos;
	texCoord = tex;
	normal = n;
}

Vertex::~Vertex()
{
}

Mesh::Mesh()
{
}

Mesh::Mesh(Vertex* vertices, unsigned long numVertices, RenderMode renderMode) : 
	vertices(vertices), numVertices(numVertices), renderMode(renderMode)
{
	
}


Mesh::~Mesh()
{
	delete[] vertices;
}

void Mesh::Draw(Transform transform, bool useDefaultMaterial)
{

	glPushMatrix();
	glTranslatef(transform.getLocalPosition().x, transform.getLocalPosition().y, transform.getLocalPosition().z);
	glRotatef(transform.getRotation().z, 0, 0, 1);
	glRotatef(transform.getRotation().y, 0, 1, 0);
	glRotatef(transform.getRotation().x, 1, 0, 0);
	glScalef(transform.getLocalScale().x, transform.getLocalScale().y, transform.getLocalScale().z);

	if (useDefaultMaterial)
	{
		GLfloat white[] = { 1, 1, 1, 0 };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
	}

	if (renderMode == TRIANGLES)
	{
		assert(numVertices % 3 == 0 && "NumVertices must be a multiple of 3 for triangles");
		glBegin(GL_TRIANGLES);
	}
	else
	{
		assert(numVertices % 4 == 0 && "NumVertices must be a multiple of 4 for quads");
		glBegin(GL_QUADS);
	}

	for (int i = 0; i < numVertices; i++)
	{
		glColor3f(1,1,1);
		glNormal3f(vertices[i].normal.x, vertices[i].normal.y, vertices[i].normal.z);
		glTexCoord2f(vertices[i].texCoord.x, vertices[i].texCoord.y);
		glVertex3f(vertices[i].position.x, vertices[i].position.y, vertices[i].position.z);
	}

	glEnd();
	glPopMatrix();
}
