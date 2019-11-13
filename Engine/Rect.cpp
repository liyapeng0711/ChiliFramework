#include "Rect.h"

Rect::Rect(Vec2 leftUp, Vec2 rightDown)
	:
	leftUp(leftUp),
	rightDown(rightDown)
{
}

Rect::Rect(Vec2 leftUp, float width, float height)
	:
	Rect(leftUp, leftUp + Vec2(width, height))
{
}


bool Rect::TestCollision(const Rect & rect) const
{
	return leftUp.x <= rect.rightDown.x && leftUp.y <= rect.rightDown.y
		&& rightDown.x >= rect.leftUp.x && rightDown.y >= rect.leftUp.y;
}

float Rect::GetWidth() const
{
	return (rightDown - leftUp).x;
}

float Rect::GetHeight() const
{
	return (rightDown - leftUp).y;
}
