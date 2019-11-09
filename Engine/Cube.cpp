#include "Cube.h"

void Cube::Draw(Graphics& gfx)
{
	gfx.DrawRectColorDim(int(pos.x), int(pos.y), width, height, color);
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

void Cube::UpdateColorChili()
{
	if (isIncreasing)
	{
		if (color.GetR() >= 253)
		{
			isIncreasing = false;
		}
		else
		{
			color = Color(color.GetR() + 2, color.GetG() + 4, color.GetB() + 4);
		}
	}
	else
	{
		if (color.GetR() <= 127)
		{
			isIncreasing = true;
		}
		else
		{
			color = Color(color.GetR() - 2, color.GetG() - 4, color.GetB() - 4);
		}
	}
}

void Cube::TestCollide(const Dude & dude)
{
	const float box1Left = pos.x;
	const float box1Right = pos.x + float(width - 1);
	const float box1Up = pos.y;
	const float box1Down = pos.y + float(height - 1);
	const float box2Left = dude.GetPos().x;
	const float box2Right = dude.GetPos().x + float(Dude::width - 1);
	const float box2Up = dude.GetPos().y;
	const float box2Down = dude.GetPos().y + float(Dude::height - 1);
	isEaten = box1Left <= box2Right && box1Right >= box2Left &&
		box1Up <= box2Down && box1Down >= box2Up;
}

void Cube::InitXY(Vec2 pos_1)
{
	pos = pos_1;
	isEaten = false;
	count = 0;
}
