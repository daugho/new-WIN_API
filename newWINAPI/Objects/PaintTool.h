#pragma once

class PaintTool
{
private:	
	enum class DrawType
	{
		Point, Pen, Line, Rectangle, Ellipse, End
	};
	
	enum class ColorType
	{
		Red,
		Green,
		Blue,
		Yellow,
		Cyan,
		Magenta,
		End
	};

public:
	PaintTool(HWND hWnd);
	~PaintTool();	

	void OnMouseMove(LPARAM lParam);
	void OnLButtonDown(LPARAM lParam);
	void OnLButtonUp(LPARAM lParam);

	void OnKeyDown(WPARAM wParam);

private:
	void InputSelectType(WPARAM wParam);
	void InputSelectColor(WPARAM wParam);

	void SetColors();
	void CreatePens();

private:
	HDC hdc;

	POINT prevMousePos = {};
	POINT curMousePos = {};

	DrawType selectDrawType = DrawType::Point;
	ColorType selectColorType = ColorType::Red;

	bool isMouseDown = false;

	HPEN* hPens;
	HBRUSH* hBrushes;	

	unordered_map<ColorType, COLORREF> colorMap;
};