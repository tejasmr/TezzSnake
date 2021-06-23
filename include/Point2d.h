#pragma once

#ifndef TEZZSNAKE_POINT2D_H
#define TEZZSNAKE_POINT2D_H

struct Point2d {
	int x, y;
	Point2d( int _x, int _y ) {
		x = _x;
		y = _y;
	}

	bool operator==(const Point2d &p) const {
		return (x == p.x) && (y == p.y);
	}

	bool operator!=(const Point2d &p) const {
		return !(*this == p);
	}
};

#endif // TEZZSNAKE_POINT2D_H