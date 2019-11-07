#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Colors.h"
class Board
{
public:
	Board(int x_1, int y_1);
	~Board();
	void Draw(Graphics& gfx)const;
	void SetLocColor(const Location loc, Color c);
	void ResetColor();
	int GetX()const;
	int GetY()const;
public:
	static constexpr int widthNum = 20;
	static constexpr int heightNum = 20;
	static constexpr int width = 20;
	static constexpr int height = 20;
	static constexpr Color emptyColor = Color{ 150, 150, 150 };
	static constexpr Color snakeHeadColor = Color{ 0, 0, 255 };
	static constexpr Color snakeBodyColor = Color{ 0, 255, 0 };
	static constexpr Color foodColor = Color{ 255, 0, 0 };
	static constexpr Color obstacleColor = Color{ 0, 0, 0 };
private:
	int x;
	int y;
	Color color[widthNum*heightNum];
};

