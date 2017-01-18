#include "Player.h"
#include "Input.h"
#include "Rigidbody.h"
#include "Time.h"
#include <gtc/matrix_transform.inl>

extern int screenWidth;
extern int screenHeight;


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

	// Draw crosshair
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

#define MOVESPEED 4.0f

void Player::Move()
{
	//vec3

	if (Input::getKeyDown(' '))
	{
		rigidbody->AddForce(vec3(0, 1, 0) * vec3(1200) * Time::deltaTime());
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
	transform.setLocalPosition(horizontalVelocity);
}
