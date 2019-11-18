#pragma once
#include"Rect.h"
#include"Colors.h"
#include"Graphics.h"
#include"Keyboard.h"
class Padder
{
public:
	Padder() = default;
	Padder(Rect rect);
	void Update(Keyboard& kbd, float dt);
	void LimitInRect(Rect rect_);
	void Draw(Graphics& gfx)const;
	Rect GetRect()const;

private:
	Rect rect;//whole rect
	static constexpr Color color=Colors::Green;//center color
	static constexpr float paddingWidth = 20.0f;//toward inside
	static constexpr Color paddingColor = Colors::Red;//two sides color
	float speed = 200;
};

