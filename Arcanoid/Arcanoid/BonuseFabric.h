#pragma once

#include"Framework.h"
#include "Const.h"

#include<array>

class Bonuse;

class BonuseFabric
{
public:
    BonuseFabric();

    void Init();

    Bonuse CreateBonuse(int x, int y);

private:
    std::array<Sprite*, 4> bonuseType;
};

