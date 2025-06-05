#include "Framework.h"

Timer::Timer()
{
	//1초동안 CPU 진동수를 반환하는 함수
	QueryPerformanceFrequency((LARGE_INTEGER*)&preriodFrequency);
	//현재 CPU 진동수를 반환하는 함수
	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
	timeScale = 1.0f / preriodFrequency;	
}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	elapsedTime = (currentTime - lastTime) * timeScale;

	lastTime = currentTime;

	frameCount++;
	oneSecondCount += elapsedTime;

	if (oneSecondCount >= 1.0f)
	{
		frameRate = frameCount;
		frameCount = 0;
		oneSecondCount = 0.0f;
	}
}

void Timer::Render(HDC hdc)
{
	wstring str = L"FPS : " + to_wstring(frameRate);
	TextOut(hdc, 0, 0, str.c_str(), str.size());
	str = L"ElapsedTime : " + to_wstring(elapsedTime);
	TextOut(hdc, 0, 20, str.c_str(), str.size());
}
