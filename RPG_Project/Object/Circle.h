#pragma once

class Circle
{
public:
	Circle();
	Circle(float radius);
	~Circle();

	void Render(HDC hdc);
	void OutOfLine();

	void SetActive(bool active) { isActive = active; }
	bool GetActive() { return isActive; }
protected:
	bool isActive = true;
	bool  isKeyDown = false;
	float radius;
	float2 center = {};
};
