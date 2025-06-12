#pragma once
#include "framework.h"

class Player
{
public:
	Player();
	~Player();

	void Render();
	void Update();

private:
	float radius = 50;
	POINT center = { 300,300 };
	float speed = 5;
};