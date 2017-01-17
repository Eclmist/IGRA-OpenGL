#include "Scene.h"
#include "SceneManager.h"
#include "EngineCore.h"
#include "Physics.h"
Scene::Scene()
{
	graphicsHandler = new GraphicsHandler();
}

Scene::~Scene()
{
	delete graphicsHandler;
}

void Scene::Unload()
{
	Physics::Reset();
	GraphicsHandler::reset();

	for (auto it = gameobjects.begin(); it != gameobjects.end(); ++it) {
		delete *it;
	}
	gameobjects.clear();
}

void Scene::Draw()
{
	if (sceneDebug)
	{
		DrawDebugInfo();
	}
}

void Scene::DrawDebugInfo()
{
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.0f);              // Move One Unit Into The Screen
	glColor3f(1.0, 1.0, 1.0);
	// Position The Text On The Screen


	for (int i = 0; i < 4; i++)
	{
		glRasterPos2f(debugStringXPos, debugStringYPos - i * 0.02F);
		PrintLine(i + 1);
	}
	
	glPopMatrix();

	DrawAxisSystem();
}

void Scene::PrintLine(int id)
{
	switch (id)
	{
	case 1:
		UI::glPrint(debugLine1.c_str());
		break;
	case 2:
		UI::glPrint(debugLine2.c_str());
		break;
	case 3:
		UI::glPrint(debugLine3.c_str());
		break;
	case 4:
		UI::glPrint(debugLine4.c_str());
		break;

	default:
		break;
	}
}

void Scene::DrawAxisSystem()
{
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 10, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, -10);
	glColor3f(1, 1, 1);

	glEnd();
}
