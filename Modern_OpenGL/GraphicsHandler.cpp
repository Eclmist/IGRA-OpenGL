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
	while (!theAlmightyCollage.empty()) delete theAlmightyCollage.back(), 
		theAlmightyCollage.pop_back();

}
