#include "../include/Window.h"

Window::Window( String _name, int _width, int _height ):
	size(_width, _height) {
	name = _name;
}

void Window::Init() {
	
	if( !glfwInit() ) {
		return;
    }

    window = glfwCreateWindow(
        (int)size.width,
        (int)size.height,
        name,
        nullptr,
        nullptr
    );

    if ( !window ) {
        glfwTerminate();
		return;
    }

    glfwMakeContextCurrent( window );
}

void Window::StartRendering() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::Resize() {
	int _width, _height;
	glfwGetFramebufferSize (
		window, 
		&_width, 
		&_height
	);
	size.width = _width;
	size.height = _height;

	glViewport(0, 0, size.width, size.height);
}

void Window::Setup() {
	glMatrixMode( GL_PROJECTION );

	glLoadIdentity();

	glClear( GL_COLOR_BUFFER_BIT );

	glOrtho (
		0,
		size.width,
		size.height,
		0,
		0,
		1
	);
}

void Window::SetKeyMap( GLFWkeyfun callback ) {
	glfwSetKeyCallback( window, *callback );
}

void Window::EndRendering() {
	glfwSwapBuffers( window );

	glfwPollEvents();
}

void Window::Destroy() {
	glfwTerminate();
}

bool Window::ShouldClose() {
	return glfwWindowShouldClose( window );
}




