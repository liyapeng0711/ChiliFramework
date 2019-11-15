#pragma once
#include"Vec2.h"
class Rect
{
public:
	Rect() = default;
	Rect(Vec2 leftUp, Vec2 rightDown);
	Rect(Vec2 leftUp, float width, float height);
	static Rect RectCenter(Vec2 center, float halfWidth, float halfHeight);
	bool TestCollision(const Rect& rect) const;
	float GetWidth()const;
	float GetHeight()const;
	Vec2 GetLeftUp()const;
	Vec2 GetRightDown()const;
private:
	Vec2 leftUp;
	Vec2 rightDown;
};

