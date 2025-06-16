#pragma once
#include "framework.h"

class Player : public Circle
{
private:
	float speed = 0.1;
	int AttackPoint = 2;
	int bulletPoolSize = 100;
public:
	Player(float radius);
	~Player();

	void Update();
	void Render(HDC hdc);

	void MoveControl();

private:
	bool iskeyPreesed = false;
	//class Bullet* bullet;

	vector<class Bullet*> bullets;
};