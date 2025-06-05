#include "Framework.h"

Enemy::Enemy() : Circle(30)
{
	hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));

	hSelectBrush = hBlueBrush;
}

Enemy::~Enemy()
{
	DeleteObject(hRedBrush);
	DeleteObject(hBlueBrush);
}

void Enemy::Update()
{
	if (!isActive) return;

	Move();
	Damage();	
}

void Enemy::Render(HDC hdc)
{
	if (!isActive) return;

	HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);

	Circle::Render(hdc);

	SelectObject(hdc, defaultBrush);
}

void Enemy::Spawn(Vector2 pos)
{
	center = pos;
	isActive = true;
	hSelectBrush = hBlueBrush;
	hp = MAX_HP;
	isDamaged = false;
}

void Enemy::Damage()
{
	if (isDamaged)
	{
		damageTimer += DELTA;

		if (damageTimer >= DAMAGE_INTERVAL)
		{
			damageTimer = 0;
			isDamaged = false;
			hSelectBrush = hBlueBrush;
		}
		return;
	}	

	if (BulletManager::Get()->IsCollision(this))
	{
		//isActive = false;
		hp -= 10;
		isDamaged = true;
		hSelectBrush = hRedBrush;

		if (hp <= 0)
		{
			isActive = false;
		}		
	}
}

void Enemy::Move()
{
	center.y += SPEED * DELTA;

	if (center.y > SCREEN_HEIGHT)
	{
		isActive = false;
	}
}
