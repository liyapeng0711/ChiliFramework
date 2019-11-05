#include "Snake.h"


Snake::~Snake()
{
}

void Snake::Init(Location head_loc, Location delta_loc)
{
	loc[0] = head_loc;
	deltaLoc = delta_loc;
}

void Snake::GetInput(const Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		deltaLoc = { 0,-1 };
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		deltaLoc = { 0,1 };
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		deltaLoc = { -1,0 };
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		deltaLoc = { 1,0 };
	}
	//also self move
	++counter;
	isRest = true;
	if (counter == duration)
	{
		isRest = false;
		counter = 0;
	}
}

Snake::NextMoveType Snake::Move(const Location& l)
{
	if (!isRest)
	{
		NextMoveType type = EMPTY;
		Location headTo = loc[0] + deltaLoc;
		for (int i = size - 1; i > 0; --i)
		{
			if (loc[i] == headTo)
			{
				type = HIT;
				break;
			}
		}
		if (l == headTo)
		{
			type = FOOD;
		}

		//if can move, move; else, just don't move
		if (type != HIT)
		{
			if (type == FOOD)
			{
				size++;
			}
			for (int i = size - 1; i > 0; --i)
			{
				loc[i] = loc[i - 1];
			}
			loc[0] = headTo;
		}
		return type;
	}
	else
	{
		return EMPTY;
	}
}

void Snake::DrawToBoard(Board & board) const
{
	board.SetLocColor(loc[0], Board::snakeHeadColor);
	for (int i = 1; i < size; ++i)
	{
		board.SetLocColor(loc[i], Board::snakeBodyColor);
	}
}

bool Snake::TestCollision(const Location & l) const
{
	for (int i = size - 1; i >= 0; --i)
	{
		if (loc[i] == l)
		{
			return true;
		}
	}
	return false;
}
