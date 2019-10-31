#pragma once
#include"Graphics.h"
class Dude
{
public:
	Dude(int x_1, int y_1)
	{
		x = x_1;
		y = y_1;
	}
	void ClampXY();
	void Draw(Graphics& gfx)const;
	bool IsCollide(int x2, int y2, int width2, int height2);
	void AddX(int a);
	void AddY(int a);
	int GetX()const;
	int GetY()const;
private:
	int x;
	int y;
public:
	static constexpr int width = 20;
	static constexpr int height = 20;

};

