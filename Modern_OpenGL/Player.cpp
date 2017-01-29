#include "Player.h"
#include "Input.h"
#include "Rigidbody.h"
#include "Time.h"
#include <gtc/matrix_transform.inl>
#include "RaycastHit.h"
#include "Physics.h"
#include "Enemy.h"
#include "BoxCollider.h"
#include "GameManager.h"

extern int screenWidth;
extern int screenHeight;


Player::Player(vec3 pos)
{
	transform.setLocalPosition(pos);
	transform.setLocalScale(vec3(1, 2, 1));
	SetColliderActive(true);
	SetRigidbodyActive(true);
}


Player::~Player()
{
}

void Player::Update()
{
	Shoot();
	camera.UpdateCamera(transform.getLocalPosition() + vec3(0, 0.65f, 0));


	vec3 weaponAimOffset;
	float targetFov = 45;

	if (!aimingDownSights) {
		weaponAimOffset =
			camera.dir * wp_forward -
			camera.up * wp_up -
			camera.right * wp_right;

		targetFov = 45;
	}
	else
	{
		weaponAimOffset =
			camera.dir * wp_forward_sights -
			camera.up * wp_up_sights -
			camera.right * wp_right_sights;

		targetFov = 44.5;
	}

	// single sided slerp target fov
	float fovDiff = camera.fov - targetFov;
	camera.fov -= fovDiff * Time::deltaTime() * 30;

	// single sided slerp weapon pos
	vec3 aimOffsetDifference = currentAimOffset - weaponAimOffset;
	currentAimOffset -= aimOffsetDifference * Time::deltaTime() * 50.0f;

	weapon.transform.setLocalPosition(camera.pos + currentAimOffset);
	weapon.transform.setRotation(vec3(camera.pitch, -camera.yaw - 90, 0));

	Move();


	// Check RMB to toggle aiming down sights
	aimingDownSights = Input::getMouse(2);

	// Draw Crosshair
	if (!aimingDownSights)
		DrawCrosshair();
}

#define MOVESPEED 4.0f

void Player::Move()
{
	//vec3

	if (Input::getKeyDown(' '))
	{
		rigidbody->AddForce(vec3(0, 1, 0) * vec3(250) * Time::deltaTime());
		std::cout << "Jumped" << std::endl;
	}
	vec3 horizontalVelocity;

	if (Input::getKey('W')) horizontalVelocity += camera.dir;
	if (Input::getKey('A')) horizontalVelocity += camera.right;
	if (Input::getKey('S')) horizontalVelocity += -camera.dir;
	if (Input::getKey('D')) horizontalVelocity += -camera.right;

	horizontalVelocity.y = 0;
	
	if (glm::length(horizontalVelocity) > 0)
		horizontalVelocity = glm::normalize(horizontalVelocity);
	
	horizontalVelocity *= vec3(MOVESPEED) * Time::deltaTime();

	horizontalVelocity += transform.getLocalPosition();
	ClampVelocity(horizontalVelocity);

	transform.setLocalPosition(horizontalVelocity);
}



void Player::Shoot()
{
	RaycastHit hit;
	
	if (Input::getMouseDown(0))
	{

		if (Physics::raycast(hit, camera.pos + camera.dir, camera.dir))
		{
			GameObject * hitObject = &hit.collider->gameObject;

			Enemy * old_child = dynamic_cast<Enemy*>(hitObject);

			if (old_child)
			{
				old_child->Die();
				return;
			}
		}

		GameManager::Instance->timeElapsed += 2;
	}
}

void Player::DrawCrosshair()
{	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	glm::mat4 orth = glm::ortho((float)-screenWidth, (float)screenWidth, (float)screenHeight, (float)-screenHeight);
	glMultMatrixf(&(orth[0][0]));

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glBegin(GL_LINES);

	glColor3f(0, 1, 1);

	//Left
	glVertex3f(-18, 0, 0);
	glVertex3f(-5, 0, 0);

	//Right
	glVertex3f(18, 0, 0);
	glVertex3f(5, 0, 0);

	//Top
	glVertex3f(0, 18, 0);
	glVertex3f(0, 5, 0);

	//Btm
	glVertex3f(0, -5, 0);
	glVertex3f(0, -18, 0);

	glEnd();
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void Player::ClampVelocity(vec3& velocity)
{
	if (velocity.x <= 9)
		velocity.x = 9;
	if (velocity.x >= 12)
		velocity.x = 12;

	if (velocity.z <= -9)
		velocity.z = -9;
	if (velocity.z >= 5)
		velocity.z = 5;

	if (velocity.y <= 0.989)
		velocity.y = 0.989;

}
