#include "Obstacle.h"



Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{
}

void Obstacle::AddOne(Location loc_1)
{
	++num;
	loc[num - 1] = loc_1;
}


bool Obstacle::TestCollision(Location l) const
{
	for (int i = num - 1; i >= 0; --i)
	{
		if (loc[i] == l)
		{
			return true;
		}
	}
	return false;
}

void Obstacle::DrawToBoard(Board & board) const
{
	for (int i = 0; i < num; ++i)
	{
		board.SetLocColor(loc[i], Board::obstacleColor);
	}
}
