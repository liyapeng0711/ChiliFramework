#pragma once
#include "Mouse.h"
#include"GameStatus.h"
#include "Graphics.h"
#include "SpriteCodes.h"
#include "Location.h"
#include "RectI.h"
#include "Level.h"


class Levels
{
public:
	Levels() = default;
public:
	GameStatus Update(Mouse& mouse);
	void Draw(Graphics& gfx);
	Level GetLevel()const;
	void Initialize();

private:
	bool isPointed = false;
	Level level = EASY;
	Location locEasy = {300, 150};	// leftUp
	Location locMiddle = { 300, 225 };  // leftUp
	Location locDifficult = { 300, 300 };  // leftUp
	const int width = 200;
	const int height = 50;	
	const int padding = 2;
	const Color paddingColor = Colors::Red;
	RectI rectEasy = RectI(locEasy, width, height);
	RectI rectMiddle = RectI(locMiddle, width, height);
	RectI rectDifficult = RectI(locDifficult, width, height);

};

