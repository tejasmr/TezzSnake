cmake_minimum_required ( 
	VERSION 
	3.16 
)

project ( TezzSnake )

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

add_executable (
	app

	src/Artist.cpp
	src/Direction.cpp
	src/Game.cpp
	src/Main.cpp
	src/Snake.cpp
	src/Timer.cpp
	src/Window.cpp

	include/Artist.h
	include/Definitions.h
	include/Direction.h
	include/Game.h
	include/Grid.h
	include/Main.h
	include/Point2d.h
	include/Point2f.h
	include/Range.h
	include/Size.h
	include/Snake.h
	include/Timer.h
	include/Window.h
)

set(glfw3_DIR "C:/Program Files (x86)/GLFW/lib/cmake/glfw3/")
find_package( OpenGL REQUIRED )
find_package( glfw3 REQUIRED )
target_link_libraries(app OpenGL::GL glfw)