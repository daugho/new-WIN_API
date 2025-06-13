#include "framework.h"

Circle::Circle()
{
}

Circle::Circle(float radius) : radius(radius)
{

}

Circle::~Circle()
{
}

void Circle::Render(HDC hdc)
{
	Ellipse(hdc, center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}
