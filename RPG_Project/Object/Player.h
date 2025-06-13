#pragma once
#include "framework.h"

class Player : public Circle
{
private:
	float speed = 0.1;
	float gravity = 0.00005f;
	int AttackPoint = 2;
public:
	Player(float radius);
	~Player();

	void Render(HDC hdc);
	void Update();
	void Gravity();
	void MoveControl();

private:
	float yVelocity = {};
	float groundY = SCREEN_HEIGHT - 100;
	class Bullet* bullet;
	
	
};