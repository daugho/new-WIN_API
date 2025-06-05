#pragma once

class Bullet : public Circle
{
private:
	const int SPEED = 20;

public:
	Bullet();
	~Bullet();

	void Update();

	void Fire(Vector2 pos)
	{
		isActive = true;
		center = pos;
	}
};