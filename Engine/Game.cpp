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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	distX(0.0f, float(gfx.ScreenWidth - Poo::width)),
	distY(0.0f, float(gfx.ScreenHeight - Poo::height)),
	dude(Vec2(distX(rng), distY(rng))),
	cube(Vec2(distX(rng),distY(rng))),
	counter(50,20)
{
	std::uniform_real_distribution<float> distV(-180.f, 180.f);
	for (int i = 0; i < size; ++i)
	{
		float vx = 0.0f;
		float vy = 0.0f;
		while (vx == 0.0f && vy == 0.0f)
		{
			vx = distV(rng);
			vy = distV(rng);
		}
		poo[i].Init(Vec2(distX(rng), distY(rng)), Vec2(vx, vy));
	}
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
	float dt = timeFramer.Mark();
	if (isGameStart&&!isGameOver)
	{
		dude.Update(wnd.kbd, wnd.mouse, dt);
		dude.ClampXY();
		for (int i = 0; i < size; ++i)
		{
			if (!poo[i].IsEaten())
			{
				poo[i].UpdateAndClamp(dt);
				poo[i].TestCollide(dude);
			}
		}
		isGameOver = false;
		for (int i = 0; i < size; ++i)
		{
			isGameOver = isGameOver || poo[i].IsEaten();
		}
		cube.UpdateColorChili();
		cube.TestCollide(dude);
		if (cube.IsEaten())
		{
			counter.AddOne();
			cube.InitXY(Vec2(distX(rng), distY(rng)));
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
		counter.Draw(gfx);
		dude.Draw(gfx);
		for (int i = 0; i < size; ++i)
		{
			poo[i].Draw(gfx);
		}
		cube.Draw(gfx);
	}
	else
	{
		title.Draw(gfx, 325, 212);
	}
}
