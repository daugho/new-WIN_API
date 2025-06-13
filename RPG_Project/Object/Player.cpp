#include "framework.h"

Player::Player(float radius) : Circle(radius)
{
    bullet = new Bullet(10);
    bullet->SetActive(false);
}

Player::~Player()
{
}

void Player::Render(HDC hdc)
{
    Circle::Render(hdc);
    bullet->Render(hdc);

}

void Player::Update()
{
    
    MoveControl();
    Gravity();

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
   // if (GetAsyncKeyState(VK_UP))
   // {
   //     if (center.y + radius >= groundY)
   //     {
   //         center.y -= speed + 100;
   //     }
   // }
    if (GetAsyncKeyState(VK_DOWN))
    {
        center.y += speed;
    }
  
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (!isActive)
        {
            bullet->Fire(this->center, this->AttackPoint);
            
        }
       
    }
    bullet->Update();
    
}
