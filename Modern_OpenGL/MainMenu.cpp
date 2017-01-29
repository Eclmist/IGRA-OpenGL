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
}

void MainMenu::Load()
{
	difficulty = difficultyEasy;

	SetupLight();

	skybox = new Skybox();

	loaded = true;
}

void MainMenu::Update()
{
	//gluLookAt(0, 0, 0, 1, 0, 0, 0, 1, 0);

	skybox->Update(vec3(0,0,0));
	CheckInput();
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
	UI::glPrint(difficulty.c_str());
	glRasterPos2f(640, 400);
	UI::glPrint("Credits:");
	glRasterPos2f(640, 450);
	UI::glPrint("Quit");

	if (creditsEnabled) {
		for (int i = 0; i < 12; i++)
		{
			glRasterPos2f(debugStringXPos, (i + 1) * 18);
			PrintCredit(i + 1);
		}
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void MainMenu::CheckInput() {
	if (Input::getMouseDown(0)) {

		if (Input::getMousePosition().x >= 635 &&
			Input::getMousePosition().x <= 745 &&
			Input::getMousePosition().y >= 280 &&
			Input::getMousePosition().y <= 300) 
		{
			SceneManager::Instance->LoadScene("Level01");
		}

		if (Input::getMousePosition().x >= 635 &&
			Input::getMousePosition().x <= 800 &&
			Input::getMousePosition().y >= 330 &&
			Input::getMousePosition().y <= 350) 
		{
			//make enum
			if (difficulty == difficultyEasy) 
			{
				difficulty = difficultyMed;
				diff = medium;
			}
			else if (difficulty == difficultyMed)
			{
				difficulty = difficultyHard;
				diff = hard;
			}
			else
			{
				difficulty = difficultyEasy;
				diff = easy;
			}
		}

		if (Input::getMousePosition().x >= 635 &&
			Input::getMousePosition().x <= 715 &&
			Input::getMousePosition().y >= 380 &&
			Input::getMousePosition().y <= 400) 
		{
			creditsEnabled = true;
		}

	}
}