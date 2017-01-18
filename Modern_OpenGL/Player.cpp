#include "Player.h"
#include "Input.h"
#include "Rigidbody.h"
#include "Time.h"

Player::Player(vec3 pos)
{
	transform.setLocalPosition(pos);
	transform.setLocalScale(vec3(1, 2, 1));
	SetColliderActive(true);
	SetRigidbodyActive(true);
	weapon.transform.setLocalScale(vec3(0.2775F));
}


Player::~Player()
{
}

void Player::Update()
{

	Move();

	camera.UpdateCamera(transform.getLocalPosition() + vec3(0, 0.65f, 0));
	vec3 weaponTargetPos = camera.pos +
		camera.dir * wp_forward -
		camera.up * wp_up -
		camera.right * wp_right;
	weapon.transform.setLocalPosition(weaponTargetPos);
	weapon.transform.setRotation(vec3(-camera.pitch, -camera.yaw + 90, 0));

}

#define MOVESPEED 4.0f

void Player::Move()
{
	//vec3

	if (Input::getKey(' ')) rigidbody->AddForce(vec3(0,1,0) * vec3(50) * Time::deltaTime());

	vec3 horizontalVelocity;

	if (Input::getKey('W')) horizontalVelocity += (camera.dir * vec3(MOVESPEED) * Time::deltaTime());
	if (Input::getKey('A')) horizontalVelocity += (camera.right * vec3(MOVESPEED) * Time::deltaTime());
	if (Input::getKey('S')) horizontalVelocity += (-camera.dir * vec3(MOVESPEED) * Time::deltaTime());
	if (Input::getKey('D')) horizontalVelocity += (-camera.right * vec3(MOVESPEED) * Time::deltaTime());

	horizontalVelocity.y = 0;

	horizontalVelocity += transform.getLocalPosition();
	transform.setLocalPosition(horizontalVelocity);
}
