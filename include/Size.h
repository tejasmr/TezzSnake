#pragma once

#ifndef TEZZSNAKE_SIZE_H
#define TEZZSNAKE_SIZE_H

struct Size {
	float width, height;

	Size(float _width, float _height) {
		width = _width;
		height = _height;
	}
};

#endif // TEZZSNAKE_SIZE_H