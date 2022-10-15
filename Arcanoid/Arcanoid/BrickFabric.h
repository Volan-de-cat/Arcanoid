#pragma once

#include"Framework.h"
#include "Const.h"

#include<array>


class Brick;

class BrickFabric
{
public:
    BrickFabric();

    void Init();

    Brick CreateBrick(int x, int y);

private:
    std::array<Sprite*, 5> bricksType;
};

