#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update();
	void Render();

private:
	HDC hdc;

	HDC backBuffer;
	HBITMAP backBufferBitmap;

	Fabric* fabric;
	Player* player;

	
	
};
