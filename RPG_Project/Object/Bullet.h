#pragma once

class Bullet : public Circle
{
private:
	float bulletSpeed = 0.2;
public:

	Bullet(float radius);
	~Bullet();

	void Update();
	
	void Fire(float2 center);


private:
};
