#include "Framework.h"

EnemyManager::EnemyManager()
{
	//Reserve
	//enemies.reserve(ENEMY_POOL_SIZE);
	// 
	//for (int i = 0; i < ENEMY_POOL_SIZE; i++)
	//{
	//	Enemy* enemy = new Enemy();
	//	enemies.push_back(enemy);
	//}
	//Resize
	enemies.resize(ENEMY_POOL_SIZE);//Enemy* enemies[50];
	for (Enemy*& enemy : enemies)
	{
		enemy = new Enemy();
		enemy->SetActive(false);
	}
}

EnemyManager::~EnemyManager()
{
	for (Enemy*& enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();
}

void EnemyManager::Update()
{
	spawnTimer += DELTA;

	if (spawnTimer >= SPAWN_INTERVAL)
	{
		spawnTimer = 0.0f;
		SpawnEnemy();
	}

	for (Enemy*& enemy : enemies)
	{
		enemy->Update();
	}
}

void EnemyManager::Render(HDC hdc)
{
	for (Enemy*& enemy : enemies)
	{
		enemy->Render(hdc);
	}
}

void EnemyManager::SpawnEnemy()
{
	int randomX = rand() % SCREEN_WIDTH;

	for (Enemy*& enemy : enemies)
	{
		if (!enemy->IsActive())
		{
			enemy->Spawn({(float)randomX, 0 });
			break;
		}
	}
}
