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
	gfx( wnd )
{
	std::random_device rd;
	std::mt19937_64 rng(rd());
	std::uniform_int_distribution<int> distX(0, gfx.ScreenWidth - Poo::width);
	std::uniform_int_distribution<int> distY(0, gfx.ScreenHeight - Poo::height);
	poo0.x = distX(rng);
	poo0.y = distY(rng);
	poo1.x = distX(rng);
	poo1.y = distY(rng);
	poo2.x = distX(rng);
	poo2.y = distY(rng);

	poo0.vx = 1;
	poo0.vy = 1;
	poo1.vx = -1;
	poo1.vy = 1;
	poo2.vx = 1;
	poo2.vy = -1;
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
	if (isGameStart)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			dude.y -= 3;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			dude.y += 3;
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			dude.x -= 3;
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			dude.x += 3;
		}
		
		dude.Update();

		if (!poo0.isEaten)
		{
			poo0.isEaten = dude.IsCollide(poo0.x, poo0.y, Poo::width, Poo::height);
			poo0.Update();
		}
		if (!poo1.isEaten)
		{
			poo1.isEaten = dude.IsCollide(poo1.x, poo1.y, Poo::width, Poo::height);
			poo1.Update();
		}
		if (!poo2.isEaten)
		{
			poo2.isEaten = dude.IsCollide(poo2.x, poo2.y, Poo::width, Poo::height);
			poo2.Update();
		}
		if (poo0.isEaten&&poo1.isEaten&&poo2.isEaten)
		{
			isGameOver = true;
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			isGameStart = true;
		}
	}
}

void Game::ComposeFrame()
{
	if (isGameStart)
	{
		if (isGameOver)
		{
			gameover.Draw(gfx, 358, 268);
		}

		dude.Draw(gfx);
		if (!poo0.isEaten)
		{
			poo0.Draw(gfx);
		}
		if (!poo1.isEaten)
		{
			poo1.Draw(gfx);
		}
		if (!poo2.isEaten)
		{
			poo2.Draw(gfx);
		}
	}
	else
	{
		title.Draw(gfx, 325, 212);
	}
}
