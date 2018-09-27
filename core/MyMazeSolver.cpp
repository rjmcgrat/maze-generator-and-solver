#include "MyMazeSolver.hpp"
#include "Maze.hpp"
#include "MazeSolution.hpp"
#include <ics46/factory/DynamicFactory.hpp>

ICS46_DYNAMIC_FACTORY_REGISTER(MazeSolver, MyMazeSolver, "Rodney's Solver (Required)");

MyMazeSolver::MyMazeSolver () {

}

void MyMazeSolver::solveMaze (const Maze & maze, MazeSolution & mazeSolution) {
	mazeSolution.restart();
	MyMazeSolver::advance(maze, mazeSolution);
}

void MyMazeSolver::advance (const Maze & maze, MazeSolution & mazeSolution) {
	if (!maze.wallExists(mazeSolution.getCurrentCell().first, mazeSolution.getCurrentCell().second, Direction::down)) {
		if ((mazeSolution.getStartingCell().first == mazeSolution.getCurrentCell().first &&
			mazeSolution.getStartingCell().second == mazeSolution.getCurrentCell().second)  ||
			mazeSolution.getMovements().back() != Direction::up) {
			mazeSolution.extend(Direction::down);
			if (mazeSolution.isComplete()) return;
			MyMazeSolver::advance(maze, mazeSolution);
			if (mazeSolution.isComplete()) return;
			mazeSolution.backUp();
		}
	}
	if (!maze.wallExists(mazeSolution.getCurrentCell().first, mazeSolution.getCurrentCell().second, Direction::right)) {
		if ((mazeSolution.getStartingCell().first == mazeSolution.getCurrentCell().first &&
			mazeSolution.getStartingCell().second == mazeSolution.getCurrentCell().second)  ||
			mazeSolution.getMovements().back() != Direction::left) {
			mazeSolution.extend(Direction::right);
			if (mazeSolution.isComplete()) return;
			MyMazeSolver::advance(maze, mazeSolution);
			if (mazeSolution.isComplete()) return;
			mazeSolution.backUp();
		}
	}
	if (!maze.wallExists(mazeSolution.getCurrentCell().first, mazeSolution.getCurrentCell().second, Direction::up)) {
		if ((mazeSolution.getStartingCell().first == mazeSolution.getCurrentCell().first &&
			mazeSolution.getStartingCell().second == mazeSolution.getCurrentCell().second)  ||
			mazeSolution.getMovements().back() != Direction::down) {
			mazeSolution.extend(Direction::up);
			if (mazeSolution.isComplete()) return;
			MyMazeSolver::advance(maze, mazeSolution);
			if (mazeSolution.isComplete()) return;
			mazeSolution.backUp();
		}
	}
	if (!maze.wallExists(mazeSolution.getCurrentCell().first, mazeSolution.getCurrentCell().second, Direction::left)) {
		if ((mazeSolution.getStartingCell().first == mazeSolution.getCurrentCell().first &&
			mazeSolution.getStartingCell().second == mazeSolution.getCurrentCell().second)  ||
			mazeSolution.getMovements().back() != Direction::right) {
			mazeSolution.extend(Direction::left);
			if (mazeSolution.isComplete()) return;
			MyMazeSolver::advance(maze, mazeSolution);
			if (mazeSolution.isComplete()) return;
			mazeSolution.backUp();
		}
	}
}
