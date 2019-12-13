#include "RectI.h"
#include "Graphics.h"
#include "Colors.h"
#include <assert.h>


RectI::RectI(Location leftUp, int width, int height)
	:
	RectI(leftUp.x, leftUp.y, leftUp.x+width, leftUp.y+height)
{
}

RectI::RectI(int left, int right, int up, int down)
	:
	left(left),
	right(right),
	up(up),
	down(down)
{
	assert(right >= left&&down >= up);
}

int RectI::GetWidth() const
{
	return right-left;
}

int RectI::GetHeight() const
{
	return down - up;
}

bool RectI::TestInside(Location loc) const
{
	return loc.x >= left&&loc.x <= right&&loc.y >= up&&loc.y <= down;
}

void RectI::Draw(Graphics & gfx, Color color) const
{
	gfx.DrawRect(*this, color);
}

void RectI::DrawRing(Graphics & gfx, int thick, Color color) const
{
	gfx.DrawRectRing(*this, thick, color);
}



RectI RectI::Expand(int padding) const
{
	return RectI(left - padding, up - padding, right + padding, down + padding);
}
