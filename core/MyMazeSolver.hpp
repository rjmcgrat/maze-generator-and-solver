#include "MazeSolver.hpp"

#ifndef MYMAZESOLVER_HPP
#define MYMAZESOLVER_HPP

class MyMazeSolver : public MazeSolver {
	public:
		MyMazeSolver ();
		virtual void solveMaze(const Maze& maze, MazeSolution& mazeSolution);
		void advance(const Maze & maze, MazeSolution & mazeSolution);
};

#endif
