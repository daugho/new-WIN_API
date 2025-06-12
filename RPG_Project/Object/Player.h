#pragma once
#include "framework.h"

class Player
{
public:
	Player(float radius);
	~Player();

	void Render(HDC hdc);
	void Update();
	void Gravity();

private:
	float radius;
	POINT center = { 300,300 };
	float speed = 5;

	float yVelocity = {};
	float gravity = 0.5f;
	float groundY = ScreenHeight - 100;
};