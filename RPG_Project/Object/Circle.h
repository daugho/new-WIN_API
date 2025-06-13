#pragma once

class Circle
{
public:
	Circle();
	Circle(float radius);
	~Circle();

	void Render(HDC hdc);


	void SetActive(bool active) { isActive = active; }
protected:
	bool isActive = true;
	bool  isKeyDown = false;
	float radius;
	float2 center = {};
};
