#include "GraphicsHandler.h"

std::vector<Drawable*> GraphicsHandler::theAlmightyCollage;

void GraphicsHandler::drawCollage()
{

	for (int i = 0; i < theAlmightyCollage.size(); i++)
	{
		theAlmightyCollage[i]->draw();
	}
}

void GraphicsHandler::addPainting(Drawable * painting)
{
	theAlmightyCollage.push_back(painting);
}

void GraphicsHandler::burnPainting(Drawable * painting)
{

	for (int i = 0; i < theAlmightyCollage.size(); i++)
	{
		if (theAlmightyCollage[i] == painting)
		{
			theAlmightyCollage.erase(theAlmightyCollage.begin() + i);
			return;
		}
	}
}

void GraphicsHandler::reset()
{
	//TODO: FIX
	//for (auto it = theAlmightyCollage.begin(); it != theAlmightyCollage.end(); ++it) {
	//	delete *it;
	//}
	theAlmightyCollage.clear();
}
