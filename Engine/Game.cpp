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
	gfx(wnd),
	originWall((float(Graphics::ScreenWidth) - widthRequired) / 2.0f, (float(Graphics::ScreenHeight) - heightRequired) / 2.0f),
	ball(originWall + Vec2(widthRequired / 2.0f, heightRequired / 2.0f), Vec2(-100.0f, -100.0f)),
	wall(originWall, widthRequired, heightRequired),
	padder(Rect(originWall+ Vec2(widthRequired/2.0f-padderWidth/2.0f, heightRequired - originPadderBottom - padderHeight), padderWidth, padderHeight))
{
	const Vec2 ori = originWall + Vec2(originBrickWidth, originBrickHeight);
	Color brickColor[4] = { Colors::Blue, Colors::Cyan, Colors::Magenta,Colors::Red };
	for (int i = 0; i < brickWidthNum; ++i)
	{
		for (int j = 0; j < brickHeightNum; ++j)
		{
			const Vec2 leftUp = ori + Vec2(float(i)*brickWidth + float(i - 1)*brickBetween, float(j)*brickHeight + float(j - 1)*brickBetween);
			bricks[i + j*brickWidthNum] = Brick(Rect(leftUp, brickWidth, brickHeight), brickColor[j % 4]);
		}
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
	float dt = timer.Mark();
	ball.Update(dt);
	padder.Update(wnd.kbd, dt);

	ball.ReboundInRect(wall);
	for (auto& i : bricks)
	{
		if (!i.IsDestroyed() && ball.ReboundOutRect(i.GetRect()))
		{
			i.Destroy();
		}
	}
	ball.ReboundOutRect(padder.GetRect(),padder.GetSpeed());
	padder.LimitInRect(wall);
}

void Game::ComposeFrame()
{
	gfx.DrawRect(wall, Colors::Gray);
	for (auto& i : bricks)
	{
		if (!i.IsDestroyed())
		{
			i.Draw(gfx);
		}
	}
	padder.Draw(gfx);
	ball.Draw(gfx);
}
