#include "Dude.h"
#include "Graphics.h"

void Dude::ClampXY()
{
	if (x < 0)
	{
		x = 0;
	}
	else if (int(x) + width - 1 >= Graphics::ScreenWidth)
	{
		x = float(Graphics::ScreenWidth - width);
	}
	else
	{
		
	}

	if (y < 0)
	{
		y = 0;
	}
	else if (int(y) + height - 1 >= Graphics::ScreenHeight)
	{
		y = float(Graphics::ScreenHeight - height);
	}
	else
	{
		
	}
}

void Dude::Update(const Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		y -= 3;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		y += 3;
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		x -= 3;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		x += 3;
	}
}

void Dude::Draw(Graphics& gfx)const
{
	const int x = int(Dude::x);
	const int y = int(Dude::y);
	gfx.PutPixel(7 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 0 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 1 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 1 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 2 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 2 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 3 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 3 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 3 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 4 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 4 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 4 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 5 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 5 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 6 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 6 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 6 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 7 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 7 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 7 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(3 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(4 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(5 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(12 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(13 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(14 + x, 8 + y, 255, 255, 255);
	gfx.PutPixel(15 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 8 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 8 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 9 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 9 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 10 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(14 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 10 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 10 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(7 + x, 11 + y, 20, 14, 18);
	gfx.PutPixel(8 + x, 11 + y, 18, 11, 14);
	gfx.PutPixel(9 + x, 11 + y, 18, 12, 14);
	gfx.PutPixel(10 + x, 11 + y, 18, 12, 14);
	gfx.PutPixel(11 + x, 11 + y, 21, 13, 16);
	gfx.PutPixel(12 + x, 11 + y, 24, 11, 15);
	gfx.PutPixel(13 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(15 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 11 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 11 + y, 0, 0, 0);
	gfx.PutPixel(0 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(2 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(6 + x, 12 + y, 23, 9, 23);
	gfx.PutPixel(7 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(10 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(11 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(12 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(13 + x, 12 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(16 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 12 + y, 254, 221, 88);
	gfx.PutPixel(19 + x, 12 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(5 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(10 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(11 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(12 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(13 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 13 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 13 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 13 + y, 0, 0, 0);
	gfx.PutPixel(1 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(3 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(9 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 14 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(14 + x, 14 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 14 + y, 254, 221, 88);
	gfx.PutPixel(18 + x, 14 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 15 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(9 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 15 + y, 251, 192, 224);
	gfx.PutPixel(14 + x, 15 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 15 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 15 + y, 0, 0, 0);
	gfx.PutPixel(2 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 16 + y, 254, 221, 88);
	gfx.PutPixel(4 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(6 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(7 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(8 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(9 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(10 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(11 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(12 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(13 + x, 16 + y, 251, 192, 224);
	gfx.PutPixel(14 + x, 16 + y, 135, 26, 68);
	gfx.PutPixel(15 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 16 + y, 254, 221, 88);
	gfx.PutPixel(17 + x, 16 + y, 0, 0, 0);
	gfx.PutPixel(3 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(4 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(13 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(15 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(16 + x, 17 + y, 0, 0, 0);
	gfx.PutPixel(5 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(6 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(8 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(9 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(10 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(11 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(12 + x, 18 + y, 254, 221, 88);
	gfx.PutPixel(13 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(14 + x, 18 + y, 0, 0, 0);
	gfx.PutPixel(7 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(8 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(9 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(10 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(11 + x, 19 + y, 0, 0, 0);
	gfx.PutPixel(12 + x, 19 + y, 0, 0, 0);

}

bool Dude::IsCollide(float x2, float y2, int width2, int height2)
{
	const float box1Left = x;
	const float box1Right = x + float(width - 1);
	const float box1Up = y;
	const float box1Down = y + float(height - 1);
	const float box2Left = x2;
	const float box2Right = x2 + float(width2 - 1);
	const float box2Up = y2;
	const float box2Down = y2 + float(height2 - 1);
	return box1Left <= box2Right && box1Right >= box2Left &&
		box1Up <= box2Down && box1Down >= box2Up;
}


float Dude::GetX() const
{
	return x;
}

float Dude::GetY() const
{
	return y;
}
