#pragma once

#ifndef TEZZSNAKE_GAME_H
#define TEZZSNAKE_GAME_H

#include <cstdlib>

#include "Window.h"
#include "Definitions.h"
#include "Artist.h"
#include "Snake.h"
#include "Timer.h"

class Game {
private:
	Offset offset;
	Grid grid;
	Snake snake;
	GLFWkeyfun callback;
	Apple apple;

public:
	Window window;
	Game( String, int, int, Count );

	Point2d GetDirection();

	void Play();
	void Update();
	void SetKeyMap( GLFWkeyfun );

	void DrawApple();
	void SpawnApple();

	void Move( Point2d );
};

#endif //TEZZSNAKE_GAME_H