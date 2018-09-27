#include "MyMazeGenerator.hpp"
#include "Maze.hpp"
#include <ics46/factory/DynamicFactory.hpp>
#include <random>
#include <iostream>

ICS46_DYNAMIC_FACTORY_REGISTER(MazeGenerator, MyMazeGenerator, "Rodney's Algorithm (Required)");

MyMazeGenerator::MyMazeGenerator () {

}

void MyMazeGenerator::generateMaze (Maze & maze) {

	bool ** visited = new bool * [maze.getHeight()];
	for (int i = 0; i < maze.getHeight(); ++i)
	{
		visited [i] = new bool [maze.getWidth()];
	}

	for (int i = 0; i < maze.getHeight(); i++) {
		for (int j = 0; j < maze.getWidth(); j++) {
			visited [i][j] = false;
		}
	}

	maze.addAllWalls();

	MyMazeGenerator::visitCell (0, 0, maze, visited);

}

int MyMazeGenerator::randDirection () {
		return distribution(engine);
}

void MyMazeGenerator::visitCell (int x, int y, Maze & maze, bool ** visited) {
	visited [y][x] = true;

	while (true) {

		if (y == 0 && x == 0) {
			if (visited [y][x + 1] == true && visited [y + 1][x] == true) {
				break;
			}
		}
		else if (y == maze.getHeight() - 1 && x == maze.getWidth() - 1) {
			if (visited [y][x - 1] == true && visited [y - 1][x] == true) {
				break;
			}
		}
		else if (y == maze.getHeight() - 1 && x == 0) {
			if (visited [y][x + 1] == true && visited [y - 1][x] == true) {
				break;
			}
		}
		else if (y == 0 && x == maze.getWidth() - 1) {
			if (visited [y][x - 1] == true && visited [y + 1][x] == true) {
				break;
			}
		}
		else if (y == 0) {
			if (visited [y][x - 1] == true && visited [y + 1][x] == true && visited [y][x + 1] == true) {
				break;
			}
		}
		else if (y == maze.getHeight() - 1) {
			if (visited [y][x - 1] == true && visited [y - 1][x] == true && visited [y][x + 1] == true) {
				break;
			}
		}
		else if (x == 0) {
			if (visited [y][x + 1] == true && visited [y + 1][x] == true && visited [y - 1][x] == true) {
				break;
			}
		}
		else if (x == maze.getWidth() - 1) {
			if (visited [y][x - 1] == true && visited [y - 1][x] == true && visited [y + 1][x] == true) {
				break;
			}
		}
		else {
			if (visited [y][x - 1] == true && visited [y][x + 1] == true && visited [y - 1][x] == true && visited [y + 1][x] == true) {
				break;
			}
		}


		int temp = randDirection();

		if (temp == 1) { //up
			
			if (y != 0) {
				if (visited [y - 1][x] == false) {
					maze.removeWall(x, y, Direction::up);
					MyMazeGenerator::visitCell (x, y - 1, maze, visited);
				}
			}
			
		}
		else if (temp == 2) { //right
			
			if (x != maze.getWidth() - 1) {
				if (visited [y][x + 1] == false) {
					maze.removeWall(x, y, Direction::right);
					MyMazeGenerator::visitCell (x + 1, y, maze, visited);
				}
			}
			
		}
		else if (temp == 3) { //down
			
			if (y != maze.getHeight() - 1) {
				if (visited [y + 1][x] == false) {
					maze.removeWall(x, y, Direction::down);
					MyMazeGenerator::visitCell (x, y + 1, maze, visited);
				}
			}
			
		}
		else if (temp == 4) { //left
			
			if (x != 0) {
				if (visited [y][x - 1] == false) {
					maze.removeWall(x, y, Direction::left);
					MyMazeGenerator::visitCell (x - 1, y, maze, visited);
				}
			}
			
		}

	}


}
