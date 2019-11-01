#include "Cube.h"

void Cube::Draw(Graphics& gfx)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			gfx.PutPixel(x + i, y + j, color);
		}
	}
}

bool Cube::IsEaten() const
{
	return isEaten;
}

void Cube::UpdateColor()
{
	count += 1;
	count %= halfFreq * 2;
	int tempCount = count;
	tempCount %= halfFreq;
	if (count < halfFreq)
	{
		color = Color(255 - 255 * tempCount / (halfFreq - 1), 255 * tempCount / (halfFreq - 1), 0);
	}
	else
	{
		color = Color(255 * tempCount / (halfFreq - 1), 255 - 255 * tempCount / (halfFreq - 1), 0);
	}
}

void Cube::TestCollide(const Dude & dude)
{
	const int box1Left = x;
	const int box1Right = x + width - 1;
	const int box1Up = y;
	const int box1Down = y + height - 1;
	const int box2Left = dude.GetX();
	const int box2Right = dude.GetX() + Dude::width - 1;
	const int box2Up = dude.GetY();
	const int box2Down = dude.GetY() + Dude::height - 1;
	isEaten = box1Left <= box2Right && box1Right >= box2Left &&
		box1Up <= box2Down && box1Down >= box2Up;
}

void Cube::InitXY(int x_1, int y_1)
{
	x = x_1;
	y = y_1;
	isEaten = false;
	count = 0;
}
