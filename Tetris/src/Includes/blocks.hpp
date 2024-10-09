#ifndef BLOCKS_HPP
#define BLOCKS_HPP

extern int originX;
extern int originY;
extern bool bottomOfScreen;
class BlockData;
extern BlockData currentBlockData;
extern BlockData* pCurrentBlockData;

class Block {
private:
    int moveDownCheckValuesX[4];
    int moveDownCheckValuesY[4];

public:
    int rotation{ 0 };
    int type;

    Block(int typeOfBlock);
    void Move(int direction);
    void Down();
    void ValidateRotation(int desiredRotation);
    void Rotate(int direction);
};

class BlockData {
public:
    int blockData[7][4][2][4] = {

        //blockData[BlockType][Rotation][X and Y values][values]
        //Each block takes up 4 tiles on the grid, hence 4 values for both x and y.
        //The first X and Y value are the origin of the block. When moving the block, we'll move the origin point and the rest of the tiles will follow.

        {//BlockType: O
            {//Rotation: 0
                //X Values:
                {originX, originX, originX + 1, originX + 1},
                //Y Values:
                {originY, originY + 1, originY, originY + 1}
            },
            {//Rotation: 90
                {originX, originX, originX + 1, originX + 1},
                {originY, originY + 1, originY, originY + 1}
            },
            {//Rotation: 180
                {originX, originX, originX + 1, originX + 1},
                {originY, originY + 1, originY, originY + 1}
            },
            {//Rotation: 270
                {originX, originX, originX + 1, originX + 1},
                {originY, originY + 1, originY, originY + 1} //Rotation on the O BlockType is the same, theres no visible change when rotating it.
            },
        },

        {//BlockType: I
            {//Rotation: 0
                {originX, originX - 1, originX + 1, originX + 2},
                {originY, originY, originY, originY}
            },
            {//Rotation: 90
                {originX, originX, originX, originX},
                {originY, originY - 1, originY + 1, originY + 2}
            },
            {//Rotation: 180
                {originX, originX - 1, originX + 1, originX + 2},
                {originY, originY, originY, originY}
            },
            {//Rotation: 270
                {originX, originX, originX, originX},
                {originY, originY - 1, originY + 1, originY + 2}
            },
        },

        {//BlockType: S
            {//Rotation: 0
                {originX, originX - 1, originX, originX + 1},
                {originY, originY, originY - 1, originY - 1}
            },
            {//Rotation: 90
                {originX, originX, originX + 1, originX + 1},
                {originY, originY - 1, originY, originY + 1}
            },
            {//Rotation: 180
                {originX, originX + 1, originX, originX - 1},
                {originY, originY, originY + 1, originY + 1}
            },
            {//Rotation: 270
                {originX, originX, originX - 1, originX - 1},
                {originY, originY + 1, originY, originY - 1}
            },
        },

        {//BlockType: Z
            {//Rotation: 0
                {originX, originX + 1, originX, originX - 1},
                {originY, originY, originY - 1, originY - 1}
            },
            {//Rotation: 90
                {originX, originX, originX + 1, originX + 1},
                {originY, originY + 1, originY, originY - 1}
            },
            {//Rotation: 180
                {originX, originX - 1, originX, originX + 1},
                {originY, originY, originY + 1, originY + 1}
            },
            {//Rotation: 270
                {originX, originX, originX - 1, originX - 1},
                {originY, originY - 1, originY, originY + 1}
            },
        },

        {//BlockType: L
            {//Rotation: 0
                {originX, originX - 1, originX + 1, originX + 1},
                {originY, originY, originY, originY - 1}
            },
            {//Rotation: 90
                {originX, originX, originX, originX + 1},
                {originY, originY - 1, originY + 1, originY + 1}
            },
            {//Rotation: 180
                {originX, originX + 1, originX - 1, originX - 1},
                {originY, originY, originY, originY + 1}
            },
            {//Rotation: 270
                {originX, originX, originX, originX - 1},
                {originY, originY + 1, originY - 1, originY - 1}
            },
        },

        {//BlockType: J
            {//Rotation: 0
                {originX, originX + 1, originX - 1, originX - 1},
                {originY, originY, originY, originY - 1}
            },
            {//Rotation: 90
                {originX, originX, originX, originX + 1},
                {originY, originY + 1, originY - 1, originY - 1}
            },
            {//Rotation: 180
                {originX, originX - 1, originX + 1, originX + 1},
                {originY, originY, originY, originY + 1}
            },
            {//Rotation: 270
                {originX, originX, originX, originX - 1},
                {originY, originY - 1, originY + 1, originY + 1}
            },
        },

        {//BlockType: T
            {//Rotation: 0
                {originX, originX - 1, originX, originX + 1},
                {originY, originY, originY - 1, originY}
            },
            {//Rotation: 90
                {originX, originX, originX + 1, originX},
                {originY, originY - 1, originY, originY + 1}
            },
            {//Rotation: 180
                {originX, originX + 1, originX, originX - 1},
                {originY, originY, originY + 1, originY}
            },
            {//Rotation: 270
                {originX, originX, originX - 1, originX},
                {originY, originY + 1, originY, originY - 1}
            },
        }

    };
};

#endif