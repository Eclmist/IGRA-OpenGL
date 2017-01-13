#pragma once
#include <vector>
#include "Drawable.h"

class GraphicsHandler
{
public:

	static void drawCollage();

	static void addPainting(Drawable *);

	static void burnPainting(Drawable *);

private:
	static std::vector<Drawable*> theAlmightyCollage;

};