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
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= 3;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += 3;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= 3;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += 3;
	}
	if (wnd.kbd.KeyIsPressed('W'))
	{
		height -= 1;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		height += 1;
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		width -= 1;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		width += 1;
	}
	if (wnd.mouse.LeftIsPressed())
	{
		width = wnd.mouse.GetPosX() - x;
		height = wnd.mouse.GetPosY() - y;
	}
	ClampRectDim(x, y, width, height);
	
}

void Game::ClampRectDim(int & x, int & y, int & width, int & height)
{
	if (width > 0)
	{
		if (x < 0)
		{
			x = 0;
		}
		while (x + width > Graphics::ScreenWidth)
		{
			if (x > Graphics::ScreenWidth - 1)
			{
				x = Graphics::ScreenWidth - 1;
			}
			else
			{
				width = Graphics::ScreenWidth - x;
			}
		}
	}
	else
	{
		while (x + width < 0)
		{
			if (x < 0)
			{
				x = 0;
			}
			else
			{
				width = -x;
			}
		}
		if (x > Graphics::ScreenWidth)
		{
			x = Graphics::ScreenWidth;
		}
	}

	if (height > 0)
	{
		if (y < 0)
		{
			y = 0;
		}
		while (y + height > Graphics::ScreenHeight)
		{
			if (y > Graphics::ScreenHeight - 1)
			{
				y = Graphics::ScreenHeight - 1;
			}
			else
			{
				height = Graphics::ScreenHeight - y;
			}
		}
	}
	else
	{
		while (y + height < 0)
		{
			if (y < 0)
			{
				y = 0;
			}
			else
			{
				height = -y;
			}
		}
		if (y > Graphics::ScreenHeight)
		{
			y = Graphics::ScreenHeight;
		}
	}
}

void Game::ComposeFrame()
{
	gfx.DrawRectDim(x, y, width, height);
}
