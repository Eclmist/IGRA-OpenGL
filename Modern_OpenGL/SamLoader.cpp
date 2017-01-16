#include "SamLoader.h"
#include "Mesh.h"


using namespace std;

void SamLoader::LoadModel(const char* fileName, Vertex* &vertexPointer, int & numVertices) {

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> vertexNormals;
	std::vector<int> faces;
	std::vector<glm::vec2> texturesCoords;

	ifstream infile(fileName);

	if (!infile)
	{
		cerr << "Cannot open " << fileName << endl;
		exit(1);
	}

	string line;
	while (getline(infile, line))
	{
		if (line.substr(0, 2) == "v ")
		{
			istringstream iss(line.substr(2));
			glm::vec3 v;
			iss >> v.x;
			iss >> v.y;
			iss >> v.z;

			vertices.push_back(v);
		}
		else if (line.substr(0, 2) == "vt")
		{
			istringstream iss(line.substr(3));
			glm::vec2 textCoords;
			iss >> textCoords.x;
			iss >> textCoords.y;

			texturesCoords.push_back(textCoords);
		}
		else if (line.substr(0, 2) == "vn")
		{
			istringstream iss(line.substr(3));
			glm::vec3 normals;
			iss >> normals.x;
			iss >> normals.y;
			iss >> normals.z;

			vertexNormals.push_back(normals);
		}
		else if (line.substr(0, 2) == "f ")
		{
			int x1, t1, n1, x2, t2, n2, x3, t3, n3;

			istringstream iss(line.substr(2));

			iss >> x1;
			iss >> t1;
			iss >> n1;

			iss >> x2;
			iss >> t2;
			iss >> n2;

			iss >> x3;
			iss >> t3;
			iss >> n3;

			x1--;
			t1--;
			n1--;

			x2--;
			t2--;
			n2--;

			x3--;
			t3--;
			n3--;

			faces.push_back(x1);
			faces.push_back(t1);
			faces.push_back(n1);

			faces.push_back(x2);
			faces.push_back(t2);
			faces.push_back(n2);

			faces.push_back(x3);
			faces.push_back(t3);
			faces.push_back(n3);
		}
	}

	numVertices = faces.size() / 3;

	vector<Vertex> verticesArray;

	for (int i = 0; i < faces.size(); i += 3) {
		verticesArray.push_back(Vertex(vertices[faces[i]], texturesCoords[faces[i + 1]], vertexNormals[faces[i + 2]]));
	}

	vertexPointer = new Vertex[faces.size()/3];

	memcpy(vertexPointer, &verticesArray[0], sizeof(Vertex)*verticesArray.size());

	//vertexPointer = &verticesArray[0];
}