#include "Drawable.h"
#include "GraphicsHandler.h"
#include <iostream>

Drawable::Drawable()
{
	GraphicsHandler::addPainting(this);
}

Drawable::~Drawable()
{
	std::cout << "destroyed ";
	//GraphicsHandler::burnPainting(this);
}
