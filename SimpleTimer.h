#pragma once
#include <chrono>
#include <iostream>

class SimpleTimer
{
public:
	SimpleTimer();
	~SimpleTimer();
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	//std::chrono::time_point<std::chrono::_V2::system_clock> start, end;
	std::chrono::duration<float> duration;
};