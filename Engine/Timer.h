#pragma once
#include<chrono>
class Timer
{
public:
	Timer();
	float TimeFrame();
private:
	std::chrono::steady_clock::time_point preTime = std::chrono::steady_clock::now();
};

