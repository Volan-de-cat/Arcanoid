#include "BrickFabric.h"
#include "Brick.h"

#include <cstdlib>
#include <time.h>

BrickFabric::BrickFabric() 
{
}

void BrickFabric::Init()
{
    for (int it = 0; it < bricksType.size(); it++)
    {
        bricksType[it] = createSprite(brickPath[it].c_str());
        setSpriteSize(bricksType[it], bricksizex, bricksizey);
    }
}



Brick BrickFabric::CreateBrick(int x, int y) 
{
    int ran = 0;

    ran = rand() % 5;

    return Brick(x, y, bricksType[ran]);
}
