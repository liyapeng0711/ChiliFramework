#include "Board.h"
#include <assert.h>

Board::Board()
	:
	rng(std::random_device{}())
{
}

GameStatus Board::Update(Mouse & mouse)
{
	Location loc = Location{ mouse.GetPosX(), mouse.GetPosY() } -origin;
	int right = cellNumX*cellSize;
	int down = cellNumY*cellSize;
	if (loc.x >= 0 && loc.x < right&&loc.y >= 0 && loc.y < down)
	{
		isPointed = true;
		int xNum = loc.x / cellSize;
		int yNum = loc.y / cellSize;
		int index = yNum*cellNumX + xNum;
		indexPointed = index;
		if (!cells[index].IsRevealed())
		{
			if (mouse.RightIsPressed())
			{
				bool isFlaggedPre = cells[index].IsFlagged();
				cells[index].ClickRight();
				if (isFlaggedPre&&!cells[index].IsFlagged)
				{
					--numFlagged;
				}
				else if (!isFlaggedPre&&cells[index].IsFlagged)
				{
					++numFlagged;
				}
			}
			else if (mouse.LeftIsPressed())
			{
				if (isSpreadMine) // for the latter click
				{
					if (cells[index].CanBeRevealed())
					{
						if (cells[index].IsMine())
						{
							cells[index].Reveal();
							return GAME_OVER;
						}
						else
						{
							Reveal(xNum, yNum);
							++numRevealed;
							if (IsWin())
							{
								return GAME_WINNER;
							}
						}
					}
				}
				else // for the first click
				{
					SpreadMineExcept(index);
					CalculateAllMineAround();
					assert(!cells[index].IsMine());
					Reveal(xNum, yNum);
					assert(numRevealed == 0);
					++numRevealed;
					isSpreadMine = true;
				}
			}
		}
	}	
	else
	{
		isPointed = false;
	}	
	return PLAYING;
}

void Board::Draw(Graphics & gfx)const
{
	for (int i = 0; i < cellNumX*cellNumY; ++i)
	{
		cells[i].Draw(gfx);
	}
	if (isPointed)
	{
		RectI rect = RectI(cells[indexPointed].GetLeftUp(), cellSize, cellSize);
		rect.DrawRing(gfx, -1, Colors::Red);
	}
}

void Board::Initialize(Level level)
{
	switch (level)
	{
	case EASY:
		cellNumX = BoardPara::easyCellXNum;
		cellNumY = BoardPara::easyCellYNum;
		cellSize = BoardPara::easyCellSize;
		mineNum = BoardPara::easyMineNum;
		break;
	case MIDDLE:
		cellNumX = BoardPara::middleCellXNum;
		cellNumY = BoardPara::middleCellYNum;
		cellSize = BoardPara::middleCellSize;
		mineNum = BoardPara::middleMineNum;
		break;
	case DIFFICULT:
		cellNumX = BoardPara::difficultCellXNum;
		cellNumY = BoardPara::difficultCellYNum;
		cellSize = BoardPara::difficultCellSize;
		mineNum = BoardPara::difficultMineNum;
		break;
	default:
		break;
	}
	origin.x = (Graphics::ScreenWidth - cellNumX*cellSize) / 2;
	Location loc;
	for (int i = 0; i < cellNumY; ++i)
	{
		for (int j = 0; j < cellNumX; ++j)
		{
			loc = origin + Location{ j*cellSize,i*cellSize };
			cells[i*cellNumX + j].Initialize(loc, HIDDEN);
		}
	}
	isSpreadMine = false;
	isPointed = false;
	numRevealed = 0;
	numFlagged = 0;
}

void Board::DrawEnd(Graphics & gfx) const
{
	for (int i = 0; i < cellNumX*cellNumY; ++i)
	{
		cells[i].DrawEnd(gfx);
	}
}

int Board::GetRemainMineNum() const
{
	return mineNum - numFlagged;
}

void Board::SpreadMineExcept(int index)
{
	std::uniform_int_distribution<int> dist(0, cellNumX*cellNumY - 1);
	for (int i = 0; i < mineNum; ++i)
	{
		int rdIndex;
		do
		{
			rdIndex = dist(rng);
		} while (rdIndex != index && !cells[rdIndex].IsMine());
		cells[rdIndex].SetMine();
	}

}

void Board::Reveal(int x, int y)
{
	cells[y*cellNumX + x].Reveal();
	if (cells[y*cellNumX + x].GetNumOfMineAround() == 0)
	{
		int minX = max(0, x - 1);
		int maxX = min(x + 1, cellNumX - 1);
		int minY = max(0, y - 1);
		int maxY = min(y + 1, cellNumY - 1);
		for (int i = minX; i <= maxX; ++i)
		{
			for (int j = minY; j <= maxY; ++j)
			{
				if (!(i == x&&j == y))
				{
					Reveal(i, j);
				}
			}
		}
	}
}

int Board::CalMineAround(int x, int y) const
{
	int minX = max(0, x - 1);
	int maxX = min(x + 1, cellNumX - 1);
	int minY = max(0, y - 1);
	int maxY = min(y + 1, cellNumY - 1);
	int num = 0;
	for (int i = minX; i <= maxX; ++i)
	{
		for (int j = minY; j <= maxY; ++j)
		{
			if (cells[j*cellNumX + i].IsMine())
			{
				++num;
			}
		}
	}
	return num;
}

void Board::CalculateAllMineAround()
{
	for (int i = 0; i < cellNumX; ++i)
	{
		for (int j = 0; j < cellNumY; ++j)
		{
			cells[j*cellNumX + i].SetNumOfMineAround(CalMineAround(i, j));
		}
	}
}

bool Board::IsWin() const
{
	return numRevealed == (cellNumX*cellNumY - mineNum);
}

void Board::Cell::Draw(Graphics & gfx) const
{
	if (isRevealed)
	{
		if (isMine)
		{
			SpriteCodes::DrawCellMINE(leftUp, gfx);
		}
		else
		{
			switch (numOfMineAround)
			{
			case 0:
				SpriteCodes::DrawCellSAFE(leftUp, gfx);
				break;
			case 1:
				SpriteCodes::DrawCellONE(leftUp, gfx);
				break;
			case 2:
				SpriteCodes::DrawCellTWO(leftUp, gfx);
				break;
			case 3:
				SpriteCodes::DrawCellTHREE(leftUp, gfx);
				break;
			case 4:
				SpriteCodes::DrawCellFOUR(leftUp, gfx);
				break;
			case 5:
				SpriteCodes::DrawCellFIVE(leftUp, gfx);
				break;
			case 6:
				SpriteCodes::DrawCellSIX(leftUp, gfx);
				break;
			case 7:
				SpriteCodes::DrawCellSEVEN(leftUp, gfx);
				break;
			case 8:
				SpriteCodes::DrawCellEIGHT(leftUp, gfx);
				break;
			default:
				assert(false); // it should not happen
				break;
			}
		}
	}
	else
	{
		switch (status)
		{
		case FLAG:
			SpriteCodes::DrawCellFLAG(leftUp, gfx);
			break;
		case HIDDEN:
			SpriteCodes::DrawCellHIDDEN(leftUp, gfx);
			break;
		case SUSPECTED:
			SpriteCodes::DrawCellSUSPECTED(leftUp, gfx);
			break;
		default:
			assert(false); // this should not happen
			break;
		}
	}
}

void Board::Cell::DrawEnd(Graphics & gfx) const
{
	if (isRevealed)
	{
		if (isMine)
		{
			SpriteCodes::DrawCellMINE(leftUp, gfx);
		}
		else
		{
			switch (numOfMineAround)
			{
			case 0:
				SpriteCodes::DrawCellSAFE(leftUp, gfx);
				break;
			case 1:
				SpriteCodes::DrawCellONE(leftUp, gfx);
				break;
			case 2:
				SpriteCodes::DrawCellTWO(leftUp, gfx);
				break;
			case 3:
				SpriteCodes::DrawCellTHREE(leftUp, gfx);
				break;
			case 4:
				SpriteCodes::DrawCellFOUR(leftUp, gfx);
				break;
			case 5:
				SpriteCodes::DrawCellFIVE(leftUp, gfx);
				break;
			case 6:
				SpriteCodes::DrawCellSIX(leftUp, gfx);
				break;
			case 7:
				SpriteCodes::DrawCellSEVEN(leftUp, gfx);
				break;
			case 8:
				SpriteCodes::DrawCellEIGHT(leftUp, gfx);
				break;
			default:
				assert(false); // it should not happen
				break;
			}
		}
	}
	else
	{
		switch (status)
		{
		case FLAG:
			if (isMine)
			{
				SpriteCodes::DrawCellFLAGMINE(leftUp, gfx);
			}
			else
			{
				SpriteCodes::DrawCellNOTMINE(leftUp, gfx);
			}
			break;
		case HIDDEN:
			if (isMine)
			{
				SpriteCodes::DrawCellHIDDENMINE(leftUp, gfx);
			}
			else
			{
				SpriteCodes::DrawCellHIDDEN(leftUp, gfx);
			}
			break;
		case SUSPECTED:
			if (isMine)
			{
				SpriteCodes::DrawCellSUSPECTEDMINE(leftUp, gfx);
			}
			else
			{
				SpriteCodes::DrawCellSUSPECTED(leftUp, gfx);
			}
			break;
		default:
			assert(false); // this should not happen
			break;
		}
	}
}

void Board::Cell::Initialize(Location leftUp_, CellStatus status_)
{
	leftUp = leftUp_;
	status = status_;
}

void Board::Cell::ClickRight()
{
	switch (status)
	{
	case HIDDEN:
		status = FLAG;
		break;
	case FLAG:
		status = SUSPECTED;
		break;
	case SUSPECTED:
		status = HIDDEN;
		break;
	default:
		assert(false); //this should not happen
		break;
	}
}

void Board::Cell::Reveal()
{
	isRevealed = true;
}

bool Board::Cell::IsMine() const
{
	return isMine;
}

void Board::Cell::SetMine()
{
	isMine = true;
}

bool Board::Cell::IsRevealed() const
{
	return isRevealed;
}

bool Board::Cell::CanBeRevealed() const
{
	assert(!isRevealed);
	return status != FLAG;
}

void Board::Cell::SetNumOfMineAround(int num)
{
	numOfMineAround = num;
}

int Board::Cell::GetNumOfMineAround() const
{
	return numOfMineAround;
}

bool Board::Cell::IsFlagged() const
{
	return status==FLAG;
}

Location Board::Cell::GetLeftUp() const
{
	return leftUp;
}


