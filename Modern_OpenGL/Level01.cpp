#include "Level01.h"
#include "Skybox.h"
#include "EngineCore.h"
#include "Cube.h"
#include "Level01Prefab.h"
#include "Enemy.h"
#include <gtc/matrix_transform.inl>

Level01::Level01()
{
	name = "Level01";
}

Level01::~Level01()
{
	delete skybox;
	delete player;
}

void Level01::Load()
{
	SetupLight();

	skybox = new Skybox();
	player = new Player(vec3(12, 3, -2));
	gameManager = GameManager::Instance;

	gameobjects.push_back(new Cube(vec3(0, 2, 0)));
	gameobjects[0]->SetColliderActive(true);
	gameobjects[0]->SetRigidbodyActive(true);
	gameobjects.push_back(new Cube(vec3(0, -0.51, 0)));
	gameobjects[1]->transform.setLocalScale(vec3(50, 1, 50));
	gameobjects[1]->SetColliderActive(true);

	//gameobjects.push_back(new Cube(vec3(0.5f, 93, 0)));
	//gameobjects[2]->SetColliderActive(true);
	//gameobjects[2]->SetRigidbodyActive(true);
	//gameobjects.push_back(new Cube(vec3(0, 104, 0.5f)));
	//gameobjects[3]->SetColliderActive(true);
	//gameobjects[3]->SetRigidbodyActive(true);
	//gameobjects.push_back(new Cube(vec3(0.5f, 109, 0.5f)));
	//gameobjects[4]->SetColliderActive(true);
	//gameobjects[4]->SetRigidbodyActive(true);
	//gameobjects.push_back(new Cube(vec3(-0.5f, 107, 0)));
	//gameobjects[5]->SetColliderActive(true);
	//gameobjects[5]->SetRigidbodyActive(true);

	gameobjects.push_back(new Cube(vec3(8, 0.5, 0)));
	gameobjects[2]->SetColliderActive(true);
	gameobjects.push_back(new Cube(vec3(8, 0.5, -8)));
	gameobjects[3]->SetColliderActive(true);
	gameobjects.push_back(new Cube(vec3(8, 0.5, 3.5)));
	gameobjects[4]->SetColliderActive(true);
	gameobjects.push_back(new Cube(vec3(8, 0.5, 4.5)));
	gameobjects[5]->SetColliderActive(true);
	gameobjects.push_back(new Cube(vec3(8, 1.5, 4)));
	gameobjects[6]->SetColliderActive(true);


	gameobjects.push_back(new Level01Prefab(vec3(0, 0, 0)));
	gameobjects.push_back(new Level01Prefab(vec3(0, -1, 1)));
	gameobjects[8]->transform.setLocalScale(vec3(1.5, 3, 1.5));

	GameManager::Instance->UpdateEnemyCount();

	for (int i = 0; i < GameManager::Instance->enemyCount; i++) {
		enemyobjects.push_back(new Enemy(vec3(-rand() % 10, 0, (rand() % 10) - 8)));
	}

	//enemyobjects.push_back(new Enemy(vec3(0, 0, 0)));
	//enemyobjects.push_back(new Enemy(vec3(-3, 0, -5)));
	//enemyobjects.push_back(new Enemy(vec3(-6, 0, -8)));
	//enemyobjects.push_back(new Enemy(vec3(-9, 0, -3)));
	//enemyobjects.push_back(new Enemy(vec3(-4, 0, -1)));
	//enemyobjects.push_back(new Enemy(vec3(-9, 0, 1)));
	//enemyobjects.push_back(new Enemy(vec3(-7, 0, 3)));
	//enemyobjects.push_back(new Enemy(vec3(-1.5, 0, 5)));

	loaded = true;
}

void Level01::Update()
{
	SetupLight();
	skybox->Update(player->transform.getLocalPosition());
	player->Update();

	if (gameManager->levelStarted && !gameManager->levelCompleted)
	{
		gameManager->GameManagerUpdate();

		for each (Enemy * e in enemyobjects)
		{
			e->EnemyUpdate();
		}
	}
	else
	{
		// Load sequence

	}



	if (Input::getKeyDown('P'))
		sceneDebug = !sceneDebug;

	if (Input::getKeyDown(' '))
		gameManager->levelStarted = true;

	if (sceneDebug)
	{
		if (Input::getKey('I')) player->wp_up -= vec3(0.002F);
		if (Input::getKey('L')) player->wp_right += vec3(0.002F);
		if (Input::getKey('J')) player->wp_right -= vec3(0.002F);
		if (Input::getKey('K')) player->wp_up += vec3(0.002F);
		if (Input::getKey('U')) player->wp_forward += vec3(0.002F);
		if (Input::getKey('O')) player->wp_forward -= vec3(0.002F);

		if (Input::getKey('M')) gameobjects[0]->transform.setLocalPosition(vec3(0,100,0));

		if (Input::getKey('V')) SetupLight();
		if (Input::getKey('B')) DisableLight();


		if (Input::getKey('F'))	enemyobjects[0]->Die();


		debugLine1 = "x: " + std::to_string(player->transform.getLocalPosition().x)
			+ " y: " + std::to_string(player->transform.getLocalPosition().y)
			+ " z: " + std::to_string(player->transform.getLocalPosition().z);

		debugLine2 = "wp_up: " + std::to_string(player->wp_up.x)
			+ " wp_right: " + std::to_string(player->wp_right.x)
			+ " wp_forward: " + std::to_string(player->wp_forward.x);

		debugLine3 = "deltaTime: " + std::to_string(Time::deltaTime())
			+ " (" + std::to_string(1 / Time::deltaTime())
			+ "fps)";


		debugLine4 = "cube1 vel x: " + std::to_string(gameobjects[0]->rigidbody->velocity.x)
			+ " y: " + std::to_string(gameobjects[0]->rigidbody->velocity.y)
			+ " z: " + std::to_string(gameobjects[0]->rigidbody->velocity.z);

		debugLine5 = "cube1 pos x: " + std::to_string(gameobjects[0]->transform.getLocalPosition().x)
			+ " y: " + std::to_string(gameobjects[0]->transform.getLocalPosition().y)
			+ " z: " + std::to_string(gameobjects[0]->transform.getLocalPosition().z);

		debugLine6 = "fov: " + std::to_string(player->camera.fov);

		debugLine7 = "mouse x: " + std::to_string(Input::getMouseDelta().x);
		debugLine8 = "mouse y: " + std::to_string(Input::getMouseDelta().y);

		debugLine9 = "Score: " + std::to_string(GameManager::Instance->playerPoints);;

	}

	Draw();
}

void Level01::Draw()
{
	Scene::Draw();
	graphicsHandler->drawCollage();
	DrawProgressBar(1 - (gameManager->timeElapsed / gameManager->totalTime));
}

void Level01::DrawProgressBar(float timeRemaining)
{
	float paddingLeft = 100;
	float paddingRight = 100;
	float paddingTop = 50;
	float height = 30;
	float xExtend = (screenWidth - paddingLeft - paddingRight) * timeRemaining;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glm::mat4 orth = glm::ortho(0.0f, (float)screenWidth, (float)screenHeight, 0.0f);
	glMultMatrixf(&(orth[0][0]));

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor4f(0.8f - (timeRemaining * 0.8f), (timeRemaining * 0.8f), 0.1f, 0.8f);

	glBegin(GL_QUADS);                      
	glVertex2f(paddingLeft + xExtend, paddingTop); // top right
	glVertex2f(paddingLeft, paddingTop); // top left
	glVertex2f(paddingLeft, paddingTop + height); // bottom left
	glVertex2f(paddingLeft + xExtend, paddingTop + height); // bottom right

	glEnd();

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glDisable(GL_BLEND);

}

void Level01::DrawScoreText(int currentScore, int targetScore)
{

}
