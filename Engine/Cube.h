#pragma once
#include"Dude.h"
#include"Graphics.h"
#include "Colors.h"

class Cube
{
public:
	Cube(int x_1, int y_1)
	{
		x = x_1;
		y = y_1;
	}
	void Draw(Graphics& gfx);
	bool IsEaten() const;
	void UpdateColor();
	void UpdateColorChili();//from read to white
	void TestCollide(const Dude& dude);
	void InitXY(int x_1, int y_1);
private:
	int x;
	int y;
	bool isEaten = false;
	int count = 0;
	int halfFreq = 100;
	bool isIncreasing = true;
	Color color = { 127,0,0 };
public:
	static const int width = 20;
	static const int height = 20;
};

