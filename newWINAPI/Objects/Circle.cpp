#include "Framework.h"
#include "Circle.h"

Circle::Circle(int radius) : radius(radius)
{
}

Circle::~Circle()
{
}


void Circle::Render(HDC hdc)
{
	if (!isActive) return;

	Ellipse(hdc, 
		center.x - radius, center.y - radius,//LeftTop
		center.x + radius, center.y + radius//RightBottom
	);	
}

bool Circle::IsCollisionPoint(POINT point)
{
	int dx = center.x - point.x;
	int dy = center.y - point.y;

	//float distance = sqrt(dx * dx + dy * dy);
	//return distance <= radius;

	return (dx * dx + dy * dy) <= (radius * radius);
}

bool Circle::IsCollisionCircle(Circle* circle)
{
	int dx = center.x - circle->center.x;
	int dy = center.y - circle->center.y;

	//float distance = sqrt(dx * dx + dy * dy);
	//return distance <= (radius + circle->GetRadius());

	return (dx * dx + dy * dy) <= ((radius + circle->radius) * (radius + circle->radius));	
}
