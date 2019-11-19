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
		rect.Move(Vec2(-speed*dt, 0.0f));
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		rect.Move(Vec2(speed*dt, 0.0f));
	}
	if (kbd.KeyIsPressed(VK_UP))
	{
		rect.Move(Vec2(0.0f, -speed*dt));
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		rect.Move(Vec2(0.0f, speed*dt));
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
		rect.Move(Vec2(left - rect.GetLeftUp().x, 0.0f));
		
	}
	else if (rect.GetRightDown().x > right)
	{
		rect.Move(Vec2(right - rect.GetRightDown().x, 0.0f));
	}
	if (rect.GetLeftUp().y < up)
	{
		rect.Move(Vec2(0.0f, up - rect.GetLeftUp().y));
	}
	else if (rect.GetRightDown().y > down)
	{
		rect.Move(Vec2(0.0f, down - rect.GetRightDown().y));
	}
}

void Padder::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect, paddingColor);
	gfx.DrawRect(Rect(rect.GetLeftUp() + Vec2(paddingWidthPer*rect.GetWidth(), 0.0f), rect.GetRightDown() - Vec2(paddingWidthPer*rect.GetWidth(), 0.0f)), color);
}

Rect Padder::GetRect() const
{
	return rect;
}

Vec2 Padder::GetSpeed() const
{
	return Vec2(speed, speed);
}
