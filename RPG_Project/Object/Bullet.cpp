#include "framework.h"

Bullet::Bullet(float radius) : Circle(radius)
{
	isActive = false;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (!isActive) { return; }
	center.x += bulletSpeed;
	if (center.x - radius > SCREEN_WIDTH)
	{
		isActive = false;
	}
}

void Bullet::Fire(float2 pos)
{
	center = pos;
	isActive = true;
}

//void Bullet::Render(HDC hdc)
//{
//	Circle::Render(hdc);
//}




