#include "Cube.h"

float Cube::radius = 1;

Cube::Cube(vec3 position, bool magical) : magical(magical)
{
	texture = new Texture("resources/Cube1.jpg");
	transform.setLocalPosition(position);
	setupMeshInformation();
	SetupProceduralTex();
}


Cube::~Cube()
{
	delete mesh;
	//delete[] vertexArr; TODO: FIX
	delete texture;
}

#define r radius

void Cube::setupMeshInformation()
{
	SamLoader::LoadModel("resources/model/cube.obj", vertexArr, numVertices);
	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);
}

void Cube::draw()
{
	glEnable(GL_TEXTURE_2D);

	if (!magical)
	{
		if (texture != nullptr)
			texture->Bind();
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
			64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, proceduralTex);
		glTexParameterf(GL_TEXTURE_2D,
			GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D,
			GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D,
			GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D,
			GL_TEXTURE_MIN_FILTER, GL_NEAREST);	}

	glEnable(GL_LIGHTING);

	mesh->Draw(transform);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Cube::SetupProceduralTex()
{
	int nrOfCheckersOnRow = 8;
	float dim = 64.0 / nrOfCheckersOnRow;
	int targetCheckerColor[] = 
	{
		rand() % 128 + 128,
		rand() % 255,
		rand() % 255
	};

	int targetBorderColor[] =
	{
		rand() % 255,
		rand() % 128 + 128,
		rand() % 255
	};


	int red = 0;
	int green = 0;
	int blue = 0;
	for (int i = 0; i<64; i++) 
	{
		for (int j = 0; j<64; j++) 
		{

			// Calculate in which checkerboard
			//rectangle the pixel falls
			int row = (int)(i / dim);
			int col = (int)(j / dim);
			int c = 0;
			if (row % 2 == 0) { // Even rows start with black
				if (col % 2 == 0) {
					// All even column will be black
					red = green = blue = 0;
				}
				else {
					green = targetCheckerColor[1];
					blue = targetCheckerColor[2];
					red = targetCheckerColor[0];
				}
			}
			else {
				// Odd rows start with red
				if (col % 2 == 0) {
					// All even column will be red
					green = targetCheckerColor[1];
					blue = targetCheckerColor[2];
					red = targetCheckerColor[0];
				}
				else {
					red = green = blue = 0;
				}
			}
			// Drawing a green border around the image
			if (i == 0 || i == 63 || j == 0 || j == 63) {
				green = targetBorderColor[1];
				blue = targetBorderColor[2];
				red = targetBorderColor[0];
			}


			proceduralTex[i][j][0] = (GLubyte)red;
			proceduralTex[i][j][1] = (GLubyte)green;
			proceduralTex[i][j][2] = (GLubyte)blue;
		}
	}
	
}
