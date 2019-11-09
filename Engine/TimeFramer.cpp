#include "TimeFramer.h"
using namespace std::chrono;


TimeFramer::TimeFramer()
{
	last = steady_clock::now();
}


TimeFramer::~TimeFramer()
{
}

float TimeFramer::Mark()
{
	auto old = last;
	last = steady_clock::now();
	duration<float> step = last - old;
	return step.count();
}
