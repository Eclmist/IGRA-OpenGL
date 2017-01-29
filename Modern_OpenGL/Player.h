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
	Weapon weapon = Weapon(vec3(12, 0.5, 1));

	vec3 wp_right = vec3(0.102F);
	vec3 wp_forward = vec3(0.37F);
	vec3 wp_up = vec3(0.138001F);

	vec3 wp_right_sights = vec3(0);
	vec3 wp_forward_sights = vec3(0.196002F);
	vec3 wp_up_sights = vec3(0.106001F);


private:
	void Move();
	void Shoot();
	void DrawCrosshair();
	void ClampVelocity(vec3& velocity);
	bool aimingDownSights;

	vec3 currentAimOffset;
	vec3 shootAnimationVector;

};

