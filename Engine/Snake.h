#pragma once
#include "Board.h"
#include "Keyboard.h"
class Snake
{
public:
	Snake();
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
private:
	static constexpr int maxSize = Board::widthNum*Board::heightNum;
	static constexpr int colorSize = 5;
private:
	int size = 1;
	Location loc[maxSize];
	Location deltaLoc;
	Color colorPattern[colorSize];
};

