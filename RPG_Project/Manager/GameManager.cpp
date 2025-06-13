#include "framework.h"
#include "GameManager.h"

GameManager::GameManager()
{
	fabric = new Fabric();
	player = new Player(50);
	
	hdc = GetDC(hWnd);

	backBuffer = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBuffer, backBufferBitmap);
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);

	DeleteObject(backBufferBitmap);
	DeleteDC(backBuffer);
}

void GameManager::Update()
{
	player->Update();
	//bullet->Update();
	InvalidateRect(hWnd, nullptr, false);
	
}


void GameManager::Render()
{
	PatBlt(backBuffer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);
	
	fabric->Render(backBuffer);
	player->Render(backBuffer);
	//bullet->Render(backBuffer);

	BitBlt(hdc,0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, backBuffer, 0, 0, SRCCOPY);
}
