#include "Brick.h"



Brick::Brick(Rect rect, Color color)
	:
	rect(rect),
	color(color)
{
}

void Brick::Draw(Graphics & gfx) const
{	
	gfx.DrawRect(rect, color);
}

Rect Brick::GetRect() const
{
	return rect;
}

void Brick::Destroy()
{
	isDestroyed = true;
}

bool Brick::IsDestroyed() const
{
	return isDestroyed;
}
