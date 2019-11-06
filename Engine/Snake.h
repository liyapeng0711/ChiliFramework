#pragma once
#include "Board.h"
#include "Keyboard.h"
class Snake
{
public:
	~Snake();
	void Init(Location head_loc, Location delta_loc);
	enum NextMoveType
	{
		EMPTY,
		FOOD,
		HIT
	};
	void GetInput(const Keyboard& kbd);
	NextMoveType Move(const Location& l);
	void DrawToBoard(Board& board)const;
	bool TestCollision(const Location& l)const;
public:
	static constexpr int maxSize = Board::widthNum*Board::heightNum;
private:
	int size = 1;
	Location loc[maxSize];
	Location deltaLoc;
	bool isRest = true;
	int counter = 0;
	int duration = 8;
};

