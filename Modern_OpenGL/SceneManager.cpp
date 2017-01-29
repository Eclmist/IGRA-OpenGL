#include "SceneManager.h"
#include "Level01.h"
#include "MainMenu.h"

SceneManager * SceneManager::Instance;

SceneManager::SceneManager()
{
	Instance = this;
	loadedScene.push_back(new Level01());
	loadedScene.push_back(new MainMenu());
}

SceneManager::~SceneManager()
{
	if (activeScene != nullptr)
		activeScene->Unload();

	for (auto it = loadedScene.begin(); it != loadedScene.end(); ++it) {
		delete *it;
	}

	loadedScene.clear();
}

Scene * SceneManager::GetActiveScene()
{
	return activeScene;
}

bool SceneManager::LoadScene(std::string name)
{
	for (int i = 0; i < loadedScene.size(); i++)
	{
		if (loadedScene[i]->name == name)
		{
			if (activeScene != nullptr)
				activeScene->Unload();
			
			loadedScene[i]->Load();
			activeScene = loadedScene[i];
			return true;
		}
	}

	return false;
}
