#pragma once
struct Location 
{
	Location operator+(Location loc)
	{
		return{ x + loc.x, y + loc.y };
	}
	bool operator==(Location loc)
	{
		return x == loc.x&&y == loc.y;
	}
	bool operator==(Location loc) const
	{
		return x == loc.x&&y == loc.y;
	}
	int x;
	int y;
};