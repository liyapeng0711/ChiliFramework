#pragma once
#include "Rect.h"
class Ball
{
public:
	Ball(Vec2 center);

private:
	Vec2 center;
	static constexpr float width = 14;
	static constexpr float height = 14;
};

