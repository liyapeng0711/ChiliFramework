#include "Vec2.h"
#include<cmath>


Vec2::Vec2()
{
}

Vec2::Vec2(float x_1, float y_1)
{
	x = x_1;
	y = y_1;
}


Vec2::~Vec2()
{
}

Vec2 Vec2::operator+(const Vec2 & rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 & Vec2::operator+=(const Vec2 & rhs)
{
	return *this = *this + rhs;
}

Vec2 Vec2::operator-(const Vec2 & rhs) const
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 & Vec2::operator-=(const Vec2 & rhs)
{
	return *this = *this - rhs;
}

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2(rhs*x, rhs*y);
}

Vec2 & Vec2::operator*=(float rhs)
{
	return *this = *this*rhs;
}

float Vec2::GetLength() const
{
	return sqrtf(GetLengthSq());
}

float Vec2::GetLengthSq() const
{
	return x*x + y*y;
}

Vec2 Vec2::GetNormalized() const
{
	float length = GetLength();
	if (length != 0.0f)
	{
		return *this*(1.0f / length);
	}
	return *this;
}

Vec2 & Vec2::Normalized()
{
	return *this = GetNormalized();
}
