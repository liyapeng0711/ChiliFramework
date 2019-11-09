#pragma once
class Vec2
{
public:
	Vec2();
	Vec2(float x_1, float y_1);
	~Vec2();
	Vec2 operator+(const Vec2& rhs)const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator-(const Vec2& rhs)const;
	Vec2& operator-=(const Vec2& rhs);
	Vec2 operator*(float rhs)const;
	Vec2& operator*=(float rhs);
	float GetLength()const;
	float GetLengthSq()const;
	Vec2 GetNormalized()const;
	Vec2& Normalized();
	
	float x;
	float y;
};

