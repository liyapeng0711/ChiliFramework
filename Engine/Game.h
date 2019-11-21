/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Rect.h"
#include "Ball.h"
#include "Vec2.h"
#include "Brick.h"
#include "Padder.h"
#include "Sound.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */

	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	float brickWidth = 50.0f;
	float brickHeight = 25.0f;
	float brickBetween = 2.0f;
	static constexpr int brickWidthNum = 10;
	static constexpr int brickHeightNum = 4;
	float originBrickWidth = brickHeight;
	float originBrickHeight = brickWidth;

	float padderWidth = brickWidth*1.2f;
	float padderHeight = brickHeight;
	float originPadderBottom = brickWidth;

	float widthRequired = (brickWidth + brickBetween)*brickWidthNum - brickBetween + 2.0f*originBrickWidth;
	float heightRequired = 4.0f*((brickHeight + brickBetween)*brickHeightNum - brickBetween) + originBrickHeight + originPadderBottom;	

	Vec2 originWall;
	FrameTimer timer;
	Ball ball;
	Rect wall;
	Brick bricks[brickWidthNum*brickHeightNum];
	Padder padder;
	Sound soundBrick;
	Sound soundWall;
	Sound soundDead;
	Sound soundPrepare;
	float timeForSound = 0.0f;
	enum GameStatus
	{
		TITLE,
		PLAYING,
		OVER,
	}status = TITLE;
	/********************************/
};