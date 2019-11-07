#pragma once
#include "Board.h"
class Obstacle
{
public:
	Obstacle();
	~Obstacle();
	void AddOne(Location loc_1);
	bool TestCollision(Location l)const;
	void DrawToBoard(Board& board)const;
private:
	int num = 0;
	static constexpr int maxNum = Board::widthNum*Board::heightNum;
	Location loc[maxNum];
};

