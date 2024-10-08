#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Includes/blocks.hpp"

extern char (*pTiles)[20];
extern char placedBlocks[10][20];

class Screen {
private:
    //---
    //main screen
    char tiles[10][20]; //tiles[x value][y value] -> the top left of the grid is tiles[0][0] while the bottom right is tiles[10][20].
    int screenWidth{ 10 };
    int screenHeight{ 20 };
    int spacing{ 2 };

    //side screens
    char nextTiles[6][6] = {
        {' ', 'N', 'E', 'X', 'T', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
    };
    char holdTiles[6][6] = {
        {' ', 'H', 'O', 'L', 'D', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
    };

    //---

    void DrawMainScreen(int line);
    void DrawNextScreen(int line);
    void DrawHoldScreen(int line);
    void DrawLine(int width);

    void ClearNextScreen();
    void ClearHoldScreen();

    void FilledRowCheck();

public:
    Screen();
    void StartScreen();
    void GameOverScreen();
    void ClearScreen();
    void PushBlockToScreen(Block block, BlockData* data);
    void LockBlockToScreen(Block block, BlockData* data);
    void HoldBlock(int blockToHold);
    void NextBlock(int blockToNext);
    void DrawScreen();
};

#endif