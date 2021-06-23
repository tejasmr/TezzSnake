#pragma once 

#ifndef TEZZSNAKE_ARTIST_H
#define TEZZSNAKE_ARTIST_H

#include <GLFW/glfw3.h>

#include "Definitions.h"
#include "Size.h"
#include "Point2f.h"
#include "Grid.h"

class Artist {
private:

public:
	static void UseColor( float, float, float );
	static void DrawGrid( Offset, Grid, Size );
	static void DrawRect( Point2f, Point2f, Offset, Size );
	static void DrawRect( Point2f, Point2f, Offset );
	static void DrawRect( Point2f, Point2f, Size );
	static void DrawRect( Point2f, Point2f );
};

#endif // TEZZSNAKE_ARTIST_H