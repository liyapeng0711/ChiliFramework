#pragma once
#include "Rect.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball(Vec2 center, Vec2 vlocity);
	Rect GetRect()const;
	void Draw(Graphics& gfx)const;
	void Update(float dt);
	void ReboundX();
	void ReboundY();
private:
	Vec2 center;
	static constexpr float width = 14.0f;
	static constexpr float height = 14.0f;
	Vec2 velocity;
};

