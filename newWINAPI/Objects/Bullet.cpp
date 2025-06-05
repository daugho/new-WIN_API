#include "Framework.h"

Bullet::Bullet() : Circle(10)
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	center.y -= SPEED;

	if (center.y < 0)
	{
		isActive = false;
	}
}
