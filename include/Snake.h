#pragma once

#ifndef TEZZSNAKE_SNAKE_H
#define TEZZSNAKE_SNAKE_H


#include <iostream>
#include <vector>
#include <deque>

#include "Point2d.h"
#include "Size.h"
#include "Definitions.h"
#include "Artist.h"
#include "Direction.h"

class Snake {
private:
	Head head;
	Count count;
	Offset offset;
	Size size;

public:
	std::vector<std::vector<bool> > at;
	Point2d previousDirection;
	std::deque<Point2d> body;
	
	Snake( Count );
	
	void SetOffset( Offset );
	void SetSize( Size );
	Head GetHead();
	
	Point2d GetDirection();

	void Draw();
	void Draw( Offset _offset, Size _size );
	void Move( Point2d );

	void EatApple( Apple );
};

#endif // TEZZSNAKE_SNAKE_H