#include "BonuseFabric.h"
#include "Bonuse.h"

BonuseFabric::BonuseFabric()
{
}

void BonuseFabric::Init()
{
    for (int it = 0; it < bonuseType.size(); it++)
    {
        bonuseType[it] = createSprite(bonusePath[it].c_str());
        setSpriteSize(bonuseType[it], bonusesizex, bonusesizey);
    }
}

Bonuse BonuseFabric::CreateBonuse(int x, int y)
{
    int ran = 0;

    ran = rand() % 3;

    return Bonuse(x, y, bonuseType[ran], ran);
}
