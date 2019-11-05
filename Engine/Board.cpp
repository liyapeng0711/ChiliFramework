#include "Board.h"



Board::Board(int x_1, int y_1)
{
	x = x_1;
	y = y_1;
}


Board::~Board()
{
}

void Board::Draw(Graphics & gfx) const
{
	for (int i = 0; i < widthNum; ++i)
	{
		for (int j = 0; j < heightNum; ++j)
		{
			const int xi = x + i*width;
			const int yi = y + j*height;
			gfx.DrawRectDimColor(xi + 1, yi + 1, width - 1, height - 1, color[j*widthNum + i]);
		}
	}
}

void Board::SetLocColor(const Location loc, Color c)
{
	color[loc.y*widthNum + loc.x] = c;
}

void Board::ResetColor()
{
	for (int i = 0; i < widthNum*heightNum; ++i)
	{
		color[i] = emptyColor;
	}
}
