#pragma once
#include "Graphics.h"
class Counter
{
public:
	Counter(int x_1, int y_1)
	{
		x = x_1;
		y = y_1;
	}
	void Draw(Graphics& gfx)const;
	void AddOne();
	int ShowNum()const;
private:
	int x;
	int y;
	int num = 0;
public:
	static const int width = 10;
	static const int height = 20;
	static const int gap = 2;
	static const int max = 20;

};

