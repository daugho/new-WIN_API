#include "Framework.h"

BulletManager::BulletManager()
{
	//bullet = new Bullet();	

	//Reserve
	//bullets.reserve(BULLET_POOL_SIZE);
	//for (int i = 0; i < BULLET_POOL_SIZE; i++)
	//{
	//	Bullet* bullet = new Bullet();
	//	bullets.push_back(bullet);
	//}
	//Resize
	bullets.resize(BULLET_POOL_SIZE);//Bullet* bullets[50];
	for (Bullet*& bullet : bullets)
	{
		bullet = new Bullet();
		bullet->SetActive(false);
	}
}

BulletManager::~BulletManager()
{
	for (Bullet*& bullet : bullets)
	{
		delete bullet;
	}
	bullets.clear();
}

void BulletManager::Update()
{
	for (Bullet*& bullet : bullets)
	{
		bullet->Update();
	}
}

void BulletManager::Render(HDC hdc)
{
	//bullet->Render(hdc);
	for (Bullet*& bullet : bullets)
	{
		bullet->Render(hdc);
	}
}

bool BulletManager::IsCollision(Circle* circle)
{
	for (Bullet*& bullet : bullets)
	{
		if (bullet->IsActive() && bullet->IsCollisionCircle(circle))
		{
			//다운 캐스팅
			//Enemy* enemy = (Enemy*)(circle);
			//enemy->Damage();

			bullet->SetActive(false);
			return true;
		}
	}

	return false;
}

void BulletManager::Fire(Vector2 pos)
{
	for (Bullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			bullet->Fire(pos);
			break;
		}
	}
}
