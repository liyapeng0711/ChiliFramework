#pragma once
#include"Dude.h"
#include"Graphics.h"
class Cube
{
public:
	Cube(int x_1, int y_1)
	{
		x = x_1;
		y = y_1;
	}
	void Draw(Graphics& gfx)const;
	bool IsEaten() const;
	void TestCollide(const Dude& dude);
	void InitXY(int x_1, int y_1);
private:
	int x;
	int y;
	bool isEaten = false;
public:
	static const int width = 20;
	static const int height = 20;
};

