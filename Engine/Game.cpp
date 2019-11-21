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
	padder(Rect(originWall+ Vec2(widthRequired/2.0f-padderWidth/2.0f, heightRequired - originPadderBottom - padderHeight), padderWidth, padderHeight)),
	soundBrick(L"Sounds\\arkbrick.wav"),
	soundWall(L"Sounds\\arkpad.wav"),
	soundDead(L"Sounds\\fart.wav"),
	soundPrepare(L"Sounds\\ready.wav")
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
	soundPrepare.Play();
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
	switch (status)
	{
	case TITLE:
		timeForSound += dt;
		if (timeForSound > 4.3f)
		{
			soundPrepare.Play();
			timeForSound = 0.0f;
		}
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			status = PLAYING;
			soundPrepare.StopAll();
		}
		break;
	case PLAYING:
	{
		ball.Update(dt);
		padder.Update(wnd.kbd, dt);

		if (ball.ReboundInRect(wall))
		{
			if (ball.IsDead())
			{
				soundDead.Play();
				status = OVER;
			}
			else
			{
				soundWall.Play();
			}
		}
		int destroyIndex;
		float centerDistSq;
		bool hasPre = false;
		for (int i = 0; i < brickWidthNum*brickHeightNum; ++i)
		{
			if (!bricks[i].IsDestroyed() && ball.GetRect().TestCollision(bricks[i].GetRect()))
			{
				if (!hasPre)
				{
					destroyIndex = i;
					centerDistSq = (bricks[i].GetRect().GetCenter() - ball.GetCenter()).GetLengthSq();
					hasPre = true;
				}
				else
				{
					float centerDistSqCur = (bricks[i].GetRect().GetCenter() - ball.GetCenter()).GetLengthSq();
					if (centerDistSqCur < centerDistSq)
					{
						destroyIndex = i;
						centerDistSq = centerDistSqCur;
					}
				}
			}
		}
		if (hasPre)
		{
			ball.ReboundOutRect(bricks[destroyIndex].GetRect());
			bricks[destroyIndex].Destroy();
			soundBrick.Play();
		}
		if (ball.ReboundOutRect(padder.GetRect(), padder.GetSpeed()))
		{
			soundWall.Play();
		}
		padder.LimitInRect(wall);
	}
	break;
	case OVER:
		break;
	}
}

void Game::ComposeFrame()
{
	switch (status)
	{
	case TITLE:
		SpriteCodex::DrawTitle(Vec2(float(Graphics::ScreenWidth / 2), float(Graphics::ScreenHeight / 2)), gfx);
		break;
	case PLAYING:
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
		break;
	case OVER:
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
		SpriteCodex::DrawGameOver(Vec2(float(Graphics::ScreenWidth / 2), float(Graphics::ScreenHeight / 2)), gfx);
		break;
	}
}
