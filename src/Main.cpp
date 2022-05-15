#include "../include/Main.h"
#include <iostream>
#include "C:/ProgramData/chocolatey/include/GLFW/glfw3.h"

int main() {
	game = new Game("TezzSnake", 600.0, 600.0, Count(40, 40));
	game->Play(Move);
}


void Move(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action != GLFW_PRESS)
        return;
    if(key == GLFW_KEY_RIGHT || key == 'D') {

        if (game->GetDirection() != Direction::RIGHT) 
            game->Move(Direction::RIGHT);
    
    } else if(key == GLFW_KEY_LEFT || key == 'A') {
        
        if (game->GetDirection() != Direction::LEFT) 
            game->Move(Direction::LEFT);

    } else if(key == GLFW_KEY_UP || key == 'W') {
        
        if (game->GetDirection() != Direction::UP) 
            game->Move(Direction::UP);

    } else if(key == GLFW_KEY_DOWN || key == 'S') {
        
        if (game->GetDirection() != Direction::DOWN) 
            game->Move(Direction::DOWN);
        
    }
}