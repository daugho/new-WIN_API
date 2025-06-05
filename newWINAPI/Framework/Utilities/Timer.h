#pragma once

class Timer : public Singleton<Timer>
{
	friend class Singleton;
private:
	Timer();
	~Timer();
public:
	void Update();
	void Render(HDC hdc);
	
	float GetElapsedTime() { return elapsedTime; }

private:
	int frameRate = 0;
	int frameCount = 0;

	float timeScale = 0.0f;
	float elapsedTime = 0.0f;
	float oneSecondCount = 0.0f;
	float deltaScale = 1.0f;
		
	__int64 currentTime = 0;
	__int64 lastTime = 0;
	__int64 preriodFrequency = 0;
};