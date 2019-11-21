#include "Ball.h"
#include <assert.h>

Ball::Ball(Vec2 center, Vec2 velocity)
	:
	center(center),
	velocity(velocity)
{
}

Rect Ball::GetRect() const
{
	return Rect::RectCenter(center, width/2.0f, height/2.0f);
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

void Ball::Update(float dt)
{
	center += velocity*dt;
}

void Ball::ReboundInRect(const Rect & rect)
{
	const float left = rect.GetLeftUp().x;
	const float right = rect.GetRightDown().x;
	const float up = rect.GetLeftUp().y;
	const float down = rect.GetRightDown().y;
	if (center.x - width / 2.0f < left)
	{
		center.x = left + width / 2.0f;
		ReboundX();
	}
	else if (center.x + width / 2.0f > right)
	{
		center.x = right - width / 2.0f;
		ReboundX();
	}
	if (center.y - height / 2.0f < up)
	{
		center.y = up + height / 2.0f;
		ReboundY();
	}
	else if (center.y + height / 2.0f > down)
	{
		center.y = down - height / 2.0f;
		ReboundY();
	}
}

bool Ball::ReboundOutRect(const Rect & rect)
{
	bool isRebound = false;
	if (GetRect().TestCollision(rect))
	{
		const float x = center.x;
		const float y = center.y;
		const float vx = velocity.x;
		const float vy = velocity.y;
		const float left = rect.GetLeftUp().x;
		const float right = rect.GetRightDown().x;
		const float up = rect.GetLeftUp().y;
		const float down = rect.GetRightDown().y;
		if (x >= left&&x <= right)// in up or down area
		{
			if (y <= up)
			{
				if (vy > 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					//this should not happen
				}
			}
			else if (y >= down)
			{
				if (vy < 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					//this should not happen
				}
			}
			else
			{
				//center is inside the rect, not possible theoritically
				//assert(false);
			}
		}
		else if (y >= up&&y <= down) //in left or right area
		{
			if (x >= right)
			{
				if (vx < 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					//this should not happen
				}
			}
			else if (x <= left)
			{
				if (vx > 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					//this should not happen
				}
			}
			else
			{
				//center is inside the rect, not possible theoritically
				//assert(false);
			}
		}
		else if (x < left&&y < up)//in leftup area
		{
			if (vx >= 0.0f&&vy >= 0.0f)
			{
				float tx = (left - x) / (vx + 0.000001f);
				float ty = (up - y) / (vy + 0.000001f);
				if (tx <= ty)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					ReboundY();
					isRebound = true;
				}
			}
			else
			{
				if (vx >= 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else if (vy >= 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					//this should not happen
				}
			}
		}
		else if (x < left&&y > down)//in leftdown area
		{
			if (vx >= 0.0f&&vy <= 0.0f)
			{
				float tx = (left - x) / (vx + 0.000001f);
				float ty = (down - y) / (-vy + 0.000001f);
				if (tx <= ty)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					ReboundY();
					isRebound = true;
				}
			}
			else
			{
				if (vx >= 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else if (vy <= 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					//this should not happen
				}
			}
		}
		else if (x > right&&y < up)//in rightup area
		{
			if (vx <= 0.0f&&vy >= 0.0f)
			{
				float tx = (x - right) / (-vx + 0.000001f);
				float ty = (up - y) / (vy + 0.000001f);
				if (tx <= ty)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					ReboundY();
					isRebound = true;
				}
			}
			else
			{
				if (vx <= 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else if (vy >= 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					//this should not happen
				}
			}
		}
		else if (x > right&&y > down)//in rightdown area
		{
			if (vx <= 0.0f&&vy <= 0.0f)
			{
				float tx = (x - right) / (-vx + 0.000001f);
				float ty = (y - down) / (-vy + 0.000001f);
				if (tx <= ty)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					ReboundY();
					isRebound = true;
				}
			}
			else
			{
				if (vx <= 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else if (vy <= 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					//this should not happen
				}
			}
		}
		else
		{
			//no other possibility
			assert(false);
		}
	}
	return isRebound;
}

bool Ball::ReboundOutRect(const Rect & rect, const Vec2& speed)
{
	bool isRebound = false;
	if (GetRect().TestCollision(rect))
	{
		const float x = center.x;
		const float y = center.y;
		const float vx = velocity.x;
		const float vy = velocity.y;
		const float left = rect.GetLeftUp().x;
		const float right = rect.GetRightDown().x;
		const float up = rect.GetLeftUp().y;
		const float down = rect.GetRightDown().y;
		if (x >= left&&x <= right)// in up or down area
		{
			if (y <= up)
			{
				if (vy > 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					velocity.y = -speed.y;
				}
			}
			else if (y >= down)
			{
				if (vy < 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					velocity.y = speed.y;
				}
			}
			else
			{
				//center is inside the rect, not possible theoritically
				//assert(false);
			}
		}
		else if (y >= up&&y <= down) //in left or right area
		{
			if (x >= right)
			{
				if (vx < 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					velocity.x = speed.x;
				}
			}
			else if (x <= left)
			{
				if (vx > 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					velocity.x = -speed.x;
				}
			}
			else
			{
				//center is inside the rect, not possible theoritically
				//assert(false);
			}
		}
		else if (x < left&&y < up)//in leftup area
		{
			if (vx >= 0.0f&&vy >= 0.0f)
			{
				float tx = (left - x) / (vx + 0.000001f);
				float ty = (up - y) / (vy + 0.000001f);
				if (tx <= ty)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					ReboundY();
					isRebound = true;
				}
			}
			else
			{
				if (vx >= 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else if (vy >= 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					velocity.x = -speed.x;
					velocity.y = -speed.y;
				}

			}
		}
		else if (x < left&&y > down)//in leftdown area
		{
			if (vx >= 0.0f&&vy <= 0.0f)
			{
				float tx = (left - x) / (vx + 0.000001f);
				float ty = (down - y) / (-vy + 0.000001f);
				if (tx <= ty)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					ReboundY();
					isRebound = true;
				}
			}
			else
			{
				if (vx >= 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else if (vy <= 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					velocity.x = -speed.x;
					velocity.y = speed.y;
				}
			}
		}
		else if (x > right&&y < up)//in rightup area
		{
			if (vx <= 0.0f&&vy >= 0.0f)
			{
				float tx = (x - right) / (-vx + 0.000001f);
				float ty = (up - y) / (vy + 0.000001f);
				if (tx <= ty)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					ReboundY();
					isRebound = true;
				}
			}
			else
			{
				if (vx <= 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else if (vy >= 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					velocity.x = speed.x;
					velocity.y = -speed.y;
				}
			}
		}
		else if (x > right&&y > down)//in rightdown area
		{
			if (vx <= 0.0f&&vy <= 0.0f)
			{
				float tx = (x - right) / (-vx + 0.000001f);
				float ty = (y - down) / (-vy + 0.000001f);
				if (tx <= ty)
				{
					ReboundX();
					isRebound = true;
				}
				else
				{
					ReboundY();
					isRebound = true;
				}
			}
			else
			{
				if (vx <= 0.0f)
				{
					ReboundX();
					isRebound = true;
				}
				else if (vy <= 0.0f)
				{
					ReboundY();
					isRebound = true;
				}
				else
				{
					velocity.x = speed.x;
					velocity.y = speed.y;
				}
			}
		}
		else
		{
			//no other possibility
			assert(false);
		}
	}
	return isRebound;
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}

Vec2 Ball::GetCenter() const
{
	return center;
}
