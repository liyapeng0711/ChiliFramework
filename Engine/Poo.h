#pragma once
#include"Graphics.h"
#include"Dude.h"
class Poo
{
public:
	Poo(int x_1, int y_1, int vx_1, int vy_1)
	{
		x = x_1;
		y = y_1;
		vx = vx_1;
		vy = vy_1;
	}
	void UpdateAndClamp();
	void TestCollide(const Dude& dude);
	void Draw(Graphics& gfx)const;
	bool IsEaten()const;
private:
	int x;
	int y;
	int vx;
	int vy;
	bool isEaten = false;
public:
	static constexpr int width = 24;
	static constexpr int height = 24;
};