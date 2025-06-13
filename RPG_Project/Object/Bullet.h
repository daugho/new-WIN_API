#pragma once
#include "framework.h"
class Bullet : public Circle
{
private:
	int AttackPoint = 2;
	float speed = 0.1;
public:
	Bullet(float radius);
	~Bullet();

	void Update();
	void Fire(float2 center, int AP);


private:
	
};
