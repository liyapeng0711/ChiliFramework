#include "Location.h"

Location Location::operator+(Location loc)
{
	return{ x + loc.x,y + loc.y };
}

Location Location::operator-(Location loc)
{
	return{ x - loc.x,y - loc.y };
}
