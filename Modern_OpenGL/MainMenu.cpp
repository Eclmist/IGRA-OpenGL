#include "MainMenu.h"
#include "Skybox.h"
#include "EngineCore.h"
#include <gtc/matrix_transform.inl>
#include "glm.hpp"

MainMenu::MainMenu()
{
	name = "MainMenu";
}

MainMenu::~MainMenu()
{
	delete skybox;
	delete player;
}

void MainMenu::Load()
{
	SetupLight();

	skybox = new Skybox();
	player = new Player();

	loaded = true;
}

void MainMenu::Update()
{
	//gluLookAt(0, 0, 0, 1, 0, 0, 0, 1, 0);

	skybox->Update(vec3(0,0,0));

	Draw();
}

void MainMenu::Draw()
{
	DrawMainMenu();
	graphicsHandler->drawCollage();
}

void MainMenu::DrawMainMenu() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glm::mat4 orth = glm::ortho(0.0f, (float)screenWidth, (float)screenHeight, 0.0f);
	glMultMatrixf(&(orth[0][0]));

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);

	glRasterPos2f(640, 300);
	UI::glPrint("Start Game");
	glRasterPos2f(640, 350);
	UI::glPrint("Difficulty: Easy");
	glRasterPos2f(640, 400);
	UI::glPrint("Credits:");
	glRasterPos2f(640, 450);
	UI::glPrint("Quit");

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

}