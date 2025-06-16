#include "framework.h"

Player::Player(float radius) : Circle(radius)
{
    center = { 50,300 };
    //bullet = new Bullet(10);
    bullets.reserve(bulletPoolSize);
    for (int i = 0; i < bulletPoolSize; i++)
    {
        Bullet* bullet = new Bullet(5);
        bullet->SetActive(false);
        bullets.push_back(bullet);
    }
 
}

Player::~Player()
{
    //delete bullet;
    for (Bullet* bullet : bullets)
    {
        delete bullet;
    }
	bullets.clear();
}

void Player::Update()
{    
    MoveControl();	
}

void Player::Render(HDC hdc)
{
    Circle::Render(hdc);
    //bullet->Render(hdc);
    for (Bullet* bullet : bullets)
    {
        if (bullet->GetActive())
        bullet->Render(hdc);
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
    if (GetAsyncKeyState(VK_UP))
    {
        center.y -= speed;        
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        center.y += speed;
    }    
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (!iskeyPreesed)
        {
            iskeyPreesed = true;
           // bullet->Fire(center);

            for (Bullet* bullet : bullets)
            {
                if (!bullet->GetActive())
                {
                
                bullet->Fire(center);
                break;
                }  
            }

        }
       
      
    }
    else
    {
        iskeyPreesed = false;
    }
    //bullet->Update();
    for (Bullet* bullet : bullets)
    {
        if (bullet->GetActive())
        {
            bullet->Update();
        }
    }
}
