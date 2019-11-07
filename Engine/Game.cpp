/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng(std::random_device()()),
	xDist(0,Board::widthNum-1),
	yDist(0,Board::heightNum-1),	
	board((Graphics::ScreenWidth-Board::widthNum*Board::width)/2, (Graphics::ScreenHeight - Board::heightNum*Board::height) / 2),
	food({ xDist(rng),yDist(rng) })
{
	std::uniform_int_distribution<int> xDistSnake(1, Board::widthNum - 2);
	std::uniform_int_distribution<int> yDistSnake(1, Board::heightNum - 2);
	Location headLoc;
	do
	{
		headLoc = { xDistSnake(rng),yDistSnake(rng) };
	} while (snake.TestCollision(food.GetLoc()));

	std::uniform_int_distribution<int> distSnake(-1, 1);
	Location deltaLoc;
	do
	{
		deltaLoc = { distSnake(rng),distSnake(rng) };
	} while ((abs(deltaLoc.x)+abs(deltaLoc.y))!=1);

	snake.Init(headLoc, deltaLoc);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	switch (status)
	{
	case TITLE:
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			status = PLAYING;
		}
		break;
	case PLAYING:
		snake.GetInput(wnd.kbd);
		++snakeCounter;
		++obstacleCounter;
		if (obstacleCounter >= snakeDuration*obstacleStepNum)
		{
			Location obstacleLoc;
			do
			{
				obstacleLoc = { xDist(rng),yDist(rng) };
			} while (snake.TestCollision(obstacleLoc)|| obstacle.TestCollision(obstacleLoc)||
				obstacleLoc==food.GetLoc()||snake.TestHeadAround(obstacleLoc));
			obstacle.AddOne(obstacleLoc);
			obstacleCounter = 0;
		}
		if (snakeCounter >= snakeDuration)
		{
			switch (snake.Move(food.GetLoc(), obstacle))
			{
			case Snake::EMPTY:
				break;
			case Snake::FOOD:
				Location foodLoc;
				do
				{
					foodLoc = { xDist(rng),yDist(rng) };
				} while (snake.TestCollision(foodLoc) || obstacle.TestCollision(foodLoc));
				food.SetLoc(foodLoc);
				break;
			case Snake::HIT:
				status = OVER;
				break;
			}
			snakeCounter = 0;
		}
		break;
	case OVER:
		break;
	}
}

void Game::DrawWall()
{
	const int xLeftUp = board.GetX() - wallDim;
	const int yLeftUp = board.GetY() - wallDim;
	const int boardWidth = Board::width*Board::widthNum;
	const int boardHeight = Board::height*Board::heightNum;
	const int xRightDown = board.GetX() + boardWidth + wallDim;
	const int yRightDown = board.GetY() + boardHeight + wallDim;
	gfx.DrawRectDimColor(xLeftUp, yLeftUp, wallDim, 2 * wallDim + boardHeight, wallColor);
	gfx.DrawRectDimColor(xLeftUp, yLeftUp, 2 * wallDim + boardWidth, wallDim, wallColor);
	gfx.DrawRectDimColor(xRightDown, yRightDown, -wallDim, -2 * wallDim - boardHeight, wallColor);
	gfx.DrawRectDimColor(xRightDown, yRightDown, -2 * wallDim - boardWidth, -wallDim, wallColor);
}

void Game::ComposeFrame()
{
	switch (status)
	{
	case TITLE:
		sprite.DrawTitle((Graphics::ScreenWidth-SpriteCodex::titleWidth)/2,
			(Graphics::ScreenHeight - SpriteCodex::titleHeight) / 2, gfx);
		break;
	case PLAYING:
		board.ResetColor();
		snake.DrawToBoard(board);
		food.DrawToBoard(board);
		obstacle.DrawToBoard(board);
		board.Draw(gfx);
		DrawWall();
		break;
	case OVER:
		board.Draw(gfx);
		DrawWall();
		sprite.DrawGameOver((Graphics::ScreenWidth - SpriteCodex::overWidth) / 2,
			(Graphics::ScreenHeight - SpriteCodex::overHeight) / 2, gfx);
		break;
	}
}
