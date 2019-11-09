#pragma once
#include<chrono>
class TimeFramer
{
public:
	TimeFramer();
	~TimeFramer();
	float Mark();
private:
	std::chrono::steady_clock::time_point last;
};

