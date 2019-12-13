#pragma once
#include <random>

#include "Mouse.h"
#include "Graphics.h"

#include "SpriteCodes.h"
#include"GameStatus.h"
#include"Level.h"

#include "Location.h"
#include"RectI.h"

class Board
{
public:
	Board();

	// for embedded structure
public:
	enum CellStatus
	{
		HIDDEN,
		FLAG,
		SUSPECTED,
	};
	class Cell
	{
	public:
		Cell() = default;
	public:
		void Draw(Graphics& gfx)const;
		void DrawEnd(Graphics& gfx)const;
		void Initialize(Location leftUp_, CellStatus status_);
		void ClickRight(); // click hidden/flag/suspected
		void Reveal(); 
		bool IsMine()const;
		void SetMine();
		bool IsRevealed()const;
		bool CanBeRevealed()const;
		void SetNumOfMineAround(int num);
		int GetNumOfMineAround()const;
		bool IsFlagged()const;
		Location GetLeftUp()const;
	private:
		Location leftUp;
		CellStatus status;
		int numOfMineAround;
		bool isMine = false;
		bool isRevealed = false;
	};

	// for inner function and members
public:
	GameStatus Update(Mouse& mouse);
	void Draw(Graphics& gfx)const;
	void Initialize(Level level); // decide size of board, cell, and initialize them
	void DrawEnd(Graphics& gfx)const;
	int GetRemainMineNum()const;

private:
	void SpreadMineExcept(int index);
	void Reveal(int x, int y); // reveal a non-mine cell
	int CalMineAround(int x, int y)const; // can we save the num in cell to avoid many repeted calculations
	void CalculateAllMineAround();
	bool IsWin()const;

private:
	int cellNumX;
	int cellNumY;
	int cellSize;
	Cell cells[BoardPara::difficultCellYNum*BoardPara::difficultCellXNum];
	Location origin = { 0,BoardPara::dividingY }; //leftUp, x is chaning while y is fixed for dividing bar and board
	int mineNum;
	bool isSpreadMine = false;
	std::mt19937 rng;
	bool isPointed = false;
	int indexPointed;
	int numRevealed = 0;
	int numFlagged = 0;
};

