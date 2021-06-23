#include "../include/Artist.h"

void Artist::UseColor( float red, float green, float blue ) {
	glColor3f( red, green, blue );
}

void Artist::DrawRect( Point2f p1, Point2f p2, Offset offset, Size size ) {
	glRectd(
		offset.x + p1.x * size.width,
		offset.y + p1.y * size.height,
		offset.x + p2.x * size.width,
		offset.y + p2.y * size.height
	);
}

void Artist::DrawRect( Point2f p1, Point2f p2, Offset offset ) {
	DrawRect( p1, p2, offset, Size(1, 1) );
}

void Artist::DrawRect( Point2f p1, Point2f p2, Size size ) {
	DrawRect( p1, p2, Offset(0, 0), size );
}

void Artist::DrawRect( Point2f p1, Point2f p2 ) {
	DrawRect( p1, p2, Offset(0, 0), Size(1, 1) );
}

void Artist::DrawGrid( Offset offset, Grid grid, Size windowSize ) {
	glBegin( GL_LINES );

	for( int i=0; i<=grid.count.x; i++ ) {
		glVertex2f ( 
			offset.x, 
			offset.y + (float)i * (float)grid.size.width 
		);
		glVertex2f ( 
			(float)windowSize.width - offset.x, 
			offset.y + (float)i * (float)grid.size.width 
		);
	}

	for( int i=0; i<=grid.count.y; i++) {
		glVertex2f (
			offset.x + (float)i * (float)grid.size.height,
			offset.y
		);
		glVertex2f (
			offset.x + (float)i * (float)grid.size.height,
			(float)windowSize.height - offset.y
		);
	}

	glEnd();
}