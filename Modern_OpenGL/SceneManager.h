#pragma once
#include "Scene.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	Scene * GetActiveScene();
	static SceneManager* Instance;

	static SceneManager* Instance;

	bool LoadScene(std::string name);

private:
	Scene * activeScene;
	std::vector<Scene*> loadedScene;
};

