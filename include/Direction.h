#pragma once

#ifndef TEZZSNAKE_DIRECTION_H
#define TEZZSNAKE_DIRECTION_H

#include "Range.h"
#include "Point2d.h"

class Direction {
public:
	static Range row;
	static Range col;

	static Point2d LEFT;
	static Point2d RIGHT;
	static Point2d UP;
	static Point2d DOWN;

	static void Move( Point2d, int&, int& );

	static bool Condition( Point2d, int, int );
};

#endif // TEZZSNAKE_DIRECTION_H