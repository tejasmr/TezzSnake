#pragma once

#ifndef TEZZSNAKE_POINT2F_H
#define TEZZSNAKE_POINT2F_H

struct Point2f {
	float x, y;
	Point2f( float _x, float _y ) {
		x = _x;
		y = _y;
	}
};

#endif // TEZZSNAKE_POINT2F_H