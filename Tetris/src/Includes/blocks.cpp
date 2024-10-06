#include "blocks.hpp"
#include "globals.hpp"

BlockData currentBlockData;
BlockData* pCurrentBlockData = &currentBlockData; //depending on the framerate, we'd need to copy this large variable multiple times a second to draw it to the screen. Using a pointer we don't need to, we only tell it where it is in memory.

bool validMove = true;
bool tileIsPartOfBlock = false;
bool bottomOfScreen = false;

Block::Block(int typeOfBlock) {
    type = typeOfBlock;
    originX = 5;
    originY = 2;
    rotation = 0;

    BlockData data;
    currentBlockData = data; //Create the blockData values from the BlockData class and move them into the global variable currentData to be modified later.
}

void Block::Move(int direction) {
    bool validMove;
    int i;

    if (direction == 1) {//left
        validMove = true;
        for (i = 0; i < 4; i++) {
            if (pCurrentBlockData->blockData[type][rotation][0][i] == 0) {//left border
                validMove = false;
            }
            else {
                if (placedBlocks[pCurrentBlockData->blockData[type][rotation][0][i] - 1][pCurrentBlockData->blockData[type][rotation][1][i]] == '#') {
                     validMove = false;
                }
            }
        }
        if (validMove) {
            originX--;
        }
    }
    else {//right
        validMove = true;
        for (i = 0; i < 4; i++) {
            if (pCurrentBlockData->blockData[type][rotation][0][i] == 9) {//right border
                validMove = false;
            }
            else {
                if (placedBlocks[pCurrentBlockData->blockData[type][rotation][0][i] + 1][pCurrentBlockData->blockData[type][rotation][1][i]] == '#') {
                    validMove = false;
                }
            }
        }

        if (validMove) {
            originX++;
        }
    }

    BlockData data;
    currentBlockData = data;
}

void Block::Down() {
    validMove = true;
    tileIsPartOfBlock = false;
    bottomOfScreen = false;

    for (int i = 0; i < 4; i++) {
        if (pCurrentBlockData->blockData[type][rotation][1][i] == 19) {//Bottom border
            validMove = false;
            bottomOfScreen = true;
        } //If on last row, skip other checks
    }

    if (validMove) {
        for (int i = 0; i < 4; i++) {
            moveDownCheckValuesX[i] = pCurrentBlockData->blockData[type][rotation][0][i]; //A list of X values in the current block
            moveDownCheckValuesY[i] = pCurrentBlockData->blockData[type][rotation][1][i]; //A list of Y values in the current block
        }

        for (int i = 0; i < 4; i++) {
            if (pTiles[pCurrentBlockData->blockData[type][rotation][0][i]][(pCurrentBlockData->blockData[type][rotation][1][i]) + 1] == '#') { //Check each tile in the block to see if there is a # below it
                tileIsPartOfBlock = false;

                for (int j = 0; j < 4; j++) { //Check if the # is part of itself
                    if (pCurrentBlockData->blockData[type][rotation][0][i] == moveDownCheckValuesX[j] && (pCurrentBlockData->blockData[type][rotation][1][i]) + 1 == moveDownCheckValuesY[j]) {
                        tileIsPartOfBlock = true;
                    }
                }

                if (!tileIsPartOfBlock) {
                    validMove = false;
                    bottomOfScreen = true;
                }
            }
        }
    }

    if (validMove) {
        originY++;
        BlockData data;
        currentBlockData = data;
    }
}

void Block::ValidateRotation(int desiredRotation) {
    //This function checks whether a rotation will result in the block rotating out of bounds. If it does, we move the block to the side to allow room for the rotation.

    bool currentlyValid = true;

    for (int i = 0; i < 4; i++) {
        if (pCurrentBlockData->blockData[type][desiredRotation][0][i] < 0 || pCurrentBlockData->blockData[type][desiredRotation][0][i] > 9) {
            currentlyValid = false;
        }
        else if (placedBlocks[pCurrentBlockData->blockData[type][desiredRotation][0][i]][pCurrentBlockData->blockData[type][desiredRotation][1][i]] == '#') {
            currentlyValid = false;
        }
    }

    if (currentlyValid) {
        rotation = desiredRotation;
    }

}

void Block::Rotate(int direction) {
    if (direction == 1) { //left
        if (rotation-- <= 0) {
            ValidateRotation(3);
        }
        else {
            ValidateRotation(rotation--);
        }
    }
    else { //right
        if (rotation++ >= 3) {
            ValidateRotation(0);
        }
        else {
           ValidateRotation(rotation++);
        }
    }
}