#include "framework.h"
#include "fabric.h"

Fabric::Fabric()
{
}

Fabric::~Fabric()
{
}

void Fabric::Render(HDC hdc)
{
	Rectangle(hdc, 0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, SCREEN_WIDTH);
}
