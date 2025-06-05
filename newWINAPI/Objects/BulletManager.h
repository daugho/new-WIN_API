#pragma once

class BulletManager : public Singleton<BulletManager>
{
	friend class Singleton;

private:
	const int BULLET_POOL_SIZE = 50;	

private:
	BulletManager();
	~BulletManager();

public:
	void Update();
	void Render(HDC hdc);

	bool IsCollision(Circle* circle);
	

	void Fire(Vector2 pos);

private:
	vector<Bullet*> bullets;	
};