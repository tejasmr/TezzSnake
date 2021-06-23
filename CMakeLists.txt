cmake_minimum_required ( 
	VERSION 
	3.16 
)

project ( TezzSnake )

set ( CMAKE_CXX_STANDARD 17 )

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


find_package( OpenGL REQUIRED )
# find_package( glfw3 REQUIRED )
include_directories(C:/GL/glfw/include)

target_link_libraries (
	app
	C:/GL/glfw/lib-vc2019/glfw3.lib
	${OPENGL_LIBRARIES}
)