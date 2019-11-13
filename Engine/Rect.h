#pragma once
#include"Vec2.h"
class Rect
{
public:
	Rect() = default;
	Rect(Vec2 leftUp, Vec2 rightDown);
	Rect(Vec2 leftUp, float width, float height);
	bool TestCollision(const Rect& rect) const;
	float GetWidth()const;
	float GetHeight()const;
private:
	Vec2 leftUp;
	Vec2 rightDown;
};

