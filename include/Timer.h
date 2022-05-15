#pragma once

#ifndef TEZZSNAKE_TIMER_H
#define TEZZSNAKE_TIMER_H

#include <functional>
#include "C:/ProgramData/chocolatey/include/GLFW/glfw3.h"

struct Timer {
private:
	double current;
	double previous;
	double change;
	double accumulator;
	double velocity;

public:
	Timer( double );
	void createTask( std::function<void()> task );
};

#endif // TEZZSNAKE_TIMER_H