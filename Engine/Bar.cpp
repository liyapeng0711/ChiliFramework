#include "Bar.h"
#include<assert.h>

void Bar::UpdateClock(float dt)
{
	clockNum += dt;
}

void Bar::UpdateFlag(int num)
{
	flagNum = num;
}

bool Bar::IsRefresh(Mouse & mouse)
{
	Location loc = Location{ mouse.GetPosX(), mouse.GetPosY() };
	if (mouse.LeftIsPressed() && GetRefreshRect().TestInside(loc))
	{
		return true;
	}
	return false;
}

void Bar::StopClock()
{
	isStopped = true;
}

void Bar::Draw(Graphics & gfx)
{
	DrawClock(gfx);
	DrawRefresh(gfx);
	DrawFlagNum(gfx);
}

void Bar::Initialize(Level level)
{
	switch (level)
	{
	case EASY:
		locClock.x = (Graphics::ScreenWidth - BoardPara::easyCellSize*BoardPara::easyCellXNum) / 2;
		locFlagNum.x = Graphics::ScreenWidth - locClock.x - BoardPara::easyCellSize;
		locRefresh.x = (locClock.x + locFlagNum.x) / 2;
		locFlagNum.x-= BoardPara::easyCellSize;
		locClock.y -= 2 * BoardPara::easyCellSize;
		locRefresh.y -= 2 * BoardPara::easyCellSize;
		locFlagNum.y -= 2 * BoardPara::easyCellSize;
		cubeSize = BoardPara::easyCellSize;
		break;
	case MIDDLE:
		locClock.x = (Graphics::ScreenWidth - BoardPara::middleCellSize*BoardPara::middleCellXNum) / 2;
		locFlagNum.x = Graphics::ScreenWidth - locClock.x - BoardPara::middleCellSize;
		locRefresh.x = (locClock.x + locFlagNum.x) / 2;
		locFlagNum.x -= BoardPara::middleCellSize;
		locClock.y -= 2 * BoardPara::middleCellSize;
		locRefresh.y -= 2 * BoardPara::middleCellSize;
		locFlagNum.y -= 2 * BoardPara::middleCellSize;
		cubeSize = BoardPara::middleCellSize;
		break;
	case DIFFICULT:
		locClock.x = (Graphics::ScreenWidth - BoardPara::difficultCellSize*BoardPara::difficultCellXNum) / 2;
		locFlagNum.x = Graphics::ScreenWidth - locClock.x - BoardPara::difficultCellSize;
		locRefresh.x = (locClock.x + locFlagNum.x) / 2;
		locFlagNum.x -= BoardPara::difficultCellSize;
		locClock.y -= 2 * BoardPara::difficultCellSize;
		locRefresh.y -= 2 * BoardPara::difficultCellSize;
		locFlagNum.y -= 2 * BoardPara::difficultCellSize;
		cubeSize = BoardPara::difficultCellSize;
		break;
	}
	isStopped = false;
	flagNum = 0;
	clockNum = 0.0f;
}

RectI Bar::GetRefreshRect() const
{
	return RectI(locRefresh, cubeSize, cubeSize);
}

void Bar::DrawClock(Graphics & gfx) const
{
	int num = int(clockNum);
	assert(num <= 999);
	Location leftUp3 = locClock;
	Location leftUp2 = leftUp3 + Location{ cubeSize,0 };
	Location leftUp1 = leftUp2 + Location{ cubeSize,0 };
	int num3 = num / 100;
	int num2 = num % 100 / 10;
	int num1 = num % 10 / 1;
	SpriteCodes::DrawNum(leftUp3, gfx, num3);
	SpriteCodes::DrawNum(leftUp2, gfx, num2);
	SpriteCodes::DrawNum(leftUp1, gfx, num1);	
}

void Bar::DrawRefresh(Graphics & gfx) const
{
	SpriteCodes::DrawRefresh(locRefresh, gfx);
}

void Bar::DrawFlagNum(Graphics & gfx) const
{
	assert(flagNum <= 99);
	Location leftUp2 = locFlagNum;
	Location leftUp1 = leftUp2 + Location{ cubeSize,0 };
	int num2 = flagNum / 10;
	int num1 = flagNum % 10 / 1;
	SpriteCodes::DrawNum(leftUp2, gfx, num2);
	SpriteCodes::DrawNum(leftUp1, gfx, num1);
}
