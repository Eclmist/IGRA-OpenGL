#pragma once
#include "Scene.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	Scene * GetActiveScene();

	bool LoadScene(std::string name);

private:
	Scene * activeScene;
	std::vector<Scene*> loadedScene;
};

