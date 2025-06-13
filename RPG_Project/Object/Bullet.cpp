#include "framework.h"

Bullet::Bullet(float radius): Circle(radius)
{
	center = { 300,300 };
	
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	
	center.x += speed;
}

void Bullet::Fire(float2 center, int AP)
{
	isActive = true;
	this->center = center;
	this->AttackPoint += AP;
	
}
