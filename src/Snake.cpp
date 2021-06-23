#include "../include/Snake.h"

Snake::Snake( Count _count ):
	count(_count),
	head(0, 0),
	offset(0.0, 0.0),
	size(0.0, 0.0),
	previousDirection(0, 0) {
	
	previousDirection = Direction::RIGHT;

	for( int i=0; i<count.x; i++ ) {
		std::vector<bool> temp;
		for( int j=0; j<count.y; j++ ) {
			temp.push_back( false );
		}
		at.push_back( temp );
	}

	head.x = (int)(count.x / 2.0);
	head.y = (int)(count.y / 2.0);

	at[(int)head.x][(int)head.y] = true;
	body.push_back(head);

	Direction::row.start = 0;
	Direction::row.end = count.x;
	Direction::col.start = 0;
	Direction::col.end = count.y;
}

void Snake::SetOffset( Offset _offset ) {
	offset = _offset;
}

void Snake::SetSize( Size _size ) {
	size = _size;
}

Point2d Snake::GetDirection() {
	return previousDirection;
}

void Snake::Draw( Offset _offset, Size _size ) {
	offset = _offset;
	size = _size;
	Draw();
}

void Snake::Draw() {
	for(auto point: body) {
		Artist::DrawRect(Point2f(point.x, point.y), Point2f(point.x+1, point.y+1), offset, size);
	}
}

void Snake::Move( Point2d direction ) {
	if( 
		previousDirection.x - direction.x == 2 || 
		previousDirection.x - direction.x == -2 ||
		previousDirection.y - direction.y == 2 ||
		previousDirection.y - direction.y == -2
	) {
		return;
	}
	if( Direction::Condition( direction, head.x-direction.x, head.y-direction.y) ) {
		Direction::Move(direction, head.x, head.y);
		at[head.x-direction.x][head.y-direction.y] = false;
		body.pop_front();
		at[head.x][head.y] = true;
		body.push_back(head);
	}
	previousDirection = direction;
	Artist::UseColor(0.3, 1.0, 0.3);
	Snake::Draw();
}

void Snake::EatApple( Apple apple ) {
	Direction::Move(previousDirection, head.x, head.y);
	if( Direction::Condition( previousDirection, head.x-previousDirection.x, head.y-previousDirection.y) ) {
		at[head.x][head.y] = true;
		body.push_back(head);
	}
	Artist::UseColor(0.3, 1.0, 0.3);
	Snake::Draw();
}


Head Snake::GetHead() {
	return head;
}