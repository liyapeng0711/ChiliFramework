#include "Ball.h"

Ball::Ball(Vec2 center, Vec2 velocity)
	:
	center(center),
	velocity(velocity)
{
}

Rect Ball::GetRect() const
{
	return Rect::RectCenter(center, width, height);
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

void Ball::Update(float dt)
{
	center += velocity*dt;
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}
