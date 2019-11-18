#pragma once
#include"Rect.h"
#include"Colors.h"
#include"Graphics.h"
class Brick
{
public:
	Brick() = default;
	Brick(Rect rect, Color color);
	void Draw(Graphics& gfx)const;
	Rect GetRect()const;
	void Destroy();
	bool IsDestroyed()const;
private:
	Rect rect;
	Color color = Colors::White;
	bool isDestroyed = false;
};

