#pragma once

#ifndef TEZZSNAKE_GRID_H
#define TEZZSNAKE_GRID_H

#include "Size.h"
#include "Point2f.h"

class Grid {
public:
	Point2f count;
	Size size;
	
	Grid( Point2f _count, Size _size ):
		count(_count),
		size(_size) {}

	Grid( float _x, float _y, float _width, float _height ):
		count(_x, _y),
		size(_width, _height) {}

	Grid( float _x, float _y, Size _size ):
		count(_x, _y),
		size(_size) {}

	Grid( Point2f _count, float _width, float _height ):
		count(_count),
		size(_width, _height) {}

};

#endif // TEZZSNAKE_GRID_H