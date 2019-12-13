#pragma once
struct Location
{
	Location operator+(Location loc);
	Location operator-(Location loc);
	int x;
	int y;
};