#pragma once

class Enemy : public Circle
{
private:
	const int SPEED = 300;
	const float DAMAGE_INTERVAL = 0.1f;
	const int MAX_HP = 30;

public:
	Enemy();
	~Enemy();

	void Update();
	void Render(HDC hdc);

	void Spawn(Vector2 pos);

private:
	void Damage();
	void Move();

private:
	int hp = 0;
	float damageTimer = 0;
	bool isDamaged = false;	

	HBRUSH hRedBrush;
	HBRUSH hBlueBrush;
	HBRUSH hSelectBrush;	
};