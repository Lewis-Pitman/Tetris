#include <cstdlib> //Used for rand()
#include <ctime> //Used for srand(time(NULL)) to get a random seed
#include <conio.h> //_kbhit() and _getch()
#include <windows.h> //Used for sleep()

#include "logic.hpp"

char input;
bool softDropSwitch;
int framerate{ 1 };
int temp;
int score{ 0 };
int speed{ 1 };
int linesCleared{ 0 };

Block Game::GetRandomBlock() {
    Block generatedBlock(rand() % 7);
    return generatedBlock;
}

Block Game::GetRandomBlock(int type) { //used for holding blocks
    Block generatedBlock(type);
    return generatedBlock;
}

void Game::Run() {
	Screen screen;
	srand(time(NULL));

    Block nextBlockToGet = GetRandomBlock();
	Block block = GetRandomBlock();

    nextBlock = nextBlockToGet.type;
    blockHasBeenHeld = false;
    holdUsedThisTurn = false;

    score = 0;
    speed = 1;
    linesCleared = 0;

    //screen.StartScreen();
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
                if (!blockHasBeenHeld && !holdUsedThisTurn) {
                    holdUsedThisTurn = true;
                    blockHasBeenHeld = true;
                    originX = 5;
                    originY = 2;

                    heldBlock = block.type;

                    block = nextBlock;
                    nextBlockToGet = GetRandomBlock();
                    nextBlock = nextBlockToGet.type;

                    block.rotation = 0;
                }
                else if(blockHasBeenHeld && !holdUsedThisTurn){
                    holdUsedThisTurn = true;
                    temp = block.type;
                    block = GetRandomBlock(heldBlock);
                    heldBlock = temp;

                    block.rotation = 0;
                    bottomOfScreen = false;
                }
                //logic to hold block
                break;
            case 's':
                if (!softDropSwitch) {
                    framerate = 10;
                    softDropSwitch = true;
                }
                else {
                    softDropSwitch = false;
                }
            default:
                break;
            }
        }

        if (softDropSwitch) {
            score++;
        }
        else {
            framerate = speed;
        }

        screen.PushBlockToScreen(block, pCurrentBlockData);

        if (bottomOfScreen) {
            screen.LockBlockToScreen(block, pCurrentBlockData);
            originX = 5;
            originY = 2;

            block = nextBlock;
            nextBlockToGet = GetRandomBlock();
            nextBlock = nextBlockToGet.type;

            block.rotation = 0;
            bottomOfScreen = false;
            holdUsedThisTurn = false;
        }

        block.type = block.type;
        screen.DrawScreen();

        Sleep(1000 / framerate);
	}
    screen.GameOverScreen();
}