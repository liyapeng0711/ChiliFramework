#pragma once
#include"Graphics.h"
#include"Keyboard.h"
#include"Mouse.h"
#include"Vec2.h"

class Dude
{
public:
	Dude(Vec2 pos_1)
	{
		pos = pos_1;
	}
	void ClampXY();
	void Update(const Keyboard& kbd, const Mouse& mouse, float dt);
	void Draw(Graphics& gfx)const;
	bool IsCollide(Vec2 vec, int width2, int height2);
	Vec2 GetPos()const;
private:
	Vec2 pos;
	float speed = 240.0f;	//60 is the frequency of drawing
public:
	static constexpr int width = 20;
	static constexpr int height = 20;

};

