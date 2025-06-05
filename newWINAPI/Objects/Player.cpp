#include "Framework.h"

Player::Player() : Circle(50)
{
	hPen = CreatePen(PS_SOLID, 5, RGB(100, 230, 150));

	center = { SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 4 / 5 };
}

Player::~Player()
{
	DeleteObject(hPen);	
}

void Player::Update()
{
	ControlMove();
	ControlFire();	

	ClampToScreenBounds();
}

void Player::Render(HDC hdc)
{
	//Circle::Render(hdc);
	DrawLine(hdc);
}

void Player::Fire()
{
	BulletManager::Get()->Fire(firePos);
}

void Player::ControlFire()
{
	if (Input::Get()->IsKeyDown(VK_SPACE))
	{
		Fire();	
	}
}

void Player::ControlMove()
{
	if (GetAsyncKeyState(VK_RIGHT))
		center.x += SPEED * DELTA;
	if (GetAsyncKeyState(VK_LEFT))
		center.x -= SPEED * DELTA;
	if (GetAsyncKeyState(VK_UP))
		center.y -= SPEED * DELTA;
	if (GetAsyncKeyState(VK_DOWN))
		center.y += SPEED * DELTA;
}

void Player::ClampToScreenBounds()
{
	//Left
	if(center.x - radius < 0)
		center.x = radius;

	//Right
	if (center.x + radius > SCREEN_WIDTH)
		center.x = SCREEN_WIDTH - radius;

	//Top
	if (center.y - radius < 0)
		center.y = radius;

	//Bottom
	if (center.y + radius > SCREEN_HEIGHT)
		center.y = SCREEN_HEIGHT - radius;
}

void Player::DrawLine(HDC hdc)
{
	firePos = { center.x, center.y - radius };
	POINT right = { center.x + radius, center.y + radius };
	POINT left = { center.x - radius, center.y + radius };

	HPEN defaultPen = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, firePos.x, firePos.y, nullptr);
	LineTo(hdc, right.x, right.y);

	MoveToEx(hdc, firePos.x, firePos.y, nullptr);
	LineTo(hdc, left.x, left.y);

	MoveToEx(hdc, center.x, center.y + (radius >> 1), nullptr);
	LineTo(hdc, right.x, right.y);

	MoveToEx(hdc, center.x, center.y + (radius >> 1), nullptr);
	LineTo(hdc, left.x, left.y);

	SelectObject(hdc, defaultPen);
}

