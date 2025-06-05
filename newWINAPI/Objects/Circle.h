#pragma once

class Circle
{
public:
	Circle(int radius);
	~Circle();

	void Render(HDC hdc);

	bool IsCollisionPoint(POINT point);
	bool IsCollisionCircle(Circle* circle);
	

	void SetCenter(float x, float y) { center = { x, y }; }
	void SetCenter(Vector2 center) { this->center = center; }
	Vector2 GetCenter() { return center; }

	void SetActive(bool isActive) { this->isActive = isActive; }
	bool IsActive() { return isActive; }

protected:
	bool isActive = true;

	Vector2 center = {};
	int radius;
};