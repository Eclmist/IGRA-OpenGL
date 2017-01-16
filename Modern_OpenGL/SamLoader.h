#pragma once

#include <math.h>
#include <stdio.h>
#include <vector>
#include "glm.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

struct Vertex;

class SamLoader {
public:
	static void LoadModel(const char* fileName, Vertex* &vertexPointer, int & numVertices);
};