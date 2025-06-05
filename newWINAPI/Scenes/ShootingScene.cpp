#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{
	player = new Player();	

	BulletManager::Get();
	EnemyManager::Get();
}

ShootingScene::~ShootingScene()
{
	delete player;

	BulletManager::Delete();
	EnemyManager::Delete();
}

void ShootingScene::Update()
{
	player->Update();

	BulletManager::Get()->Update();
	EnemyManager::Get()->Update();
}

void ShootingScene::Render(HDC hdc)
{
	player->Render(hdc);

	BulletManager::Get()->Render(hdc);
	EnemyManager::Get()->Render(hdc);
}
