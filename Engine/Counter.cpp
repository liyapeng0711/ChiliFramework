#include "Counter.h"

void Counter::Draw(Graphics & gfx) const
{
	Color color = Colors::White;
	if (num == max)
	{
		color = Colors::Red;
	}
	for (int i = 0; i < num; ++i)
	{
		gfx.DrawRectColorDim(x + (width + gap)*i, y, width, height, color);
	}
}

void Counter::AddOne()
{
	++num;
	if (num > max)
	{
		num = max;
	}
}

int Counter::ShowNum() const
{
	return num;
}
