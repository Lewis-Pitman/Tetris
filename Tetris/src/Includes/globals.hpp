#ifndef GLOBALS_HPP  
#define GLOBALS_HPP  

//Screen
extern char (*pTiles)[20];  
extern char placedBlocks[10][20];

//Block
extern int originX;  
extern int originY;  
extern bool bottomOfScreen; 
class BlockData;  
extern BlockData currentBlockData;  
extern BlockData* pCurrentBlockData;  

//Game
extern bool gameActive;  
extern int framerate;  
extern int speed;
extern int linesCleared;
extern int nextBlock;  
extern int heldBlock; 
extern int score;

#endif