#pragma once

class ShootingScene : public Scene
{
public:
	ShootingScene();
	~ShootingScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	Player* player;	
};