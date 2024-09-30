#include <cstdlib> //Used for rand()
#include <ctime> //Used for srand(time(NULL)) to get a random seed
#include <conio.h> //_kbhit() and _getch()
#include <windows.h> //Used for sleep()

#include "logic.hpp"

char input;
bool softDropSwitch;
int framerate{ 4 };

Block Game::GetRandomBlock() {
    Block generatedBlock(rand() % 8);
    return generatedBlock;
}

void Game::Run() {
	Screen screen;
	srand(time(NULL));
	Block block = GetRandomBlock();

	while (gameActive) {
        block.Down();
		screen.ClearScreen();
		system("cls");


        if (_kbhit()) { //if key has been pressed

            input = _getch(); //assign input to the key that was pressed

            switch (input) {
            case 'q'://rotate left
                block.Rotate(1);
                break;
            case 'e'://rotate right
                block.Rotate(2);
                break;
            case 'a'://move left
                block.Move(1);
                break;
            case 'd'://move right
                block.Move(2);
                break;
            case 'w'://hold block
                heldBlock = block.type;
                //logic to hold block
                break;
            case 's':
                if (!softDropSwitch) {
                    framerate = 8;
                    softDropSwitch = true;
                }
                else {
                    framerate = 4;
                    softDropSwitch = false;
                }
            default:
                break;
            }
        }

        screen.PushBlockToScreen(block, pCurrentBlockData);

        if (bottomOfScreen) {
            //logic
        }

        screen.DrawScreen();
        Sleep(1000 / framerate);
	}
}