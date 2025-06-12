#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update();
	void Render(HDC hdc);
	void Render();

private:
	HDC hdc;

	HDC backBufferDC;
	HBITMAP backBufferBitmap;

	Fabric* fabric;
	Player* player;
};
