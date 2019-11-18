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
	bool TestInside(const Vec2& vec)const;
	float GetWidth()const;
	float GetHeight()const;
	Vec2 GetLeftUp()const;
	Vec2 GetRightDown()const;
	void SetLeft(float left);
	void SetRight(float right);
	void SetUp(float up);
	void SetDown(float down);
private:
	Vec2 leftUp;
	Vec2 rightDown;
};

