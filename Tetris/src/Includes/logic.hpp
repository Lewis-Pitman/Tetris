#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "globals.hpp"
#include "screen.hpp"

extern bool blockHasBeenHeld;
extern bool holdUsedThisTurn;

class Game {
public:
	Block GetRandomBlock();
	Block GetRandomBlock(int type);
	void Run();
};

#endif