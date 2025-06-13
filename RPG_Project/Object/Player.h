#pragma once
#include "framework.h"

class Player
{
private:
	float speed = 0.1;
	float gravity = 0.0005f;

public:
	Player(float radius);
	~Player();

	void Render(HDC hdc);
	void Update();
	void Gravity();

private:
	float radius;
	float2 center = { 300,300 };


	float yVelocity = {};
	
	float groundY = SCREEN_HEIGHT - 100;
	bool isKeyPreesed = false;
};