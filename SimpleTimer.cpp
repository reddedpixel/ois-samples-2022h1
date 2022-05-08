#include "SimpleTimer.h"

SimpleTimer::SimpleTimer()
{
	start = std::chrono::high_resolution_clock::now();
}

SimpleTimer::~SimpleTimer()
{
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	float result = duration.count();
	std::cout<<"Time passed "<<result<<" seconds"<<std::endl;

}