#include "../include/Direction.h"

Range Direction::row(0, 0);
Range Direction::col(0, 0);

Point2d Direction::LEFT(-1, 0);
Point2d Direction::RIGHT(1, 0);
Point2d Direction::UP(0, -1);
Point2d Direction::DOWN(0, 1);

void Direction::Move( Point2d direction, int& i, int& j ) {
	if ( Condition(direction, i, j) ) {
		i += direction.x;
		j += direction.y;
	}
}

bool Direction::Condition( Point2d direction, int i, int j ) {
	return (
		i >= row.start - direction.x && 
		i < row.end - direction.x &&
		j >= col.start - direction.y &&
		j < col.end - direction.y
	);
}