#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update();
	void Render();

private:
	void Create();
	void Release();

private:
	HDC hdc;	

	Scene* scene;

	HDC backBufferDC;
	HBITMAP backBufferBitmap;
};