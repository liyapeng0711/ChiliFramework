#include "Levels.h"


GameStatus Levels::Update(Mouse & mouse)
{
	Location loc = { mouse.GetPosX(),mouse.GetPosY() };
	if (rectEasy.TestInside(loc))
	{
		isPointed = true;
		level = EASY;
	}
	else if (rectMiddle.TestInside(loc))
	{
		isPointed = true;
		level = MIDDLE;
	}
	else if (rectDifficult.TestInside(loc))
	{
		isPointed = true;
		level = DIFFICULT;
	}
	else
	{
		isPointed = false;
	}

	if (isPointed && mouse.LeftIsPressed())
	{
		return PLAYING;
	}

	return LEVEL_CHOOSING;
}

void Levels::Draw(Graphics & gfx)
{
	SpriteCodes::DrawLevelEasy(locEasy, gfx);
	SpriteCodes::DrawLevelMiddle(locMiddle, gfx);
	SpriteCodes::DrawLevelDifficult(locDifficult, gfx);
	if (isPointed)
	{
		switch (level)
		{
		case EASY:
			rectEasy.Expand(padding).DrawRing(gfx, padding, paddingColor);
			break;
		case MIDDLE:
			rectMiddle.Expand(padding).DrawRing(gfx, padding, paddingColor);
			break;
		case DIFFICULT:
			rectDifficult.Expand(padding).DrawRing(gfx, padding, paddingColor);
			break;
		default:
			;
		}
	}
}

Level Levels::GetLevel() const
{
	return level;
}

void Levels::Initialize()
{
	isPointed = false;
}
