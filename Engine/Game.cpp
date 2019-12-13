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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{

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
	float dt = timer.TimeFrame();
	switch (status)
	{
	case LEVEL_CHOOSING:
		status = levels.Update(wnd.mouse);
		if (status == PLAYING)
		{
			board.Initialize(levels.GetLevel());
			bar.Initialize(levels.GetLevel());
		}
		break;
	case PLAYING:
		status = board.Update(wnd.mouse);
		if (status == GAME_WINNER || status == GAME_OVER)
		{
			bar.StopClock();
		}
		bar.UpdateClock(dt);
		bar.UpdateFlag(board.GetRemainMineNum());
		if (bar.IsRefresh(wnd.mouse))
		{
			levels.Initialize();
		}
		break;
	case GAME_OVER:
	case GAME_WINNER:
		if (bar.IsRefresh(wnd.mouse))
		{
			levels.Initialize();
		}
		break;
	default:
		break;
	}
}

void Game::ComposeFrame()
{
	switch (status)
	{
	case LEVEL_CHOOSING:
		levels.Draw(gfx);
		break;
	case PLAYING:
		board.Draw(gfx);
		bar.Draw(gfx);
		break;
	case GAME_OVER:
	case GAME_WINNER:
		board.DrawEnd(gfx);
		bar.Draw(gfx);
		break;
	default:
		break;
	}
}
