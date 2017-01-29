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
	difficultyText = difficultyEasy;

	SetupLight();

	//skybox = new Skybox();

	loaded = true;
}

void MainMenu::Update()
{
	//gluLookAt(0, 0, 0, 1, 0, 0, 0, 1, 0);

	//skybox->Update(vec3(0,0,0));
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

	UI::BuildFont(-26);

	glRasterPos2f(640, 300);
	UI::glPrint("Start Game");
	glRasterPos2f(640, 350);
	UI::glPrint(difficultyText.c_str());
	glRasterPos2f(640, 400);
	UI::glPrint("Credits:");
	glRasterPos2f(640, 450);
	UI::glPrint("Quit");

	if (creditsEnabled) {
		for (int i = 0; i < 4; i++)
		{
			glRasterPos2f(debugStringXPos, (i + 1) * 18);
			PrintCredits(i + 1);
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

			if (difficultyText == difficultyEasy) 
			{
				difficultyText = difficultyMed;
				GameManager::Instance->diff = medium;
			}
			else if (difficultyText == difficultyMed)
			{
				difficultyText = difficultyHard;
				GameManager::Instance->diff = hard;
			}
			else
			{
				difficultyText = difficultyEasy;
				GameManager::Instance->diff = easy;
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

void MainMenu::PrintCredits(int id)
{
	UI::BuildFont(-17);

	switch (id)
	{
	case 1:
		UI::glPrint(creditLine1.c_str());
		break;
	case 2:
		UI::glPrint(creditLine2.c_str());
		break;
	case 3:
		UI::glPrint(creditLine3.c_str());
		break;
	case 4:
		UI::glPrint(creditLine4.c_str());
		break;
	default:
		break;
	}
}