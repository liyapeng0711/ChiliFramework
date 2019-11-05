#include "Food.h"



Food::Food(Location loc_1)
{
	loc = loc_1;
}


Food::~Food()
{
}

Location Food::GetLoc() const
{
	return loc;
}

void Food::SetLoc(Location loc_1)
{
	loc = loc_1;
}

void Food::DrawToBoard(Board & board)
{
	board.SetLocColor(loc, Board::foodColor);
}

