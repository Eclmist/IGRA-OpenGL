#include "Scene.h"
#include "SceneManager.h"
#include "EngineCore.h"
#include "Physics.h"
#include <gtc/matrix_transform.inl>
#include <glm.hpp>

using namespace glm;

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
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glm::mat4 orth = glm::ortho(0.0f, (float)screenWidth, (float)screenHeight, 0.0f );
	glMultMatrixf(&(orth[0][0]));

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);

	for (int i = 0; i < 12; i++)
	{
		glRasterPos2f(debugStringXPos, (i+1) * 18);
		PrintLine(i + 1);
	}
	
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);



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
	case 5:
		UI::glPrint(debugLine5.c_str());
		break;
	case 6:
		UI::glPrint(debugLine6.c_str());
		break;
	case 7:
		UI::glPrint(debugLine7.c_str());
		break;
	case 8:
		UI::glPrint(debugLine8.c_str());
		break;
	case 9:
		UI::glPrint(debugLine9.c_str());
		break;
	case 10:
		UI::glPrint(debugLine10.c_str());
		break;
	case 11:
		UI::glPrint(debugLine11.c_str());
		break;
	case 12:
		UI::glPrint(debugLine12.c_str());
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

void Scene::SetupLight()
{
	glShadeModel(GL_SMOOTH);
	GLfloat LightAmbient[] = { 0.21, 0.112, 0.05, 1 };
	GLfloat LightDiffuse[] = { 1, 1, 1, 1 };
	GLfloat LightSpecular[] = { 1, 0, 0, 1 };
	GLfloat LightPosition[] = { 5, 30, -2, 0 }; 
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glEnable(GL_LIGHT0);
}

void Scene::DisableLight()
{
	glDisable(GL_LIGHT0);
}
