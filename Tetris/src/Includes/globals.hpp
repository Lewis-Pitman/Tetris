#ifndef GLOBALS_HPP  
#define GLOBALS_HPP  

extern char (*pTiles)[20];  

extern int originX;  
extern int originY;  
extern bool bottomOfScreen;  

class BlockData;  
extern BlockData currentBlockData;  
extern BlockData* pCurrentBlockData;  

extern char placedBlocks[10][20];


extern bool gameActive;  
extern int framerate;  

extern int nextBlock;  
extern int heldBlock;  

#endif