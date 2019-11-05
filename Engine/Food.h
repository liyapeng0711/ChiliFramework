#pragma once
#include "Board.h"
class Food
{
public:
	Food(Location loc_1);
	~Food();
	Location GetLoc()const;
	void SetLoc(Location loc_1);
	void DrawToBoard(Board& board);
private:
	Location loc;
	
};

