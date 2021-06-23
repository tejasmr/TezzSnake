#include "../include/Game.h"

Game::Game( String _name, int _width, int _height, Count count ):
	window(_name, _width, _width),
	offset(0, 0),
	grid(0, 0, 0.0, 0.0),
	snake(Count(count.x, count.y)),
	apple(-1, -1) {
	
	if ( window.size.width < window.size.height )
		offset = Offset(100.0, 100.0 + (float)(window.size.height - window.size.width) / 2.0);
	else
		offset = Offset(100.0 + (float)(window.size.width - window.size.height) / 2.0, 100.0);
	
	
	grid.count.x = count.x;
	grid.count.y = count.x;
	grid.size.width = ( (float)window.size.width - 2.0*offset.x ) / grid.count.x;
	grid.size.height = ( (float)window.size.height - 2.0*offset.y ) / grid.count.y;

}

Point2d Game::GetDirection() {
	return snake.previousDirection;
}

void Game::Play() {
	window.Init();
	Timer timer(2.0);
	while( !window.ShouldClose() ) {
		window.StartRendering();
		window.Setup();
		window.Resize();
		timer.createTask([&]() {
			Move( snake.GetDirection() );
		});
		SetKeyMap(callback);
		Update();
		Artist::UseColor(0.3, 1.0, 0.3);
		snake.SetOffset(offset);
		snake.SetSize(grid.size);
		snake.Draw();
		SpawnApple();
		Artist::UseColor(0.3, 0.3, 0.3);
		Artist::DrawGrid(
			offset,
			grid,
			window.size
		);
	window.EndRendering();
	}

	window.Destroy();
}

void Game::SetKeyMap( GLFWkeyfun _callback ) {
	callback = _callback;
	window.SetKeyMap(callback);
}

void Game::Update() {
	if ( window.size.width < window.size.height )
		offset = Offset(100.0, 100.0 + ((float)(window.size.height - window.size.width)) / 2.0);
	else
		offset = Offset(100.0 + ((float)(window.size.width - window.size.height)) / 2.0, 100.0);
	
	grid.size.width = ( (float)window.size.width - 2.0*offset.x ) / grid.count.x;
	grid.size.height = ( (float)window.size.height - 2.0*offset.y ) / grid.count.y;
}

void Game::Move( Point2d direction ) {
	snake.Move( direction );
}

void Game::SpawnApple() {
	std::vector<Point2d> availablePoints;
	for( int i=0; i<grid.count.x; i++ ) {
		for( int j=0; j<grid.count.y; j++ ) {
			if(!snake.at[i][j]) 
				availablePoints.emplace_back( Point2d(i, j) );
		}
	}
	srand(time(0));
	int randomCoordinate = (rand() % availablePoints.size());
	if( apple.x == -1 && apple.y == -1 ) {
		apple = Point2d(availablePoints[randomCoordinate].x, availablePoints[randomCoordinate].y);
	}
	if( apple.x == snake.GetHead().x && apple.y == snake.GetHead().y ) {
		snake.EatApple(apple);
		randomCoordinate = (rand() % availablePoints.size());
		apple = Point2d(availablePoints[randomCoordinate].x, availablePoints[randomCoordinate].y);
	}
	DrawApple();
}

void Game::DrawApple() {
	Artist::UseColor(1.0, 0.2, 0.2);
	Artist::DrawRect(Point2f(apple.x, apple.y), Point2f(apple.x+1, apple.y+1), offset, grid.size);
}