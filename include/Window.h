#pragma once

#ifndef TEZZSNAKE_WINDOW_H
#define TEZZSNAKE_WINDOW_H

#include "C:/ProgramData/chocolatey/include/GLFW/glfw3.h"

#include "Definitions.h"
#include "Size.h"

class Window {
private:
	String name;

public:
	GLFWwindow* window;
	Size size;
	
	Window( String, int, int );
	void Init();
	void StartRendering();
	void Resize();
	void Setup();
	void SetKeyMap( GLFWkeyfun );
	void EndRendering();
	void Destroy();

	bool ShouldClose();
};


#endif // TEZZSNAKE_WINDOW_H