#pragma once
using namespace System::Drawing;

ref class Cell
{
public:
	static int size;
	bool val;
	Cell(void)
	{
		val = 0;
	}
	void draw(BufferedGraphics^ buff, int i, int j, int dBox, int dX, int dY )
	{
		Brush^ BrushBlue = gcnew SolidBrush(Color::Blue);
		Brush^ BrushGray = gcnew SolidBrush(Color::LightGray);
		if(val)
			buff->Graphics->FillRectangle(BrushBlue, i*(size+dBox)+dX, j*(size+dBox)+dY, size, size);
		else
			buff->Graphics->FillRectangle(BrushGray, i*(size+dBox)+dX, j*(size+dBox)+dY, size, size);
	}
};
