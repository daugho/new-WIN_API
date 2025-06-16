#include "framework.h"

Player::Player(float radius) : Circle(radius)
{
}

Player::~Player()
{
}

void Player::Update()
{    
    MoveControl();	
}

void Player::MoveControl()
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
}
