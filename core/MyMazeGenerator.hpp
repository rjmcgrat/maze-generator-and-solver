#include "MazeGenerator.hpp"
#include <iostream>
#include <random>

#ifndef MYMAZEGENERATOR_HPP
#define MYMAZEGENERATOR_HPP

class MyMazeGenerator : public MazeGenerator {
	public:
		MyMazeGenerator ();
		virtual void generateMaze (Maze & maze);
		void visitCell (int x, int y, Maze & maze, bool ** visited);
		int randDirection ();
	private:
		std::random_device device;
		std::default_random_engine engine { device () };
		std::uniform_int_distribution<int> distribution {1, 4};
};

#endif
