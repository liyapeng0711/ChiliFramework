#include "Timer.h"



Timer::Timer()
{
}

float Timer::TimeFrame()
{
	std::chrono::steady_clock::time_point pre = preTime;
	preTime = std::chrono::steady_clock::now();
	std::chrono::duration<float>runtime = preTime - pre;
	return runtime.count();
}


