#include "framework.h"

Player::Player(float radius) : radius(radius)
{
}

Player::~Player()
{
}

void Player::Render(HDC hdc)
{
    Ellipse(hdc, center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}

void Player::Update()
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        center.x += speed;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        center.x -= speed;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        center.y -= speed;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        center.y += speed;
    }
    Gravity();

    InvalidateRect(hWnd, nullptr, true);
}


void Player::Gravity()
{
    yVelocity += gravity;
    center.y += yVelocity;
    if (center.y + radius >= groundY)
    {
        center.y = groundY - radius;
        yVelocity = 0;
    }
  
    
}
