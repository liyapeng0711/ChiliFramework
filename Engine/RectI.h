#pragma once
#include "Location.h"

class RectI
{
public:
	RectI() = default;
	RectI(Location leftUp, int width, int height);
	RectI(int left, int right, int up, int down);
	friend class Graphics;
public:
	int GetWidth()const;
	int GetHeight()const;
	bool TestInside(Location loc) const;
	void Draw(Graphics& gfx, class Color color)const;
	void DrawRing(Graphics& gfx, int thick, Color color)const; //zero and minus for inside, positive for outside
	RectI Expand(int padding)const;  // positive for bigger, negative for smaller
private:
	int left;
	int right;
	int up;
	int down;
};

