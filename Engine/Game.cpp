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
	distX(0, gfx.ScreenWidth - Poo::width),
	distY(0, gfx.ScreenHeight - Poo::height),
	dude(300, 400),
	poo0(distX(rng), distY(rng), 1, 1),
	poo1(distX(rng), distY(rng), -1, 1),
	poo2(distX(rng), distY(rng), -1, -1),
	poo3(distX(rng), distY(rng), 1, -1),
	poo4(distX(rng), distY(rng), -1, 1),
	poo5(distX(rng), distY(rng), 1, -1),
	poo6(distX(rng), distY(rng), 1, 1),
	poo7(distX(rng), distY(rng), -1, 1),
	poo8(distX(rng), distY(rng), 1, -1)
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
	if (isGameStart)
	{
		dude.Update(wnd.kbd);		
		dude.ClampXY();

		if (!poo0.IsEaten())
		{
			poo0.UpdateAndClamp();
			poo0.TestCollide(dude);
		}
		if (!poo1.IsEaten())
		{
			poo1.UpdateAndClamp();
			poo1.TestCollide(dude);
		}
		if (!poo2.IsEaten())
		{
			poo2.UpdateAndClamp();
			poo2.TestCollide(dude);
		}
		if (!poo3.IsEaten())
		{
			poo3.UpdateAndClamp();
			poo3.TestCollide(dude);
		}
		if (!poo4.IsEaten())
		{
			poo4.UpdateAndClamp();
			poo4.TestCollide(dude);
		}
		if (!poo5.IsEaten())
		{
			poo5.UpdateAndClamp();
			poo5.TestCollide(dude);
		}
		if (!poo6.IsEaten())
		{
			poo6.UpdateAndClamp();
			poo6.TestCollide(dude);
		}
		if (!poo7.IsEaten())
		{
			poo7.UpdateAndClamp();
			poo7.TestCollide(dude);
		}
		if (!poo8.IsEaten())
		{
			poo8.UpdateAndClamp();
			poo8.TestCollide(dude);
		}
		if (poo0.IsEaten() &&poo1.IsEaten() &&poo2.IsEaten()&&
			poo3.IsEaten() && poo4.IsEaten() && poo5.IsEaten()&&
			poo6.IsEaten() && poo7.IsEaten() && poo8.IsEaten())
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
		if (!poo0.IsEaten())
		{
			poo0.Draw(gfx);
		}
		if (!poo1.IsEaten())
		{
			poo1.Draw(gfx);
		}
		if (!poo2.IsEaten())
		{
			poo2.Draw(gfx);
		}
		if (!poo3.IsEaten())
		{
			poo3.Draw(gfx);
		}
		if (!poo4.IsEaten())
		{
			poo4.Draw(gfx);
		}
		if (!poo5.IsEaten())
		{
			poo5.Draw(gfx);
		}
		if (!poo6.IsEaten())
		{
			poo6.Draw(gfx);
		}
		if (!poo7.IsEaten())
		{
			poo7.Draw(gfx);
		}
		if (!poo8.IsEaten())
		{
			poo8.Draw(gfx);
		}
	}
	else
	{
		title.Draw(gfx, 325, 212);
	}
}
