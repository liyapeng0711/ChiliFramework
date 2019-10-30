#pragma once
#include"Graphics.h"
class Poo
{
public:
	void Update();
	void Draw(Graphics& gfx)const;
	int x;
	int y;
	int vx;
	int vy;
	bool isEaten = false;
	static constexpr int width = 24;
	static constexpr int height = 24;
};