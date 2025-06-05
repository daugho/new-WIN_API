#include "Framework.h"

#include "Scenes/ShootingScene.h"

GameManager::GameManager()
{
	hdc = GetDC(hWnd);	

	backBufferDC = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBufferDC, backBufferBitmap);

	Create();

	scene = new ShootingScene();
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);		

	delete scene;

	Release();

	DeleteObject(backBufferBitmap);
	DeleteDC(backBufferDC);
}

void GameManager::Update()
{
	Timer::Get()->Update();
	Input::Get()->Update();

	scene->Update();

	InvalidateRect(hWnd, nullptr, false);
}

void GameManager::Render()
{
	PatBlt(backBufferDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);	

	scene->Render(backBufferDC);
	Timer::Get()->Render(backBufferDC);

	BitBlt(hdc, 
		0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
		backBufferDC, 0, 0, SRCCOPY);
}

void GameManager::Create()
{
	Timer::Get();
	Input::Get();


}

void GameManager::Release()
{
	Timer::Delete();
	Input::Delete();
}
