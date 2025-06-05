#include "Framework.h"

PaintTool::PaintTool(HWND hWnd)
{
	hdc = GetDC(hWnd);	

	SetColors();
	CreatePens();
}

PaintTool::~PaintTool()
{	
	for (int i = 0; i < (int)ColorType::End; i++)
	{
		DeleteObject(hPens[i]);
	}	

	delete[] hPens;
}

void PaintTool::OnMouseMove(LPARAM lParam)
{
	curMousePos.x = LOWORD(lParam);
	curMousePos.y = HIWORD(lParam);

	if (!isMouseDown) return;
	if (selectDrawType != DrawType::Pen) return;	

	MoveToEx(hdc, prevMousePos.x, prevMousePos.y, nullptr);
	LineTo(hdc, curMousePos.x, curMousePos.y);

	prevMousePos = curMousePos;
}

void PaintTool::OnLButtonDown(LPARAM lParam)
{
	SelectObject(hdc, hPens[(int)selectColorType]);

	prevMousePos.x = LOWORD(lParam);
	prevMousePos.y = HIWORD(lParam);

	if (selectDrawType == DrawType::Point)
	{
		SetPixel(hdc, prevMousePos.x, prevMousePos.y, colorMap[selectColorType]);
		return;
	}

	isMouseDown = true;	
}

void PaintTool::OnLButtonUp(LPARAM lParam)
{
	isMouseDown = false;	

	switch (selectDrawType)
	{
	case PaintTool::DrawType::Line:
		MoveToEx(hdc, prevMousePos.x, prevMousePos.y, nullptr);
		LineTo(hdc, curMousePos.x, curMousePos.y);		
		break;
	case PaintTool::DrawType::Rectangle:
		break;
	case PaintTool::DrawType::Ellipse:
		break;
	case PaintTool::DrawType::End:
		break;
	default:
		break;
	}
}

void PaintTool::OnKeyDown(WPARAM wParam)
{
	InputSelectType(wParam);
	InputSelectColor(wParam);

	
}

void PaintTool::InputSelectType(WPARAM wParam)
{
	if (wParam < VK_F1 || wParam > VK_F1 + (int)DrawType::End)
		return;

	selectDrawType = (DrawType)(wParam - VK_F1);
}

void PaintTool::InputSelectColor(WPARAM wParam)
{
	if (wParam < '1' || wParam > '1' + (int)ColorType::End)
		return;

	selectColorType = (ColorType)(wParam - '1');
}

void PaintTool::SetColors()
{
	colorMap[ColorType::Red] = RGB(255, 0, 0);
	colorMap[ColorType::Green] = RGB(0, 255, 0);
	colorMap[ColorType::Blue] = RGB(0, 0, 255);
	colorMap[ColorType::Yellow] = RGB(255, 255, 0);
	colorMap[ColorType::Cyan] = RGB(0, 255, 255);
	colorMap[ColorType::Magenta] = RGB(255, 0, 255);
}

void PaintTool::CreatePens()
{
	hPens = new HPEN[(int)ColorType::End];

	//for (int i = 0; i < (int)ColorType::End; i++)
	//{
	//	hPens[i] = CreatePen(PS_SOLID, 1, colorMap[(ColorType)i]);
	//}
	//colorMap.insert(pair<ColorType, COLORREF>(ColorType::Red, RGB(255, 0, 0)));
	for (pair<ColorType, COLORREF> color : colorMap)	
	{
		hPens[(int)color.first] = CreatePen(PS_SOLID, 1, color.second);
	}
}
