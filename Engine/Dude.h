#pragma once
#include"Graphics.h"
class Dude
{
public:
	void Update();
	void Draw(Graphics& gfx)const;
	bool IsCollide(int x2, int y2, int width2, int height2);
	int x = 400;
	int y = 300;
	static constexpr int width = 20;
	static constexpr int height = 20;

};

