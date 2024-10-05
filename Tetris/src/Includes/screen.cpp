#include <iostream>
#include <iomanip>

#include "screen.hpp"
#include "blocks.hpp"

char (*pTiles)[20] = nullptr; //iniutialise the pointer to tiles


void Screen::ClearScreen() {
    int i{ 0 };
    int j{ 0 };

    for (i = 0; i < screenWidth; i++) {
        for (j = 0; j < screenHeight; j++) {
            tiles[i][j] = placedBlocks[i][j];
        }
    }

}

Screen::Screen() : screenWidth(10), screenHeight(20), spacing(2) { 
    ClearScreen(); 
    pTiles = tiles; 

    for (int i = 0; i < screenWidth; i++) {
        for (int j = 0; j < screenHeight; j++) {
            placedBlocks[i][j] = ' ';
        }
    }
}

void Screen::PushBlockToScreen(Block block, BlockData* data) {
    for (int i = 0; i < 4; i++) {
        tiles[data->blockData[block.type][block.rotation][0][i]][data->blockData[block.type][block.rotation][1][i]] = '#';
    }
}

void Screen::LockBlockToScreen(Block block, BlockData* data) {
    for (int i = 0; i < 4; i++) {
        placedBlocks[data->blockData[block.type][block.rotation][0][i]][data->blockData[block.type][block.rotation][1][i]] = '#';
    }
}

void Screen::ClearHoldScreen() {
    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < 6; j++) {//Clear the box but keep "HOLD" at the top
            holdTiles[i][j] = ' ';
        }
    }
}


void Screen::HoldBlock(int blockToHold) {
    switch (blockToHold) {
    case 0:
        ClearHoldScreen();
        holdTiles[2][3] = '#';
        holdTiles[3][2] = '#';
        holdTiles[2][2] = '#';
        holdTiles[3][3] = '#';
        break;
    case 1:
        ClearHoldScreen();
        holdTiles[3][1] = '#';
        holdTiles[3][2] = '#';
        holdTiles[3][3] = '#';
        holdTiles[3][4] = '#';
        break;
    case 2:
        ClearHoldScreen();
        holdTiles[2][4] = '#';
        holdTiles[2][3] = '#';
        holdTiles[3][3] = '#';
        holdTiles[3][2] = '#';
        break;
    case 3:
        ClearHoldScreen();
        holdTiles[2][1] = '#';
        holdTiles[2][2] = '#';
        holdTiles[3][2] = '#';
        holdTiles[3][3] = '#';
        break;
    case 4:
        ClearHoldScreen();
        holdTiles[2][2] = '#';
        holdTiles[3][2] = '#';
        holdTiles[4][2] = '#';
        holdTiles[4][3] = '#';
        break;
    case 5:
        ClearHoldScreen();
        holdTiles[2][3] = '#';
        holdTiles[3][3] = '#';
        holdTiles[4][3] = '#';
        holdTiles[4][2] = '#';
        break;
    case 6:
        ClearHoldScreen();
        holdTiles[2][2] = '#';
        holdTiles[3][2] = '#';
        holdTiles[4][2] = '#';
        holdTiles[3][3] = '#';
        break;
    default:
        ClearHoldScreen();
        break;
    }
}

void Screen::ClearNextScreen() {
    for (int i = 1; i < 6; i++) {
        for (int j = 0; j < 6; j++) {//Clear the box but keep "NEXT" at the top
            nextTiles[i][j] = ' ';
        }
    }
}

void Screen::NextBlock(int blockToNext) {
    switch (blockToNext) {
    case 0:
        ClearNextScreen();
        nextTiles[2][3] = '#';
        nextTiles[3][2] = '#';
        nextTiles[2][2] = '#';
        nextTiles[3][3] = '#';
        break;
    case 1:
        ClearNextScreen();
        nextTiles[3][1] = '#';
        nextTiles[3][2] = '#';
        nextTiles[3][3] = '#';
        nextTiles[3][4] = '#';
        break;
    case 2:
        ClearNextScreen();
        nextTiles[2][4] = '#';
        nextTiles[2][3] = '#';
        nextTiles[3][3] = '#';
        nextTiles[3][2] = '#';
        break;
    case 3:
        ClearNextScreen();
        nextTiles[2][1] = '#';
        nextTiles[2][2] = '#';
        nextTiles[3][2] = '#';
        nextTiles[3][3] = '#';
        break;
    case 4:
        ClearNextScreen();
        nextTiles[2][2] = '#';
        nextTiles[3][2] = '#';
        nextTiles[4][2] = '#';
        nextTiles[4][3] = '#';
        break;
    case 5:
        ClearNextScreen();
        nextTiles[2][3] = '#';
        nextTiles[3][3] = '#';
        nextTiles[4][3] = '#';
        nextTiles[4][2] = '#';
        break;
    case 6:
        ClearNextScreen();
        nextTiles[2][2] = '#';
        nextTiles[3][2] = '#';
        nextTiles[4][2] = '#';
        nextTiles[3][3] = '#';
        break;
    default:
        ClearNextScreen();
        break;
    }
}

void Screen::DrawLine(int width) {
    std::cout << std::setw(spacing + 1); //start above the first "|"
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < (spacing * 2); j++)
            std::cout << "-"; //print out a line the same width as the grid
    }
    std::cout << "-"; //makes the line neater with an extra dash added to the line
}

void Screen::DrawNextScreen(int line) {
    NextBlock(nextBlock);
    if (line < 6) {//Height of box
        for (int i = 0; i < 6; i++) {
            std::cout << "|" << std::setw(spacing) << nextTiles[line][i] << std::setw(spacing);
        }
        std::cout << "|";
    }
}

void Screen::DrawHoldScreen(int line) {
    HoldBlock(heldBlock);
    if (line > 6 && line < 13) {//Height of box
        for (int i = 0; i < 6; i++) {
            std::cout << "|" << std::setw(spacing) << holdTiles[line - 7][i] << std::setw(spacing);
        }
        std::cout << "|";
    }
}

void Screen::DrawMainScreen(int line) {
    std::cout << std::setw(spacing + 1); //move grid further away from left side

    for (int i = 0; i < screenWidth; i++) {
        std::cout << "|" << std::setw(spacing) << tiles[i][line] << std::setw(spacing);
    }

    std::cout << "|";
}

void Screen::DrawScreen() {
    std::cout << "\n";
    DrawLine(screenWidth);
    DrawLine(6);
    std::cout << "\n";

    for (int i = 0; i < screenHeight; i++) {
        DrawMainScreen(i);
        std::cout << std::setw(spacing + 1);
        DrawNextScreen(i);
        std::cout << std::setw(spacing + 1);
        DrawHoldScreen(i);
        std::cout << "\n";
        DrawLine(screenWidth);
        if (i < 6) {
            DrawLine(6);
        }
        else if (i == 6) {
            DrawLine(6);
        }
        else if (i > 6 && i < 13) {
            DrawLine(6);
        }
        std::cout << "\n";
    }
}