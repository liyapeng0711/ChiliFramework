#include "Padder.h"



Padder::Padder(Rect rect)
	:
	rect(rect)
{
}

void Padder::Update(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		rect = Rect(rect.GetLeftUp() - Vec2(speed*dt, 0), rect.GetRightDown() - Vec2(speed*dt, 0));
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		rect = Rect(rect.GetLeftUp() + Vec2(speed*dt, 0), rect.GetRightDown() + Vec2(speed*dt, 0));
	}
}

void Padder::LimitInRect(Rect rect_)
{
	const float left = rect_.GetLeftUp().x;
	const float right = rect_.GetRightDown().x;
	const float up = rect_.GetLeftUp().y;
	const float down = rect_.GetRightDown().y;
	if (rect.GetLeftUp().x < left)
	{
		rect.SetLeft(left);
	}
	else if (rect.GetRightDown().x > right)
	{
		rect.SetRight(right);
	}
	if (rect.GetLeftUp().y < up)
	{
		rect.SetUp(up);
	}
	else if (rect.GetRightDown().y > down)
	{
		rect.SetDown(down);
	}
}

void Padder::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, paddingColor);
	gfx.DrawRect(Rect(rect.GetLeftUp() + Vec2(paddingWidth, 0), rect.GetRightDown() - Vec2(paddingWidth, 0)), color);
}

Rect Padder::GetRect() const
{
	return rect;
}
