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
		const int xi = x + (width + gap)*i;
		const int yi = y;
		for (int j = 0; j < width; ++j)
		{
			for (int k = 0; k < height; ++k)
			{
				gfx.PutPixel(xi + j, yi + k, color);
			}
		}
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
