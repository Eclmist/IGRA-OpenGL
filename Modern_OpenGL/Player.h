#pragma once
#include "GameObject.h"
#include "Camera.h"
#include <glm.hpp>
#include "Weapon.h"

class Player : public GameObject
{
public:
	Player(vec3 pos = vec3(0,2,0));
	~Player();

	void Update();

	Camera camera = Camera(45, 16 / 9, 0.01, 1000);
	Weapon weapon = Weapon(vec3(0, 0, 0));

	vec3 wp_right = vec3(0.158000F);
	vec3 wp_forward = vec3(0.130002);
	vec3 wp_up = vec3(0.186001F);

private:
	void Move();
};

