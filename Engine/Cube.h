#pragma once
#include"Dude.h"
#include"Graphics.h"
#include "Colors.h"
#include "Vec2.h"

class Cube
{
public:
	Cube(Vec2 pos_1)
	{
		pos = pos_1;
	}
	void Draw(Graphics& gfx);
	bool IsEaten() const;
	void UpdateColor();
	void UpdateColorChili();//from read to white
	void TestCollide(const Dude& dude);
	void InitXY(Vec2 pos_1);
private:
	Vec2 pos;
	bool isEaten = false;
	int count = 0;
	int halfFreq = 100;
	bool isIncreasing = true;
	Color color = { 127,0,0 };
public:
	static const int width = 20;
	static const int height = 20;
};

