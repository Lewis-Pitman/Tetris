#include <iostream>
#include <conio.h> //windows specific terminal controls -> _kbhit checks if a key was pressed -> _getch gets the key pressed
#include <windows.h> //used for sleep() command

#include "Includes/screen.hpp"
#include "Includes/blocks.hpp"
#include "Includes/logic.hpp"
#include "Includes/globals.hpp"

int originX = 5;
int originY = 2;

bool gameActive{ true };
int nextBlock = 0;
int heldBlock = 0;

int main() {
    Game game;

    game.Run();

    return 0;
}