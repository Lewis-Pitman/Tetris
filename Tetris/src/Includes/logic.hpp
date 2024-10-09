#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "Includes/screen.hpp"

extern bool blockHasBeenHeld;
extern bool holdUsedThisTurn;

extern bool gameActive;
extern int framerate;
extern int speed;
extern int linesCleared;
extern int nextBlock;
extern int heldBlock;
extern int score;

class Game {
public:
	Block GetRandomBlock();
	Block GetRandomBlock(int type);
	void Run();
};

#endif