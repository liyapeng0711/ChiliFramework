#pragma once
#include"Graphics.h"
#include"Keyboard.h"

class Dude
{
public:
	Dude(float x_1, float y_1)
	{
		x = x_1;
		y = y_1;
	}
	void ClampXY();
	void Update(const Keyboard& kbd);
	void Draw(Graphics& gfx)const;
	bool IsCollide(float x2, float y2, int width2, int height2);
	float GetX()const;
	float GetY()const;
private:
	float x;
	float y;
public:
	static constexpr int width = 20;
	static constexpr int height = 20;

};

