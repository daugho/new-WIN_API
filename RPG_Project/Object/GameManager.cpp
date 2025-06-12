#include "framework.h"
#include "GameManager.h"

GameManager::GameManager()
{
	fabric = new Fabric();
	player = new Player(50);
	hdc = GetDC(hWnd);

	backBufferDC = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBufferDC, backBufferBitmap);
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);

	DeleteObject(backBufferBitmap);
	DeleteDC(backBufferDC);
}

void GameManager::Update()
{
	player->Update();
}

void GameManager::Render(HDC hdc)
{
	fabric->Render(hdc);
	player->Render(hdc);
	
}

void GameManager::Render()
{
	PatBlt(backBufferDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);

	fabric->Render(backBufferDC);
	player->Render(backBufferDC);

	BitBlt(hdc,0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,backBufferDC, 0, 0, SRCCOPY);
}
